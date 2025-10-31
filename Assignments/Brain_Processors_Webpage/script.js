const regions = document.querySelectorAll('.region');
const tooltip = document.getElementById('tooltip');
const infoPanel = document.getElementById('info-panel');
const partTitle = document.getElementById('part-title');
const partDescription = document.getElementById('part-description');
let activeRegion = null;


regions.forEach(region => {
region.addEventListener('mousemove', (e) => {
const name = region.dataset.name;
const info = region.dataset.info;
tooltip.innerHTML = `<strong>${name}</strong><br>${info}`;
tooltip.style.left = `${e.pageX}px`;
tooltip.style.top = `${e.pageY - 20}px`;
tooltip.classList.add('visible');
});


region.addEventListener('mouseleave', () => {
tooltip.classList.remove('visible');
});


region.addEventListener('click', () => {
if (activeRegion) activeRegion.classList.remove('active');
activeRegion = region;
region.classList.add('active');


partTitle.textContent = region.dataset.name;
partDescription.textContent = region.dataset.info;
});
});


document.addEventListener('keydown', (e) => {
if (e.key === 'Escape' && activeRegion) {
activeRegion.classList.remove('active');
activeRegion = null;
partTitle.textContent = 'Hover over a brain region';
partDescription.textContent = 'Details about each processor will appear here when you hover or click on the brain parts.';
}
});
