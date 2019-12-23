## Submit Events
- the default action after submit is refresh the page

```javaScript

const form = document.querySelector('.signup-form');
const username = document.querySelector('#username');
form.addEventListener('submit', e => {
  // prevent default action of refreshing the page
  e.preventDefault();
  console.log(username.value);
  // access the field directly using dot notation
  console.log(form.username.value);
});

```


## Regular Expressions
- test for regular expression

```javaScript
const name = 'tizzyy';
const pattern = /[a-z]{6,}/;

let result = pattern.test(name);
console.log(result);
```

```javaScript
const name = 'tizzyy@qq.com';
const pattern = /^[a-z]{6,}$/;

let result = pattern.test(name);
console.log(result);
```

## Basic Form Validation

```javaScript
const form = document.querySelector('.signup-form');

form.addEventListener('submit', e => {
   e.preventDefault();
   var name = form.username.value;
   const pattern = /^[a-z]{6,}$/;

   let result = pattern.test(name);
   if(result){
     console.log('test passed');
   }else{
     console.log('test failed');
   }
});
```

```javaScript
// -1 means not getting a match
// otherwise, position of the match
const form = document.querySelector('.signup-form');
form.addEventListener('submit', e => {
   e.preventDefault();
   var name = form.username.value;
   const pattern = /^[a-z,A-Z]{6,}$/;
   console.log(name);
   // -1 means not getting a match
   // otherwise, position of the match
   let result = name.search(pattern);
   console.log(result);
});

```

```javaScript
const form = document.querySelector('.signup-form');
const feedback = document.querySelector('.feedback');

form.addEventListener('submit', e => {
   e.preventDefault();
   const name = form.username.value;
   const pattern = /^[a-zA-Z]{6,12}$/;

   if(pattern.test(name)){
     feedback.textContent = 'that username is valid!';
   }else {
     feedback.textContent = 'username must contain letters only & be between 6 and 12 characters long';
   }
});

```
## Keyboard Events

```javaScript
// get the same value
form.username.addEventListener('keyup', e => {
  console.log(e.target.value, form.username.value);
})
```

```javaScript

.success{
  border: 2px solid limegreen;
}
.error{
  border: 2px solid crimson;
}

form.username.addEventListener('keyup', e => {
  var keyTypedIn = e.target.value;
  console.log(keyTypedIn);
  if(pattern.test(keyTypedIn)){
    console.log("passed");
    form.username.setAttribute('class','success');
  }else{
    console.log("failed");
    form.username.setAttribute('class','error');
  }
});

```
