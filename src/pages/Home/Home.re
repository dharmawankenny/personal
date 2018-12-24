module HomeStyles = {
  open Css;

  let title = style([
    fontSize(rem(3.0)),
    fontWeight(700),
    color(Theme.white),
  ]);

  let subtitle = style([
    fontSize(rem(1.25)),
    fontWeight(400),
    color(Theme.gray.lighter),
    marginTop(rem(1.0)),
  ]);
}

let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: _self =>
    <PageWrapper>
      <h1 className=HomeStyles.title>(ReasonReact.string("Hi, I'm Kenny Reida Dharmawan"))</h1>
      <h3 className=HomeStyles.subtitle>(ReasonReact.string("Sorry for the mess, this site is a work in progress"))</h3>
    </PageWrapper>,
};
