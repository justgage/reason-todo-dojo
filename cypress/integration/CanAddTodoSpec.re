open Cypress;

context("actions", () =>
  it("should be able to add a todo item by submitting the form", () => {
    cy->visit("http://localhost:3001/");

    cy
    ->get(".todoInput")
    ->typeIntoInput("I want to make this test pass")
    ->ignore;

    cy->get(".todoInputForm")->submitForm->ignore;

    cy->get(".todoList")->contains("I want to make this test pass");
  })
);