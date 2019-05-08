type completionStatus =
  | Complete
  | NotStarted;

type t = {
  description: string,
  complete: completionStatus,
};

let toggle = ({complete} as todo: t) =>
  switch (complete) {
  | Complete => {...todo, complete: NotStarted}
  | NotStarted => {...todo, complete: Complete}
  };