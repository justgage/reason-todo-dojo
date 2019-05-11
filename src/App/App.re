WebpackHelper.requireCss("./App.css");

/* The snippet below is what we'd like to have, but it doesn't seem to play
 * well with BuckleScript code generation, because we'd need the default
 * export.
 *
 * [@bs.module] external logo: string = "./logo.svg";
 */

[@react.component]
let make = () =>
  <div className="app">
    <header className="appHeader">
      <Logo />
      <p> "REASON UTAH DOJO TODO LIST"->React.string </p>
      <a
        className="appLink"
        href="https://reasonml.github.io/reason-react"
        target="_blank"
        rel="noopener noreferrer">
        {React.string("Learn Reason React")}
      </a>
    </header>
    <TodoListView />
  </div>;