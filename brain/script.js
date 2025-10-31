
const hotspots = document.querySelectorAll('.hotspot');
const tooltip = document.getElementById('tooltip');
const buttons = document.querySelectorAll('.detail-button');
const allDetailSections = document.querySelectorAll('.detail-section');

// --- 1. Tooltip Follows Mouse ---
document.addEventListener('mousemove', (e) => {

    tooltip.style.left = e.pageX + 15 + 'px';
    tooltip.style.top = e.pageY + 15 + 'px';
});

// --- 2. Hotspot Hover Events ---
hotspots.forEach(hotspot => {
    hotspot.addEventListener('mouseenter', () => {
        const info = hotspot.getAttribute('data-info');
        
        tooltip.innerHTML = info;
        tooltip.style.display = 'block';
        
        const targetId = hotspot.getAttribute('href');
        const targetButton = document.querySelector(`.detail-button[href="${targetId}"]`);
        
        if (targetButton) {
            buttons.forEach(btn => btn.classList.remove('active'));
            targetButton.classList.add('highlight');
        }
    });

    hotspot.addEventListener('mouseleave', () => {
        tooltip.style.display = 'none';
        
  
        const targetId = hotspot.getAttribute('href');
        const targetButton = document.querySelector(`.detail-button[href="${targetId}"]`);
        
        if (targetButton) {
            targetButton.classList.remove('highlight');
        }
        
 
        const activeSection = document.querySelector('.detail-section.active');
        if (activeSection) {
            const activeSectionId = activeSection.getAttribute('id');
            // Find the button that matches the active section
            const activeButton = document.querySelector(`.detail-button[href="#${activeSectionId}"]`);
            if (activeButton) {
                activeButton.classList.add('active');
            }
        }
    });
});

// --- 3. NEW: Click Handler Function ---
function showDetailSection(targetId) {
    allDetailSections.forEach(section => {
        section.classList.remove('active');
    });
    
    buttons.forEach(btn => {
        btn.classList.remove('active');
    });

    const targetElement = document.querySelector(targetId);
    if (targetElement) {
        targetElement.classList.add('active');
        
        targetElement.scrollIntoView({
            behavior: 'smooth',
            block: 'start' 
        });
    }
    

    const targetButton = document.querySelector(`.detail-button[href="${targetId}"]`);
    if (targetButton) {
        targetButton.classList.add('active');
    }
}

// --- 4. NEW: Attach Click Event to Hotspots ---
hotspots.forEach(hotspot => {
    hotspot.addEventListener('click', (e) => {
        e.preventDefault(); 
        
        const targetId = hotspot.getAttribute('href');
        showDetailSection(targetId);
    });
});

buttons.forEach(button => {
    button.addEventListener('click', (e) => {
       
        e.preventDefault();
        
        const targetId = button.getAttribute('href');
        showDetailSection(targetId);
    });
});

