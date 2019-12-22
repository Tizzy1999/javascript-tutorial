## Event Basics
- attach event to item
- if we have a collection of items, we can cycle through them, and add an event listener to each individual item.
- [Event Cheasheet](https://developer.mozilla.org/en-US/docs/Web/Events)

```javaScript
const items = document.querySelectorAll('li');

p.addEventListener('click', (e)=> {
  console.log(e.target);
  # change the style of the clicked element
  e.target.style.textDecoration = 'line-through';
});

```

## Creating & Removing Elements

- Removing element

```javaScript
const items = document.querySelectorAll('li');

p.addEventListener('click', (e)=> {
  console.log(e.target);
  e.target.remove();
});
```

- Creating element

```javaScript
const items = document.querySelectorAll('li');
const ul = document.querySelector('ul');
const button = document.querySelector('button');

button.addEventListener('click', ()=>{
  const li = document.createElement('li');
  li.textContent = 'Something New';
  ul.prepend(li);
});

items.forEach(item=> {
  item.addEventListener('click', (e)=>{
    e.target.remove();
  });
});
```

## Event Bubbling (and delegation)
- refers to how event bubbles up from child to parent
- we can make use of event bubbling and attach event listener to parent instead of every single child
- by doing this, we can also keep track of the new child added to the parent element

```javaScript
// const items = document.querySelectorAll('li');
const ul = document.querySelector('ul');
const button = document.querySelector('button');

button.addEventListener('click', ()=>{
  const li = document.createElement('li');
  li.textContent = 'Something New';
  ul.prepend(li);
});

ul.addEventListener('click', (e)=>{
  if(e.target.tagName == 'LI'){
    e.target.remove();
  }
})
