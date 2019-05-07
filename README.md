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

## ReasonML for JS programmers

There's a really great "Cheat Sheet" for JS to Reason Syntax. It's no replacement for
actually learning the language but it's useful for people just trying to read ReasonML:
https://reasonml.github.io/docs/en/syntax-cheatsheet

## Reason Gotchas and new syntax

Reason can look a lot like JavaScript, however it's quite a bit different.

## `let` is `const`

In Reason `let` is used instead of `const`.

For the most part you shouldn't need any mutable variables but if you _really_ do
there's ways to do it in the [ReasonML docs](https://reasonml.github.io/docs/en/mutation).

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

Because ReasonML is statically typed (in a way that doesn't allow polymorphism) you have to specify what type the children of a component are:

```reasonml
<div>
  {React.string("Way 1")}  
  "Way 2"->React.string
</div>
```


## Reasons Module System

Again, the [official docs](https://reasonml.github.io/docs/en/module) are better
than this short explanation but ReasonML's module system is very different from JS.

In JavaScript it's file-path based. Meaning you have to point Webpack to the
actual file using folder paths like `./App/App.js`. For example:

```JS
import App from "./App/App.js";
import Math from '../lib/Math.js"

const three = Math.add(1, 2);
<App>...</App>
```

In contrast ReasonML is a _global non-path based system_. Basically it works like this:

```reason
// no imports! Just access the modules directly
let three = Math.add(1,2);
<App>...</App>
```

You just forget the imports, and it finds it because the filename is `App.re` and `Math.re`!

If you have more questions about this, just ask! It can be confusing at times. 

## Other stuff:

This project was bootstrapped with [Create React App](https://github.com/facebook/create-react-app).
