[@react.component]
let make = (~complete, ~description) => {
  <div
    className={"todo" ++ " " ++ (complete ? "todoComplete" : "todoIncomplete")}>
    description->React.string
  </div>;
};