type iconsVariant =
  | Logo
  | Eye
  | Story
  | Skills
  | Works
  | Contact
  | Download;

let component = ReasonReact.statelessComponent("Icons");

let make = (~variant: iconsVariant, ~color: string, ~size: int, _children) => {
  ...component,
  render: (_self) =>
    <>
      (
        switch variant {
        | Logo => <IconLogo size=size stroke=color fill="none" />
        | Eye => <IconEye size=size fill=color />
        | Story => <IconStory size=size fill=color />
        | Skills => <IconSkills size=size fill=color />
        | Works => <IconWorks size=size fill=color />
        | Contact => <IconContact size=size fill=color />
        | Download => <IconDownload size=size fill=color />
        }
      )
    </>,
};
