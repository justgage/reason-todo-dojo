WebpackHelper.requireCss("./Todo.css");

[@react.component]
let make = () => {
  let (todos, setTodos) = React.useState(() => TodoList.empty());

  let (todoInput, setTodoInput) = React.useState(() => "");

  let addTodo = () => {
    setTodos(todos => TodoList.addTodo(todos, todoInput));
    setTodoInput(_ => "");
  };

  let toggleTodo = (i: int) =>
    setTodos(todos => TodoList.moveToDone(todos, i));

  <div className="todoList">
    <h1> "Please do this"->React.string </h1>
    {
      React.array(
        Belt.Array.mapWithIndex(
          TodoList.toArray(todos), (index, (complete, description)) =>
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