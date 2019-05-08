open Todo;

[@react.component]
let make = (~complete, ~description, ~onClick) => {
  let completeClass =
    switch (complete) {
    | Complete => "todoComplete"
    | NotStarted => "todoIncomplete"
    };

  <div onClick className={j|todo $completeClass|j}>
    description->React.string
  </div>;
};