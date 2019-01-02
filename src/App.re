type page =
  | Home
  | Story
  | Skills
  | Works
  | Contact;

type colorMode =
  | Light
  | Dark;

type state = {
  color: colorMode,
  route: page,
};

type action =
  | HandleRouteChange(page)
  | HandleColorToggle(colorMode);

let setBodyBackgroundAndColor: (string, string) => _ = [%bs.raw
  {|
    function (background, color) {
      document.body.style.background = background;
      document.body.style.color = color;
    }
  |}
];

let resolveRoute = path => switch path {
  | [] => Home
  | ["story", ..._rest] => Story
  | ["skills", ..._rest] => Skills
  | ["works", ..._rest] => Works
  | ["contact", ..._rest] => Contact
  | _ => Home
};

let stringifyColorMode: colorMode => string = colorMode => switch colorMode {
| Dark => "Dark"
| Light => "Light"
};

let resolveColormode: option(string) => colorMode = colorOption => switch colorOption {
| None => Dark
| Some(colorMode) => switch colorMode {
  | "Dark" => Dark
  | "Light" => Light
  | _ => Dark
  }
};

let colorModeStorageKey = "reida.tech/color.mode";

let hydrateColorMode: _ => colorMode = _ => resolveColormode(Dom.Storage.(localStorage |> getItem(colorModeStorageKey)));
let persistColorMode: colorMode => _ = colorMode => Dom.Storage.(localStorage |> setItem(colorModeStorageKey, stringifyColorMode(colorMode)));

let toggleBaseTheme: colorMode => _ = colorMode => switch (colorMode) {
| Light => setBodyBackgroundAndColor(Theme.white, Theme.black)
| Dark => setBodyBackgroundAndColor(Theme.black, Theme.white)
};

/* set initial base theme from hydration */
toggleBaseTheme(hydrateColorMode());

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => ({
    color: hydrateColorMode(), /* hydrate from local storage, will use Dark by default */
    route: resolveRoute(ReasonReact.Router.dangerouslyGetInitialUrl().path),
  }),
  reducer: (action, state) => {
    switch (action) {
    | HandleRouteChange(route: page) => ReasonReact.Update({ ...state, route: route })
    | HandleColorToggle(colorMode: colorMode) => {
        /* toggle base color and persist to local storage */
        toggleBaseTheme(colorMode);
        persistColorMode(colorMode);
        ReasonReact.Update({ ...state, color: colorMode });
      }
    };
  },
  didMount: self => {
    let routerWatcherID = ReasonReact.Router.watchUrl(url => self.send(HandleRouteChange(resolveRoute(url.path))));
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(routerWatcherID));
  },
  render: self => {
    <>
      <Navigation
        colorMode=stringifyColorMode(self.state.color)
        toggleColorMode=(
          () => self.send(HandleColorToggle(switch (self.state.color) {
            | Light => Dark
            | Dark => Light
          }))
        )
      />
      (
        switch self.state.route {
        | Home => <Home />
        | Story => <Story />
        | Skills => <Skills />
        | Works => <Works />
        | Contact => <Contact />
        }
      )
    </>
  }
}
