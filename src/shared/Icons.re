type iconsVariant =
  | Logo;

let component = ReasonReact.statelessComponent("Icons");

let make = (~variant: iconsVariant, ~color: string, ~size: int, ~strokeWidth: int, _children) => {
  ...component,
  render: (_self) =>
    <>
      (
        switch variant {
        | Logo => <IconLogo width=size height=size stroke=color strokeWidth=strokeWidth fill="none" />
        }
      )
    </>,
};
