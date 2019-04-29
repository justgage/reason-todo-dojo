# Todo list challenge

The challenge is to create a todo list that you can:

- [ ] Add items to.
- [ ] Check off items
- [ ] Filter items by completion status
- [ ] Whatever you want!

This is to teach basic Reason and the React bindings (called ReasonReact).

## Getting Started

We recommend you use VSCode, you can search "reason" for an extension that supports Reason. We recommend
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

Reason can look a lot like JavaScript in many ways, but there are quite a bit of differences as well.

## double quotes, not single quotes

In ReasonML single quotes are reserved for a single character
much like C and C++.

```reasonml

// single character OK
let a = 's';

// this is an error
let a = 'something';

// OK
let a = "something";
```

## always put your `;`'s

JavaScript is very lax if you leave off a `;`, ReasonML, not so much. Most confusing syntax errors you get will be due to
this. The auto-formatter will catch them in some cases but
not very many.

## `let` is `const`

In Reason `let` is used instead of `const`. It works just the way you can't re-assign it, only shadow it.

```
// similar to `const` in JS
let a = 1;

// this won't work
a = 2;

// this will work but will cause a warning about the fact
// that you didn't use the `let a = 1;` above.
let a = 2;
```

For the most part you shouldn't need any mutable variables but if you _really_ do there's ways to do it in the [ReasonML docs](https://reasonml.github.io/docs/en/mutation).

### The `->` operator.

Reason has a cool operator called "Pipe first" or sometimes "Fast Pipe". Basically
it lets you call function in a chaining style:

```reason
// this is BuckleScript standard library, List is in it and many other modules
// that support "Pipe First" style.
open Belt;

// you could do this, but what do you name the variables???
let values = [1, 2, 3];
let valuesTimesTwo = List.map(i, x => x * 2);
let result = List.map(ii, x => x - 2);

// terser, but not very readable
let result = List.map(
  List.map([1, 2, 3], x => x * 2),
  x => x - 2
);

// More readable, compiles to the thing as above
let result =
  [1, 2, 3]
  ->List.map(x => x * 2)
  ->List.map(x => x - 2);
```

## The Module System

Again, the [official docs](https://reasonml.github.io/docs/en/module) are better but
here's a short explanation ReasonML's module system, as it's very different than JS.

In JavaScript to use another module you have to explicitly import it using it's file-path.
Meaning you have to point Webpack to the actual file like `../App/App.js`.

For example:

```JS
import App from "./App/App.js";
import Math from '../lib/Math.js"

export const three = Math.add(1, 2);

const make = () => <App>...</App>;

export default make;
```

In contrast ReasonML **just uses the filename and ignores where it is in the folder structure.**
Basically it works like this:

```reason
// no imports or exports! Just access the modules directly.
let three = Math.add(1,2);

[@react.component]
let make = () => <App>...</App>
```

All modules are Uppercase in naming, so if you name a file `app.re` or `App.re` then
it will become immediately available to other modules (always prefer `App.re` to avoid
confusion though).

Also exports are gone because by default everything is public inside a module. While
learning I wouldn't worry about this fact, but just know there is ways to make mark
things as private by creating a `.rei` file.

At first this system may seem like anarchy but please just [give it (a metaphorical) "five minutes"](https://signalvnoise.com/posts/3124-give-it-five-minutes). It's actually very convenient to use once you
get used to it. And for what it's worth it's how Facebook bundles all their
JS because it's much faster to compile.

## JSX differences

In JavaScript you can just interpolate strings into your HTML
without any syntax:

```javascript
<div>This is a Todo component</div>
```

Because ReasonML is statically typed you have to transform
strings and other data structures into the `React.component` type.
We use methods like `React.string` or `React.array` to do this.

```reasonml
// you have to turn the string into a component
<div>
  {React.string("This is a Todo component")}
</div>

// also often written like this:
<div>
  "This is a Todo component"->React.string
</div>
```

While this is a little less convenient this means
that your props types are automatically inferred
and enforced.

## JSX punning

Reason's JSX syntax has a lot of shortcuts for instance
instead of writing:

```reasonml
<TodoList items={items} />
```

You can simply write:

```reasonml
<TodoList items />
```

## String interpolation

If you write very much modern JavaScript you've probably got used to using
backticks for string interpolation:

```js
const className = `baseClass--${active ? 'active' : 'inactive'}`;
```

In ReasonML you would normally do something like this:

```reasonml
let className = "baseClass--" ++ (active ? "active" : "inactive");
```

In Javascript it's bad practice to use `+` because it can make strings
that _look_ like [numbers actually act like numbers](http://2ality.com/2013/04/quirk-implicit-conversion.html)!
In ReasonML everything is statically typed so this is not a danger.

There is also a `{j|baseClass--$modifier|j}` syntax that provides [a limited
form of interpolation](https://reasonml.github.io/docs/en/string-and-char#quoted-string)
but isn't quite advanced as JS. I would use syntax like above for the the most part.

## Other stuff:

This project was bootstrapped with [Create React App](https://github.com/facebook/create-react-app).
