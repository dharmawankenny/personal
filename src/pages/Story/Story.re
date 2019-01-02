module StoryStyles = {
  open Css;

  let title = style([
    fontSize(rem(3.0)),
    fontWeight(700),
    color(currentColor),
  ]);
}

let component = ReasonReact.statelessComponent("Story");

let make = (_children) => {
  ...component,
  render: _self =>
    <PageWrapper>
      <h1 className=StoryStyles.title>(ReasonReact.string("Still procrastinating on this, sorry :("))</h1>
    </PageWrapper>,
};
