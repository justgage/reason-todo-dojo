WebpackHelper.requireCss("./Todo.css");

[@react.component]
let make = () => {
  let (todos, setTodos) =
    React.useState(() =>
      TodoList.fromList(["learn some ReasonML", "Own the demo"])
    );

  let (todoInput, setTodoInput) = React.useState(() => "");

  let addTodo = () => {
    setTodos(todos => TodoList.addTodo(todos, todoInput));
    setTodoInput(_ => "");
  };

  let toggleTodo = i => setTodos(todos => TodoList.moveToDone(todos, i));

  <div className="todoList">
    <h1> "Please do this"->React.string </h1>
    {
      React.array(
        Belt.Array.map(
          TodoList.toArray(todos), ({id, isComplete, description}) =>
          <TodoItem
            onClick={_event => toggleTodo(id)}
            description
            complete=isComplete
            key={j|$id|j}
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