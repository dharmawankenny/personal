module Styles = {
  open Css;

  let wrapper = style([
    width(pct(100.0)),
    maxWidth(rem(64.0)),
    margin2(zero, auto),
    display(flexBox),
    flexWrap(wrap),
    alignItems(center),
    alignContent(center),
    justifyContent(flexStart),
  ]);
}

let component = ReasonReact.statelessComponent("Navigation");

let make = (~toggleColorMode, _children) => {
  let clickToggleColor = (_event) => toggleColorMode();
  {
    ...component,
    render: (_self) =>
      <div className=Styles.wrapper onClick=clickToggleColor>
        <Icons variant=Icons.Logo color="#FFFFFF" size=64 strokeWidth=2/>
      </div>,
  }
};