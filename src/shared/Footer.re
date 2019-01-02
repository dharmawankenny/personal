module Styles = {
  open Css;

  let wrapper = style([
    width(pct(100.0)),
    maxWidth(rem(64.0)),
    margin2(~v=zero, ~h=auto),
    padding2(~v=rem(1.0), ~h=zero),
    display(flexBox),
    flexWrap(wrap),
    alignItems(center),
    alignContent(center),
    justifyContent(flexStart),
    media("(max-width: 48rem)", [
      flexDirection(columnReverse),
      padding(rem(1.5)),
    ]),
  ]);

  let copyWrapper = style([
    flex(1),
    display(flexBox),
    flexWrap(wrap),
    alignItems(center),
    alignContent(center),
    justifyContent(flexStart),
    media("(max-width: 48rem)", [
      flex(0),
      width(pct(100.0)),
      margin2(~v=rem(1.5), ~h=zero),
    ]),
  ]);

  let copyHeader = style([
    width(pct(100.0)),
    fontSize(rem(1.0)),
    fontWeight(700),
    lineHeight(pct(125.0)),
    color(currentColor),
    opacity(0.75),
    margin3(zero, zero, rem(0.25)),
    media("(max-width: 48rem)", [
      fontSize(rem(0.85)),
      textAlign(center),
    ]),
  ]);

  let copyContent = style([
    width(pct(100.0)),
    fontSize(rem(0.75)),
    fontWeight(400),
    lineHeight(pct(125.0)),
    color(currentColor),
    opacity(0.5),
    media("(max-width: 48rem)", [
      fontSize(rem(0.65)),
      lineHeight(pct(200.0)),
      textAlign(center),
    ]),
  ]);

  let copyContentLink = style([
    textDecoration(`underline),
    color(currentColor),
  ]);

  let actionButton = style([
    margin4(~left=rem(1.0), ~right=zero, ~top=zero, ~bottom=zero),
    firstOfType([
      margin(zero),
    ]),
  ]);

  let utilityButtonWrapper = style([
    display(flexBox),
    flexWrap(wrap),
    alignItems(center),
    alignContent(center),
    justifyContent(flexEnd),
  ]);
}

let component = ReasonReact.statelessComponent("Footer");

let make = (~colorMode, ~toggleColorMode, _children) => {
  let clickToggleColor = (_event) => toggleColorMode();
  let navigate = (url: string) => (_event) => ReasonReact.Router.push(url);
  let mainColor = switch (colorMode) {
  | "Dark" => "#FFFFFF"
  | "Light" => "#000000"
  | _ => "#FFFFFF"
  };
  {
    ...component,
    render: (_self) =>
      <div className=Styles.wrapper>
        <div className=Styles.copyWrapper>
          <h1 className=Styles.copyHeader>(ReasonReact.string({js|©2019 Kenny Reida Dharmawan, All Rights Reserved.|js}))</h1>
          <h3 className=Styles.copyContent>
            (ReasonReact.string({js|Made with ReasonReact  — |js}))
            <a className=Styles.copyContentLink href="https://github.com/dharmawankenny/personal" target="_blank">(ReasonReact.string("Source Code"))</a>
            (ReasonReact.string({js| — |js}))
            <a className=Styles.copyContentLink href="https://thenounproject.com" target="_blank">(ReasonReact.string("Icons Provided by The Noun Project"))</a>
            (ReasonReact.string({js| — |js}))
            <a className=Styles.copyContentLink href="https://rsms.me/inter/" target="_blank">(ReasonReact.string("Inter UI Font by Rasmus Andersson"))</a>
          </h3>
        </div>
        <div className=Styles.utilityButtonWrapper>
          <button className=Styles.actionButton onClick=clickToggleColor>
            <Icons variant=Icons.Eye color=mainColor size=32 />
          </button>
          <button className=Styles.actionButton onClick=clickToggleColor>
            <Icons variant=Icons.Download color=mainColor size=32 />
          </button>
        </div>
      </div>,
  }
};