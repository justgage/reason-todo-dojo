[@react.component]
let make =
    (
      ~complete: bool,
      ~description: string,
      ~onClick: ReactEvent.Mouse.t => unit,
    ) => {
  let completeClass = complete ? "todoComplete" : "todoIncomplete";

  <div onClick className={j|todo $completeClass|j}>
    description->React.string
  </div>;
};