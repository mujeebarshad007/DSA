let currentLanguage = 'english';
let currentMode = 'standard';
let userPin = '';
let accountBalance = 50000;
let withdrawAmount = 0;
let depositAmount = 0;
let transactionType = '';
let currentScreenId = 'welcomeScreen'; 

let textToSpeechEnabled = false; 
let synth = window.speechSynthesis;
let recognition;

if ('SpeechRecognition' in window || 'webkitSpeechRecognition' in window) {
    const SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;
    recognition = new SpeechRecognition();
    recognition.continuous = false; 
    recognition.lang = 'en-US';
    recognition.interimResults = false;

    recognition.onstart = function() {
        document.getElementById('voiceIndicator').style.display = 'flex';
    };

    recognition.onend = function() {
        document.getElementById('voiceIndicator').style.display = 'none';
    };

    recognition.onresult = function(event) {
        const transcript = event.results[0][0].transcript.toLowerCase();
        console.log("Heard:", transcript);
        handleVoiceCommand(transcript);
    };
}

const translations = {
    english: {
        modeTitle: 'Select Mode', standardText: 'Standard Mode', kidsText: 'Kids Mode', specialText: 'Special Mode (Accessible)',
        pinTitle: 'Enter Your 4-Digit PIN', orUseText: 'Or Use', fingerprintText: 'Fingerprint Access',
        mainMenuTitle: 'Main Menu', withdrawText: 'Withdraw', depositText: 'Deposit', transferText: 'Transfer',
        balanceText: 'Balance Check', otherText: 'Other Services', exitText: 'Exit',
        withdrawAmountTitle: 'Select Amount', otherAmountText: 'Other Amount', customAmountTitle: 'Enter Amount',
        insufficientMessage: 'You do not have sufficient balance. Do you want to make another transaction?',
        confirmTitle: 'Confirm Transaction', confirmQuestion: 'Do you want to proceed?',
        receiptTitle: 'Receipt', receiptQuestion: 'Do you want a receipt?', takeCashMessage: 'Please take your cash',
        balanceCheckTitle: 'Your Balance', depositTitle: 'Enter Deposit Amount', depositSuccessMessage: 'Deposit successful. Thank you!',
        exitTitle: 'Thank You!', thankYouMessage: "Thank you for using NIKO's ATM"
    },
    urdu: {
        modeTitle: 'موڈ منتخب کریں', standardText: 'معیاری موڈ', kidsText: 'بچوں کا موڈ', specialText: 'خصوصی موڈ',
        pinTitle: 'اپنا 4 ہندسوں کا PIN درج کریں', orUseText: 'یا استعمال کریں', fingerprintText: 'فنگر پرنٹ',
        mainMenuTitle: 'مین مینو', withdrawText: 'رقم نکالیں', depositText: 'رقم جمع کریں', transferText: 'منتقلی',
        balanceText: 'بیلنس چیک', otherText: 'دیگر خدمات', exitText: 'باہر نکلیں',
        withdrawAmountTitle: 'رقم منتخب کریں', otherAmountText: 'دوسری رقم', customAmountTitle: 'رقم درج کریں',
        insufficientMessage: 'آپ کے پاس کافی بیلنس نہیں ہے۔', confirmTitle: 'تصدیق کریں', confirmQuestion: 'کیا آپ آگے بڑھنا چاہتے ہیں؟',
        receiptTitle: 'رسید', receiptQuestion: 'کیا آپ رسید چاہتے ہیں؟', takeCashMessage: 'براہ کرم اپنی رقم لیں',
        balanceCheckTitle: 'آپ کا بیلنس', depositTitle: 'رقم درج کریں', depositSuccessMessage: 'رقم جمع ہو گئی۔ شکریہ!',
        exitTitle: 'شکریہ!', thankYouMessage: 'NIKO کے ATM استعمال کرنے کا شکریہ'
    }
};

