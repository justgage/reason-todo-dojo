WebpackHelper.requireCss("./Todo.css");
open Belt;

type todo = {
  description: string,
  complete: bool,
};

[@react.component]
let make = () => {
  let (todos, setTodos) =
    React.useState(() =>
      [|
        {description: "Come to ReasonML dojo", complete: true},
        {description: "Learn Reason!", complete: false},
      |]
    );

  let addTodo = () =>
    setTodos(_previousTodos =>
      [|
        {
          description: "Woops, you need to implement this part",
          complete: false,
        },
      |]
    );

  <div className="todoList">
    <h1> "Do this"->React.string </h1>
    {todos
     ->Array.mapWithIndex((index, {description, complete}) =>
         <TodoItem description complete key={j|$index|j} />
       )
     ->ReasonReact.array}
    <form
      className="todoInputForm"
      onSubmit={event => {
        ReactEvent.Form.preventDefault(event);
        addTodo();
      }}>
      <input type_="text" className="todoInput" />
      <input className="todoButton" type_="submit" value="Add" />
    </form>
  </div>;
};