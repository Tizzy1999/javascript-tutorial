const ps = document.querySelectorAll('p');

ps.forEach(p => {
  if(p.textContent.includes('error')){
    p.classList.add('error')
  }else if(p.textContent.includes('success')){
    p.classList.add('success');
  }
});
console.log(ps);
ps.forEach(p => {
  if(p.textContent.includes('error')){
    p.classList.toggle('error')
  }else if(p.textContent.includes('success')){
    p.classList.toggle('success');
  }
});
console.log(ps);
