/*
 This is the TodoList's type's interface file. It defines
 the public interface for the "TodoList" type. `.rei` files
 are a great place to write documentation and define a
 contract with other modules that you don't want to accidentally
 change.
 */

/*
 Generally if the type is the same as the module name (file name)
 you shorten it to "t". Any place you see "t" in this file you can think
 "Todo type".

 Note this is an immutable type so that it can more easily work in React.
 */
type t;

/*
  This is a unique id that identifies every todo item from another one. Makes
  for a great key when you're displaying them and as a way to signify which
  todo you want to mark as completed.
 */
type id;

/*
  this is an individual todo item.
 */
type todo = {
  id,
  description: string,
  isComplete: bool,
};

/*
  This will take a todo item by id and move it to done.
 */
let moveToDone: (t, id) => t;

/*
  This will take a todo item by id and move it from done to
  not done.
 */
let moveToPending: (t, id) => t;

/*
  This will take an item by id and move it to the opposite
  state that it's currently in.
 */
let toggleTodo: (t, id) => t;

/* adds an item to a todo list as pending */
let addTodo: (t, string) => t;

/* gets all the todo items that you haven't been done yet. */
let getPending: t => array(todo);

/* gets all the todo items that you have been done already. */
let getDone: t => array(todo);

/* gets all the items, pending and done, and returns them as an array */
let toArray: t => array(todo);

/* Takes a List of strings and turns it into a list of pending todos */
let fromList: list(string) => t;

/* creates an empty todo list that you can add items to */
let empty: unit => t;

/* checks if a Todo list is empty */
let isEmpty: t => bool;