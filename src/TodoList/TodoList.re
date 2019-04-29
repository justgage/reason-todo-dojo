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

  <div className="todoList">
    <h1> "TODO"->React.string </h1>
    {Array.mapWithIndex(todos, (index, {description, complete})
       // Note: the {j| |j} syntax is used to interpolate strings (with $variableName)
       // and it's used to handle unicode characters.
       =>
         <div
           className={
             "todo" ++ " " ++ (complete ? "todoComplete" : "todoIncomplete")
           }
           key={j|$index|j}>
           description->React.string
         </div>
       )
     ->ReasonReact.array}
    <form
      className="todoInputForm"
      onSubmit={event => {
        ReactEvent.Form.preventDefault(event);
        setTodos(_previousTodos =>
          [|
            {
              description: "Woops, you need to implement this part",
              complete: false,
            },
          |]
        );
      }}>
      <input type_="text" className="todoInput" />
      <input className="todoButton" type_="submit" value="Add" />
    </form>
  </div>;
};