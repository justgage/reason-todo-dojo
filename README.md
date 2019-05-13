# Todo list Kata (code challenge)

The challenge is to create a todo list that you can:

- [ ] Add items to.
- [ ] Check off items
- [ ] Filter items by completion status
- [ ] Whatever you want!

This is to teach basic Reason and the React bindings (called ReasonReact).

## Getting Started

#### Setting up VSCode:

We recommend you use VSCode, you can search "reasonml" for an extension that supports Reason. We recommend: ["OCaml and Reason IDE"](https://marketplace.visualstudio.com/items?itemName=freebroccolo.reasonml)

![Click the Top result of searching "reason" or if on Windows, the second.](https://cl.ly/7568476b5d2e/Image%2525202019-05-13%252520at%25252010.29.49%252520AM.png)

#### Getting the app running

To get the app running you can do:

```
npm i
npm start
```

Then open up http://localhost:1414

#### Mob timer

If you're going to switch off with other people we reccomend a mob timer to help you remember to switch. Pick whatever
- In browser: https://agility.jahed.io/timer.html
- Mac app: http://mobster.cc/

# Goals

## Goal 1: Adding Todo items

Basically you want to be able to add todo items to the todo list by typing something into the box and clicking add or pushing enter. Example:

![Adding things](https://cl.ly/071c5b571d20/download/Screen%252520Recording%2525202019-05-13%252520at%25252006.39%252520AM.gif)

**Hints:**

There's a lot of usefull functions in `Belt` which is like a lodash for any ReasonML project.

Namely here's a few useful ones:

```reason
/* This will add something to the front of a list */
List.add([1,2,3], -1) /* will return [-1, 1, 2, 3] */

/* this will add something to the back of the list */
List.concat([1,2,3], [4, 5, 6]) /* will return [1, 2, 3, 4, 5, 6] */
```

Solution: https://github.com/justgage/reason-todo-dojo/pull/4/files

## Goal 2: Checking off items on the list

At this step you'll want to check items off the list.

![Checking off items](https://cl.ly/c9d5ce5bc519/download/Screen%252520Recording%2525202019-05-13%252520at%25252010.23%252520AM.gif)

**Tip 1:**

the `[]` by default are immutable linked lists. Indexing into them to change them doesn't work.

Try using `Belt.List.mapWithIndex` to change one item. The type signiture is:

```reasonml
let mapWithIndex: (list(todo), (int, todo) => todo) => list;
```

**Tip 2:**

To update one item of a record you do it like this:

```
{...record, thing: "new value"}
```

**Gotcha 2:**

the onClick function on dom element **must** take an event so if you don't care about this event so if you do this:

```reasonml
// ERROR! typing () means you're passing "unit", which isn't compatible with the event type.
<div onClick={() => Js.log("I clicked!")}></div>
```

It will throw an error! So you have to do this:

```reasonml
/* throwing a `_` in front of a variable name lets ReasonML know that you want to ignore it. */
<div onClick={_ignoredEvent => Js.log("I clicked!")}></div>
```

Solution: https://github.com/justgage/reason-todo-dojo/pull/5/files

## Stretch Goal: Items in tabs

In this you should have tabs at the top of the todo list that you can sort them by either done, pending or all.

Example:

![gif of clicking tabs](https://cl.ly/c7204f56e62f/Screen%252520Recording%2525202019-05-13%252520at%25252007.28%252520AM.gif)

This one is more of a stretch goal so I won't provide any tips but try to use a variant type to model your tabs: https://reasonml.github.io/docs/en/variant

## Show off your stuff

Please show off your stuff by making pushing up a PR or deploying it here:

```
npm run deploy
```

Then post your solutions in the UtahJS #reasonml channel: https://slack.utahjs.com/

---

<br />
<br />
<br />

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

## Automatic returns

There's no `return` keyword in ReasonML. The last line of a function always returns:

```reasonml

let add = (x, y) => {
  let solution = x + y;
  solution; /* <- this get's automatically returned */
}
```

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
/* no imports! Just access the modules directly */
let three = Math.add(1,2);
<App>...</App>
```

You just forget the imports, and it finds it because the filename is `App.re` and `Math.re`!

If you have more questions about this, just ask! It can be confusing at times.
