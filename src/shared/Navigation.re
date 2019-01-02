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
  ]);

  let actionButton = style([
    margin4(~left=rem(1.0), ~right=zero, ~top=zero, ~bottom=zero),
    firstOfType([
      margin(zero),
    ]),
  ]);

  let utilityButtonWrapper = style([
    flex(1),
    display(flexBox),
    flexWrap(wrap),
    alignItems(center),
    alignContent(center),
    justifyContent(flexEnd),
  ]);
}

let component = ReasonReact.statelessComponent("Navigation");

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
        <button className=Styles.actionButton onClick=navigate("/")>
          <Icons variant=Icons.Logo color=mainColor size=48 />
        </button>
        <button className=Styles.actionButton onClick=navigate("/story")>
          <Icons variant=Icons.Story color=mainColor size=32 />
        </button>
        <button className=Styles.actionButton onClick=navigate("/skills")>
          <Icons variant=Icons.Skills color=mainColor size=32 />
        </button>
        <button className=Styles.actionButton onClick=navigate("/works")>
          <Icons variant=Icons.Works color=mainColor size=32 />
        </button>
        <button className=Styles.actionButton onClick=navigate("/contact")>
          <Icons variant=Icons.Contact color=mainColor size=32 />
        </button>
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