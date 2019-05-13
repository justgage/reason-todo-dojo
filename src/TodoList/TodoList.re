WebpackHelper.requireCss("./Todo.css");

type todo = {
  description: string,
  complete: bool,
};

type viewFilter = All | Pending | Done;

[@react.component]
let make = () => {
  let (todoInput, setTodoInput) = React.useState(() => "");
  let (filter, setFilter) = React.useState(() => All);

  let (todos, setTodos) =
    React.useState(() =>
      [
        {description: "Come to ReasonML dojo", complete: true},
        {description: "Learn Reason!", complete: false},
      ]
    );

  let addTodo = () =>
    setTodos(_previousTodos =>
      [
        {
          description: todoInput,
          complete: false,
        },
        ..._previousTodos,
      ]
    );

  let toggleComplete = (idx) =>
    setTodos(_previousTodos =>
      todos->Belt.List.mapWithIndex((index, {description, complete}) => { description, complete: idx == index ? !complete : complete })
    );

  <div className="todoList">
    <h1> "Please do this"->React.string </h1>
    <input className={"tab " ++ (filter == All ? "active" : "")} type_="button" value="All" onClick={ev => setFilter(_ => All)} />
    <input className={"tab " ++ (filter == Pending ? "active" : "")} type_="button" value="Pending" onClick={ev => setFilter(_ => Pending)} />
    <input className={"tab " ++ (filter == Done ? "active" : "")} type_="button" value="Done" onClick={ev => setFilter(_ => Done)} />
    {
      React.array(
        todos
        ->Belt.List.keep(({ complete }) => switch (filter) {
            | All => true
            | Pending => !complete
            | Done => complete
          })
        ->Belt.List.mapWithIndex((index, {description, complete}) =>
            <TodoItem
              description
              complete
              key={j|$index|j}
              onClick={event => {
                toggleComplete(index)
              }}
            />
          )
        ->Belt.List.toArray,
      )
    }
    <form
      className="todoInputForm"
      onSubmit={
        event => {
          ReactEvent.Form.preventDefault(event);
          addTodo();
          setTodoInput(_ => "");
        }
      }>
      <input
        type_="text"
        className="todoInput"
        value={todoInput}
        onChange={
          event => setTodoInput(ReactEvent.Form.target(event)##value)
        }
      />
      <input className="todoButton" type_="submit" value="Add" />
    </form>
  </div>;
};
