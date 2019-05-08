WebpackHelper.requireCss("./Todo.css");

open Belt;
open Todo;

/* this is the best "immutable" way to change a value at an index that I could figure out :( */
let updateAtIndex = (arr: array('a), i: int, mapFn: 'a => 'a) =>
  switch (arr[i]) {
  | Some(todo) =>
    let arr = arr->Array.copy;
    (arr[i] = mapFn(todo))->ignore;
    arr;
  | None => arr
  };

[@react.component]
let make = () => {
  let (todos, setTodos) =
    React.useState(() =>
      [|
        {description: "Come to ReasonML dojo", complete: Complete},
        {description: "Learn Reason!", complete: NotStarted},
      |]
    );

  let (todoInput, setTodoInput) = React.useState(() => "");

  let addTodo = () => {
    setTodos(previousTodos =>
      Array.concat(
        previousTodos,
        [|{description: todoInput, complete: NotStarted}|],
      )
    );
    setTodoInput(_ => "");
  };

  let toggleTodo = (i: int) =>
    setTodos(todos => todos->updateAtIndex(i, Todo.toggle));

  <div className="todoList">
    <h1> "Please do this"->React.string </h1>
    {
      React.array(
        Array.mapWithIndex(todos, (index, {description, complete}) =>
          <TodoItem
            onClick={_event => toggleTodo(index)}
            description
            complete
            key={j|$index|j}
          />
        ),
      )
    }
    <form
      className="todoInputForm"
      onSubmit={
        event => {
          ReactEvent.Form.preventDefault(event);
          addTodo();
        }
      }>
      <input
        type_="text"
        className="todoInput"
        value=todoInput
        onChange={
          event => setTodoInput(ReactEvent.Form.target(event)##value)
        }
      />
      <input className="todoButton" type_="submit" value="Add" />
    </form>
  </div>;
};