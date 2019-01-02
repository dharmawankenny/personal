open AppHelpers;

/* set initial base theme from hydration */
toggleBaseTheme(hydrateColorMode());

type state = {
  color: colorMode,
  route: page,
};

type action =
  | HandleRouteChange(page)
  | HandleColorToggle(colorMode);

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
      <Navigation colorMode=stringifyColorMode(self.state.color) />
      (
        switch self.state.route {
        | Home => <Home />
        | Story => <Story />
        | Skills => <Skills />
        | Works => <Works />
        | Contact => <Contact />
        }
      )
      <Footer
        colorMode=stringifyColorMode(self.state.color)
        toggleColorMode=(
          () => self.send(HandleColorToggle(switch (self.state.color) {
            | Light => Dark
            | Dark => Light
          }))
        )
      />
    </>
  }
};
