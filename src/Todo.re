open Belt;
[@bs.module] external css: Js.t({..}) as 'a = "./App.module.css";

[@react.component]
let make = () => {
  let (todos, setTodos) = React.useState(() => [|"Learn Reason"|]);
  <div>
    <h1> "TODO"->React.string </h1>
    <ul>
      {Array.map(todos, todo =>
         <li> "[ ]"->React.string todo->React.string </li>
       )
       ->ReasonReact.array}
    </ul>
    <input type_="text" />
    <button
      onClick={_e =>
        setTodos(_ => [|"Woops, you need to implement this part"|])
      }>
      "+"->React.string
    </button>
  </div>;
};