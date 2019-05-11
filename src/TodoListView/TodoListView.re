WebpackHelper.requireCss("./TodoListView.css");

type tabs =
  | AllTab
  | PendingTab
  | DoneTab;

[@react.component]
let make = () => {
  let (tab, setTab) = React.useState(() => AllTab);

  let (todos, setTodos) =
    React.useState(() =>
      TodoList.fromList(["learn some ReasonML", "Own the demo"])
    );

  let (todoInput, setTodoInput) = React.useState(() => "");

  let addTodo = () => {
    setTodos(todos => TodoList.addTodo(todos, todoInput));
    setTodoInput(_ => "");
  };

  let toggleTodo = i => setTodos(todos => TodoList.toggleTodo(todos, i));

  let todos =
    switch (tab) {
    | AllTab => TodoList.toArray(todos)
    | PendingTab => TodoList.getPending(todos)
    | DoneTab => TodoList.getDone(todos)
    };

  <div className="todoList">
    <h1> "Please do this"->React.string </h1>
    <div className="todoListTabs">
      <button
        className={
          "todoListTab" ++ (tab == AllTab ? " todoListTab--active" : "")
        }
        onClick={_ => setTab(_ => AllTab)}>
        "All"->React.string
      </button>
      <button
        className={
          "todoListTab" ++ (tab == PendingTab ? " todoListTab--active" : "")
        }
        onClick={_ => setTab(_ => PendingTab)}>
        "Pending"->React.string
      </button>
      <button
        className={
          "todoListTab" ++ (tab == DoneTab ? " todoListTab--active" : "")
        }
        onClick={_ => setTab(_ => DoneTab)}>
        "Done"->React.string
      </button>
    </div>
    {
      React.array(
        Belt.Array.map(todos, ({id, isComplete, description}) =>
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