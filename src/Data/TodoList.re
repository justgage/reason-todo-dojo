open Belt;

type id = int;
type todo = {
  description: string,
  isComplete: bool,
  id,
};

type t = {
  nextId: int,
  todos: Belt_MapInt.t(todo),
};

let empty = () => {nextId: 0, todos: Belt_MapInt.empty};

let rec range = (start: int, end_: int) =>
  if (start >= end_) {
    [];
  } else {
    [start, ...range(start + 1, end_)];
  };

let fromList = list => {
  nextId: List.length(list),
  todos:
    range(0, List.length(list))
    ->Belt.List.zip(list)
    ->Belt.List.map(((id, description)) =>
        (id, {id, description, isComplete: false})
      )
    ->Belt.List.toArray
    ->Belt_MapInt.fromArray,
};

let toArray = ({todos}: t) =>
  todos->Belt_MapInt.toArray->Belt.Array.map(((_todoId, todo)) => todo);

let filterTodoByStatus = (todos, status) =>
  todos->toArray->Belt.Array.keep(({isComplete}) => isComplete == status);

let getDone = (todos: t) => filterTodoByStatus(todos, true);

let getPending = (todos: t) => filterTodoByStatus(todos, false);

let addTodo = (todoList: t, description: string) => {
  nextId: todoList.nextId + 1,
  todos:
    todoList.todos
    ->Belt_MapInt.set(
        todoList.nextId,
        {id: todoList.nextId, description, isComplete: false},
      ),
};

let toggleTodo = (todoList, index: int) => {
  ...todoList,
  todos:
    Belt_MapInt.update(
      todoList.todos,
      index,
      fun
      | Some(todo) => Some({...todo, isComplete: !todo.isComplete})
      | x => x,
    ),
};
let moveToPending = (todoList, index: int) => {
  ...todoList,
  todos:
    Belt_MapInt.update(
      todoList.todos,
      index,
      fun
      | Some(todo) => Some({...todo, isComplete: false})
      | x => x,
    ),
};
let moveToDone = (todoList, index: int) => {
  ...todoList,
  todos:
    Belt_MapInt.update(
      todoList.todos,
      index,
      fun
      | Some(todo) => Some({...todo, isComplete: true})
      | x => x,
    ),
};