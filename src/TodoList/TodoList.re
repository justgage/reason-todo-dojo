WebpackHelper.requireCss("./Todo.css");

type todo = {
  description: string,
  complete: bool,
};

[@react.component]
let make = () => {
  let (todoInput, setTodoInput) = React.useState(() => "");

  let (todos, setTodos) =
    React.useState(() =>
      [
        {description: "Come to ReasonML dojo", complete: true},
        {description: "Learn Reason!", complete: false},
      ]
    );

  let addTodo = () =>
    setTodos(previousTodos => {
      setTodoInput(_oldInput => "");

      Belt.List.concat(
        previousTodos,
        [{description: todoInput, complete: false}],
      );
    });

  let toggleTodo = indexToToggle =>
    setTodos(todos =>
      Belt.List.mapWithIndex(todos, (i, todo) =>
        if (i == indexToToggle) {
          {...todo, complete: !todo.complete};
        } else {
          todo;
        }
      )
    );

  <div className="todoList">
    <h1> "Please do this"->React.string </h1>
    {
      React.array(
        todos
        ->Belt.List.mapWithIndex((index, {description, complete}) =>
            <TodoItem
              description
              onClick={_ => toggleTodo(index)}
              complete
              key={j|$index|j}
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
        }
      }>
      <input
        type_="text"
        className="todoInput"
        onChange={
          event => setTodoInput(ReactEvent.Form.target(event)##value)
        }
      />
      <input className="todoButton" type_="submit" value="Add" />
    </form>
  </div>;
};