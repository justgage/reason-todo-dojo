[@react.component]
let make = (~complete, ~description, ~onClick) =>
  <div
    className={"todo" ++ " " ++ (complete ? "todoComplete" : "todoIncomplete")}
    onClick={
      event => onClick(event)
    }
  >
    description->React.string
  </div>;
