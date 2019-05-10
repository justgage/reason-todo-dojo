/**
 * This is the TodoList's type.
 */
type t;

type index = int;

let moveToDone: (t, index) => t;

/* let moveToPending: (t, index) => t; */

let addTodo: (t, string) => t;

let getPending: t => array((bool, string));

let getDone: t => array((bool, string));

let toArray: t => array((bool, string));

let fromList: list(string) => t;

let empty: unit => t;