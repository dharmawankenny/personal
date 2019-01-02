module Styles = {
  open Css;

  let wrapper = style([
    width(pct(100.0)),
    maxWidth(rem(64.0)),
    minHeight(`calc(`sub, vh(100.0), rem(10.0))),
    margin2(zero, auto),
    display(flexBox),
    flexWrap(wrap),
    alignItems(center),
    alignContent(center),
    justifyContent(flexStart),
    media("(max-width: 48rem)", [
      padding(rem(1.5)),
    ]),
  ]);
};

let component = ReasonReact.statelessComponent("PageWrapper");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className=Styles.wrapper>
      ...(_children)
    </div>,
};
