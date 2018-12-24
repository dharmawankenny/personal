module SkillsStyles = {
  open Css;

  let title = style([
    fontSize(rem(3.0)),
    fontWeight(700),
    color(Theme.white),
  ]);
}

let component = ReasonReact.statelessComponent("Skills");

let make = (_children) => {
  ...component,
  render: _self =>
    <PageWrapper>
      <h1 className=SkillsStyles.title>(ReasonReact.string("Still procrastinating on this, sorry :("))</h1>
    </PageWrapper>,
};
