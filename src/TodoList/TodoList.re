open Belt;
[@bs.module] external css: Js.t({..}) as 'a = "./Todo.module.css";

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

  <div
    className={
      css##todoList;
    }>
    <h1> "TODO"->React.string </h1>
    {Array.mapWithIndex(todos, (index, {description, complete})
       // Note: the {j| |j} syntax is used to interpolate strings (with $variableName)
       // and it's used to handle unicode characters.
       =>
         <div
           className={
             css##todo ++ " " ++ (complete ? css##complete : css##incomplete)
           }
           key={j|$index|j}>
           description->React.string
         </div>
       )
     ->ReasonReact.array}
    <form
      className={css##inputForm}
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
      <input type_="text" className={css##input} />
      <input className={css##button} type_="submit" value="Add" />
    </form>
  </div>;
};