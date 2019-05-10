open Belt;
type todo = {description: string};

type index = int;

type t = {
  pendingTodos: array(todo),
  doneTodos: array(todo),
};

let empty = () => {pendingTodos: [||], doneTodos: [||]};

let fromList = list => {
  pendingTodos:
    list
    ->Belt.List.map(description => {description: description})
    ->Belt.List.toArray,
  doneTodos: [||],
};

let todoToTuple = (state: bool, {description}) => (state, description);

let todosToTuples = (todos, isDone) =>
  todos->Belt.Array.map(todoToTuple(isDone));

let getDone = ({doneTodos}: t) => todosToTuples(doneTodos, true);

let getPending = ({pendingTodos}: t) => todosToTuples(pendingTodos, false);

let toArray = (todos: t) =>
  Array.concat(getPending(todos), getDone(todos));

let addTodo = (todos: t, description: string) => {
  ...todos,
  pendingTodos:
    Array.concat(todos.pendingTodos, [|{description: description}|]),
};

let moveToDone = ({doneTodos, pendingTodos} as todos: t, index: int) =>
  switch (Belt.Array.get(pendingTodos, index)) {
  | Some(todo) =>
    let newPending = Array.keepWithIndex(pendingTodos, (_, i) => i != index);
    let newDone = Array.concat(doneTodos, [|todo|]);
    {doneTodos: newDone, pendingTodos: newPending};
  | None => todos
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