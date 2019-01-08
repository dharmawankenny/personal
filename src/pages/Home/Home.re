module HomeStyles = {
  open Css;

  let title = style([
    fontSize(rem(3.0)),
    fontWeight(700),
    color(currentColor),
    media("(max-width: 20rem)", [
      fontSize(rem(2.5)),
    ]),
  ]);

  let subtitle = style([
    fontSize(rem(1.25)),
    fontWeight(400),
    opacity(0.5),
    marginTop(rem(1.0)),
    width(pct(100.0)),
    media("(max-width: 20rem)", [
      fontSize(rem(1.0)),
    ]),
  ]);

  let outboundLink = style([
    textDecoration(`underline),
    color(currentColor),
  ]);

  let divider = style([
    margin2(~v=zero, ~h=rem(0.5)),
  ]);
};

let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: _self =>
    <PageWrapper>
      <h1 className=HomeStyles.title>(ReasonReact.string("Hi, I'm Kenny Reida Dharmawan"))</h1>
      <h3 className=HomeStyles.subtitle>
        <a className=HomeStyles.outboundLink href="https://www.linkedin.com/in/kennyrd/" target="_blank">
          (ReasonReact.string("LinkedIn"))
        </a>
        <span className=HomeStyles.divider>(ReasonReact.string({js| — |js}))</span>
        <a className=HomeStyles.outboundLink href="https://github.com/dharmawankenny/" target="_blank">
          (ReasonReact.string("Github"))
        </a>
        <span className=HomeStyles.divider>(ReasonReact.string({js| — |js}))</span>
        <a className=HomeStyles.outboundLink href="https://codepen.io/dharmawankenny/" target="_blank">
          (ReasonReact.string("Codepen"))
        </a>
      </h3>
    </PageWrapper>,
};
