# Todo list challenge

The challenge is to create a todo list that you can:

- [ ] Add items to.
- [ ] Check off items
- [ ] Filter items by completion status
- [ ] Whatever you want!

This is to teach basic Reason and the React bindings (called ReasonReact).

## Getting Started

We recomend you use VSCode, you can search "reason" for an extension that supports Reason. We reccomend
`reason-vscode`.

To get the app running you can do:

```
yarn install
yarn start
```

Or with NPM:

```
npm i
npm start
```

If you're not using the VSCode extension mentioned above you'll also have to run the
ReasonML compiler in a separate terminal window:

```bash
yarn bs:watch
# or
npm bs:watch
```

(`bs` stands for BuckleScript the OCaml to JavaScript compiler that most Reason projects use).

## Reason Gotchas and new syntax

Reason can look a lot like JavaScript, however it's quite a bit different.

Here's just a few:

## `let` is `const`

In Reason `let` is used instead of `const`. It works just the way you can't
re-assign it, only shadow it.

```
let a = 1;

// this won't work
a = 2;

// this will work but will cause a warning about the fact
// that you didn't use the `let a = 1;` above.
let a = 2;
```

For the most part you shouldn't need any mutable variables but if you _really_ do
there's ways to do it in the [ReasonML docs](https://reasonml.github.io/).

### The `->` operator.

Reason has a cool operator called "Pipe first" or sometimes "Fast Pipe". Basically
it lets you call function in a chaining style:

```reason
// this is BuckleScript standard library, List is in it and many other modules
// that support "Pipe First" style.
open Belt;

// you could do this, but what do you name the variables???
let i = [1, 2, 3];
let ii = List.map(i, x => x * 2);
let iii = List.map(ii, x => x - 2);

// terser, but not very readable
List.map(
  List.map([1, 2, 3], x => x * 2),
  x => x - 2
)

// More readable, compiles to the thing above
[1, 2, 3]
  ->List.map(x => x * 2)
  ->List.map(x => x - 2)
```

## JSX differences

Because ReasonML is statically typed you have to specify

```reason
<TodoList items> "This is a Todo component"->React.string</Items>
```

## Other stuff:

This project was bootstrapped with [Create React App](https://github.com/facebook/create-react-app).