function goToScreen(screenId) {
    currentScreenId = screenId; 
    const screens = document.querySelectorAll('.screen');
    screens.forEach(screen => screen.classList.remove('active'));
    document.getElementById(screenId).classList.add('active');
    
    if (textToSpeechEnabled) {
        setTimeout(() => { announceScreen(screenId); }, 300);
    }
}

function selectLanguage(language) {
    currentLanguage = language;
    if(recognition) {
        recognition.lang = (language === 'urdu') ? 'ur-PK' : 'en-US';
    }
    updateLanguage();
    goToScreen('modeScreen');
}

function updateLanguage() {
    const lang = translations[currentLanguage];
    const elements = {
        modeTitle: 'modeTitle', standardText: 'standardText', kidsText: 'kidsText', specialText: 'specialText',
        pinTitle: 'pinTitle', orUseText: 'orUseText', fingerprintText: 'fingerprintText',
        mainMenuTitle: 'mainMenuTitle', withdrawText: 'withdrawText', depositText: 'depositText',
        transferText: 'transferText', balanceText: 'balanceText', otherText: 'otherText', exitText: 'exitText',
        withdrawAmountTitle: 'withdrawAmountTitle', otherAmountText: 'otherAmountText', customAmountTitle: 'customAmountTitle',
        insufficientMessage: 'insufficientMessage', confirmTitle: 'confirmTitle', confirmQuestion: 'confirmQuestion',
        receiptTitle: 'receiptTitle', receiptQuestion: 'receiptQuestion', takeCashMessage: 'takeCashMessage',
        balanceCheckTitle: 'balanceCheckTitle', depositTitle: 'depositTitle', depositSuccessMessage: 'depositSuccessMessage',
        exitTitle: 'exitTitle', thankYouMessage: 'thankYouMessage'
    };
    for (const [key, elementId] of Object.entries(elements)) {
        const element = document.getElementById(elementId);
        if (element && lang[key]) element.textContent = lang[key];
    }
}

function selectMode(mode) {
    currentMode = mode;
    const machine = document.getElementById('atmMachine');
    machine.classList.remove('kids-mode', 'special-mode');
    document.getElementById('transferBtn').classList.remove('hidden');
    document.getElementById('otherServicesBtn').classList.remove('hidden');
    
    textToSpeechEnabled = false; 
    stopSpeech();

    if (mode === 'kids') {
        machine.classList.add('kids-mode');
        document.getElementById('transferBtn').classList.add('hidden');
        document.getElementById('otherServicesBtn').classList.add('hidden');
    } else if (mode === 'special') {
        machine.classList.add('special-mode');
        textToSpeechEnabled = true; 
        speak('Special accessible mode activated. I will read the screen for you.');
    }
    goToScreen('pinScreen');
}

function resetToModeScreen() {
    const machine = document.getElementById('atmMachine');
    machine.classList.remove('kids-mode', 'special-mode');
    textToSpeechEnabled = false;
    stopSpeech();
    goToScreen('modeScreen');
}

function addPinDigit(digit) {
    if (userPin.length < 4) {
        userPin += digit;
        updatePinDisplay();
        if(textToSpeechEnabled) speak(digit);
    }
}
function clearPin() { userPin = ''; updatePinDisplay(); if(textToSpeechEnabled) speak("Cleared"); }
function updatePinDisplay() {
    const display = document.getElementById('pinDisplay');
    if (userPin.length === 0) display.textContent = '****';
    else display.textContent = '•'.repeat(userPin.length) + '*'.repeat(4 - userPin.length);
}
function submitPin() {
    if (userPin.length === 4) {
        if(textToSpeechEnabled) speak("PIN Accepted");
        goToScreen('mainMenuScreen');
        userPin = ''; updatePinDisplay();
    } else {
        if(textToSpeechEnabled) speak("Please enter 4 digits");
        alert('Please enter a 4-digit PIN');
    }
}
function fingerprintAuth() {
    if(textToSpeechEnabled) speak("Fingerprint scanned");
    goToScreen('mainMenuScreen');
}

