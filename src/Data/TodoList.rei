/**
 * This is the TodoList's type.
 */
type t;

type id;

type todo = {
  description: string,
  isComplete: bool,
  id,
};

let moveToDone: (t, id) => t;

/* let moveToPending: (t, index) => t; */

let addTodo: (t, string) => t;

let getPending: t => array(todo);

let getDone: t => array(todo);

let toArray: t => array(todo);

let fromList: list(string) => t;

let empty: unit => t;