[@bs.val] external context: (string, unit => unit) => unit = "context";
[@bs.val] external beforeEach: (unit => unit) => unit = "beforeEach";
[@bs.val] external it: (string, unit => unit) => unit = "it";

type cypressGlobal;
[@bs.val] external cy: cypressGlobal = "cy";

[@bs.send] external visit: (cypressGlobal, string) => unit = "visit";

type domNode;
[@bs.send] external get: (cypressGlobal, string) => domNode = "get";
[@bs.send] external contains: (domNode, string) => unit = "contains";

/**
 * Type into the box.
 */
[@bs.send]
external typeIntoInput: (domNode, string) => domNode = "type";

[@bs.send] external submitForm: domNode => domNode = "submit";

/**
 * Some boolean assertion
 *
 * TODO: type the first parameter!
 */
[@bs.send]
external should: (domNode, string, string) => domNode = "should";