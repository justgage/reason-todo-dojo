[@react.component]
let make = (~complete, ~description, ~onClick) =>
  <div
    onClick
    className={"todo" ++ " " ++ (complete ? "todoComplete" : "todoIncomplete")}>
    description->React.string
  </div>;