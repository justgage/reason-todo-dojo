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
  ...empty(),
  todos:
    range(0, List.length(list))
    ->Belt.List.zip(list)
    ->Belt.List.map(((id, description)) =>
        (id, {id, description, isComplete: false})
      )
    ->Belt.List.toArray
    ->Belt_MapInt.fromArray,
};

let filterTodoByStatus = (todos, status) =>
  todos
  ->Belt_MapInt.toArray
  ->Belt.Array.map(((_todoId, todo)) => todo)
  ->Belt.Array.keep(({isComplete}) => isComplete == status);

let getDone = ({todos}: t) => filterTodoByStatus(todos, true);

let getPending = ({todos}: t) => filterTodoByStatus(todos, false);

let toArray = (todos: t) =>
  Array.concat(getPending(todos), getDone(todos));

let addTodo = (todoList: t, description: string) => {
  nextId: todoList.nextId + 1,
  todos:
    todoList.todos
    ->Belt_MapInt.set(
        todoList.nextId,
        {id: todoList.nextId, description, isComplete: false},
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

/* let moveToPending = ({doneTodos, pendingTodos} as todos: t, index: int) =>
   Belt.(
     switch (pendingTodos[index]) {
     | Some(todo) =>
       let newPending =
         Belt.Array.keepWithIndex(pendingTodos, (_, i) => i == index);
       let newDone = Array.concat(doneTodos, [||]);
       {doneTodos: newDone, pendingTodos: newPending};
     | None => todos
     }
   ); */