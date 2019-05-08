# Todo list challenge

The challenge is to create a todo list that you can:

- [ ] Add items to.
- [ ] Check off items
- [ ] Filter items by completion status
- [ ] Whatever you want!

This is to teach basic Reason and the React bindings (called ReasonReact).

## Getting Started

#### Setting up VSCode:

We recommend you use VSCode, you can search "reasonml" for an extension that supports Reason. We recommend: "OCaml and Reason IDE"

#### Getting the app running

To get the app running you can do:

```
npm i
npm start
```

Then open up http://localhost:1414

---

## ReasonML for JS programmers

There's a really great "Cheat Sheet" for JS to Reason Syntax. It's no replacement for
actually learning the language but it's useful for people just trying to read ReasonML:
https://reasonml.github.io/docs/en/syntax-cheatsheet

## Reason Gotchas and new syntax

Reason can look a lot like JavaScript, however it's quite a bit different.

## No single quotes

In ReasonML everything is double quotes. No more fights, just get used to it.

Single quotes are reserved for a single character like in C, and C++. This is not very useful
in JavaScript however if you compile ReasonML to native it can be nice.

## `let` is `const`

In Reason `let` is used instead of `const`.

For the most part you shouldn't need any mutable variables but if you _really_ do
there's ways to do it in the [ReasonML docs](https://reasonml.github.io/docs/en/mutation).

## Don't forget your `;`'s

Again, ReasonML doesn't allow you to omit semicolons, you just have to get used to it if you're used to leaving
them off. Currently the parser can get pretty confused when you omit them so make sure to look for them as it's
one of the most common source of hard to read compiler errors.

### The `->` operator.

Reason has a cool operator called "Pipe first" or sometimes "Fast Pipe". Basically
it lets you call any group of functions in a chaining style:

```reason
/* this is BuckleScript standard library, List is in it and many other modules */
/* that support "Pipe First" style. */
open Belt;

 /* you could do this, but what do you name the variables??? */
let i = [1, 2, 3];
let ii = List.map(i, x => x * 2);
let iii = List.map(ii, x => x - 2);

/* terser, but not very readable */
let i = List.map(
  List.map([1, 2, 3], x => x * 2),
  x => x - 2
)

/* More readable and compiles to the thing above */
let i =
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
