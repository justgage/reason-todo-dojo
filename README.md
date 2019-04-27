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

In Reason `let` is used instead of `const`. It works just the way you can't
re-assign it, only shadow it.

```
// similar to `const` in JS
let a = 1;

// this won't work
a = 2;

// this will work but will cause a warning about the fact
// that you didn't use the `let a = 1;` above.
let a = 2;
```

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

Because ReasonML is statically typed you have to specify

```reason
<TodoList items> "This is a Todo component"->React.string</Items>
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

To fully understand this I have a few "rules":

### 1. The file names are module names

What you name you're file **_is_** the module name of the file in Reason. Meaning if you have a file named `Math.re`
that looked like this:

```reasonml
// util/Math.re

let add = (x, y) => x + y;
```

you can refer to that in _any other file_ by just doing this:

```reasonml
// any other reason file:
let two = Math.add(1,3);
```

While you _can_ name files like `inThisWay.re` and it will uppercase the first letter but
I would highly recommend you do it `InThisFashion.re` (first letter uppercase) due to to the fact that module names **must** always start with an uppercase letter, so
this removes indirection.

#### 2. Module names (thus filenames) must be **globally unique.**

When you name a file in ReasonML it's name must be **globally unique**!. Meaning if you name a file
`TodoList.re`, no other file may be names that same thing. You may have this kind of reaction:

> this is crazy unsaleable!!!

To which I say, **then Facebook is un-scalable** then because that's how they do it (even with their JavaScript projects).

When it comes to _build speed_ it's actually a **lot more scalable.** It's one of the primary reasons
that ReasonML is the fastest alt-JS compilers out there. It literally can start up and finish in seconds,
even milliseconds in many cases.

You might say,

> _"What about libraries? Wouldn't that cause a lot of conflicts?"_

the compiler for Reason (bsb) can scope your package name so every module is prefixed with the name of your library. There's also a [good article about how to name things in a more namespace friendly way](https://dev.to/yawaramin/a-modular-ocaml-project-structure-1ikd). I think this is overkill for most personal and even company projects, but it's nice for libraries.

Also as a benefit it makes things much easier to use `⌘-P` (`Ctrl-P` on windows) to find files. No problem with every file named `index.js`.

### 3. Everything in modules is auto-exported

You don't have to add explicit exports because by default everything is auto-exported! If you want to limit what you export you need to create a
`.rei` file. Read about doing this here.

#### 4. Folders don't have any scope, only files.

Putting a `.re` file into a folder doesn't do anything. However, the Reason compiler will look into folders just in case so long as you configure it to in the `bsconfig.json` file.

**Note**: However interop with JS breaks this fact because JS _does_ care about files.

#### 4. Modules have a lots of super powers

Modules are really powerfull in ReasonML (really OCaml), read the offical docs for more cool stuff.

## Other stuff:

This project was bootstrapped with [Create React App](https://github.com/facebook/create-react-app).