function checkBalance() {
    document.getElementById('balanceAmount').textContent = 'Rs. ' + accountBalance.toLocaleString();
    goToScreen('balanceScreen');
}
function selectWithdrawAmount(amount) {
    withdrawAmount = amount;
    if (currentMode === 'kids' && amount > 5000) {
        const msg = 'Kid limit is 5000';
        if(textToSpeechEnabled) speak(msg);
        alert(msg); return;
    }
    checkFundsAndProceed(amount);
}
function confirmCustomAmount() {
    const input = document.getElementById('customAmountInput');
    const amount = parseInt(input.value);
    if (!amount || amount <= 0) { alert('Invalid amount'); return; }
    if (currentMode === 'kids' && amount > 5000) { alert('Kid limit is 5000'); return; }
    withdrawAmount = amount; input.value = '';
    checkFundsAndProceed(amount);
}
function checkFundsAndProceed(amount) {
    if (amount > accountBalance) goToScreen('insufficientScreen');
    else {
        transactionType = 'withdraw';
        document.getElementById('confirmAmount').textContent = 'Rs. ' + amount.toLocaleString();
        goToScreen('confirmScreen');
    }
}
function proceedTransaction() {
    if (transactionType === 'withdraw') { accountBalance -= withdrawAmount; goToScreen('receiptScreen'); }
    else if (transactionType === 'deposit') { accountBalance += depositAmount; goToScreen('depositSuccessScreen'); }
}
function cancelTransaction() {
    if (transactionType === 'withdraw') goToScreen('withdrawScreen');
    else if (transactionType === 'deposit') goToScreen('depositScreen');
}

function confirmDeposit() {
    const input = document.getElementById('depositAmountInput');
    const amount = parseInt(input.value);
    if (!amount || amount <= 0) { alert('Enter valid amount'); return; }
    depositAmount = amount; input.value = ''; transactionType = 'deposit';
    document.getElementById('depositConfirmAmount').textContent = 'Rs. ' + amount.toLocaleString();
    goToScreen('depositConfirmScreen');
}
function processDeposit() { accountBalance += depositAmount; goToScreen('depositSuccessScreen'); }
function printDepositReceipt() { setupReceipt('DEPOSIT', depositAmount); goToScreen('receiptDisplayScreen'); }
function printReceipt() { setupReceipt('WITHDRAWAL', withdrawAmount); goToScreen('receiptDisplayScreen'); }
function setupReceipt(type, amount) {
    const now = new Date();
    document.getElementById('receiptDate').textContent = now.toLocaleDateString() + ' ' + now.toLocaleTimeString();
    document.getElementById('receiptType').textContent = type;
    document.getElementById('receiptAmount').textContent = 'Rs. ' + amount.toLocaleString();
    document.getElementById('receiptBalance').textContent = 'Rs. ' + accountBalance.toLocaleString();
}
function completeWithdraw() { goToScreen('takeCashScreen'); setTimeout(() => { withdrawAmount = 0; }, 1000); }
function exitATM() { goToScreen('exitScreen'); }

function resetATM() { 
    currentLanguage = 'english'; 
    document.getElementById('atmMachine').classList.remove('kids-mode', 'special-mode');
    selectMode('standard'); 
    goToScreen('welcomeScreen'); 
}

function speak(text) {
    if (!textToSpeechEnabled) return;
    if (synth.speaking) synth.cancel();
    const utterance = new SpeechSynthesisUtterance(text);
    utterance.lang = currentLanguage === 'urdu' ? 'ur-PK' : 'en-US';
    utterance.rate = 0.9;
    synth.speak(utterance);
}
function stopSpeech() { if (synth.speaking) synth.cancel(); }

function announceScreen(screenId) {
    if (!textToSpeechEnabled) return;
    let text = '';
    switch(screenId) {
        case 'welcomeScreen': text = 'Welcome. Select Language.'; break;
        case 'modeScreen': text = 'Select Mode.'; break;
        case 'pinScreen': text = 'Enter 4 digit PIN. Say numbers to type.'; break;
        case 'mainMenuScreen': text = 'Main Menu. Options are Withdraw, Deposit, Balance, Transfer, Exit.'; break;
        case 'withdrawScreen': text = 'Select amount. Say 1000, 2000, 3000, or 5000.'; break;
        case 'confirmScreen': text = 'Confirm Transaction? Say Yes or No.'; break;
        case 'receiptScreen': text = 'Do you want a receipt? Say Yes or No.'; break;
        case 'takeCashScreen': text = 'Please take your cash.'; break;
        case 'balanceScreen': text = 'Your balance is ' + accountBalance + '. Say Main Menu to go back.'; break;
        default: text = 'Screen updated';
    }
    speak(text);
}

document.body.onkeyup = function(e){
    if(e.keyCode == 32){ startListening(); }
}

function startListening() {
    if (recognition) { stopSpeech(); recognition.start(); }
}

function handleVoiceCommand(cmd) {
    if (cmd.includes('exit')) { exitATM(); return; }
    if (cmd.includes('back')) { 
         if(currentScreenId === 'withdrawScreen') goToScreen('mainMenuScreen');
         else if(currentScreenId === 'pinScreen') resetToModeScreen();
         else if(currentScreenId === 'mainMenuScreen') exitATM();
         else if(currentScreenId === 'balanceScreen') goToScreen('mainMenuScreen');
         else goToScreen('mainMenuScreen');
         return;
    }

    if (currentScreenId === 'modeScreen') {
        if (cmd.includes('standard') || cmd.includes('normal')) selectMode('standard');
        else if (cmd.includes('kids') || cmd.includes('child')) selectMode('kids');
        else if (cmd.includes('special') || cmd.includes('blind') || cmd.includes('voice')) selectMode('special');
    }
    else if (currentScreenId === 'pinScreen') {
        const nums = {'one':1,'two':2,'three':3,'four':4,'five':5,'six':6,'seven':7,'eight':8,'nine':9,'zero':0};
        for (let word in nums) { if(cmd.includes(word)) addPinDigit(nums[word].toString()); }
        if (cmd.match(/\d/)) { addPinDigit(cmd.match(/\d/)[0]); }
        if (cmd.includes('clear')) clearPin();
        if (cmd.includes('enter') || cmd.includes('ok')) submitPin();
    }
    else if (currentScreenId === 'mainMenuScreen') {
        if (cmd.includes('withdraw')) goToScreen('withdrawScreen');
        else if (cmd.includes('deposit')) goToScreen('depositScreen');
        else if (cmd.includes('balance')) checkBalance();
    }
    else if (currentScreenId === 'withdrawScreen') {
        if (cmd.includes('1000')) selectWithdrawAmount(1000);
        else if (cmd.includes('2000')) selectWithdrawAmount(2000);
        else if (cmd.includes('3000')) selectWithdrawAmount(3000);
        else if (cmd.includes('5000')) selectWithdrawAmount(5000);
    }
    else if (['confirmScreen', 'receiptScreen', 'insufficientScreen'].includes(currentScreenId)) {
        if (cmd.includes('yes') || cmd.includes('sure')) {
            if(currentScreenId === 'confirmScreen') proceedTransaction();
            else if(currentScreenId === 'receiptScreen') printReceipt();
        } else if (cmd.includes('no')) {
            if(currentScreenId === 'confirmScreen') cancelTransaction();
            else if(currentScreenId === 'receiptScreen') completeWithdraw();
        }
    }
}

document.addEventListener('mouseover', function(e) {
    if (textToSpeechEnabled && (e.target.classList.contains('btn') || e.target.classList.contains('keypad-btn'))) {
        speak(e.target.innerText);
    }
});