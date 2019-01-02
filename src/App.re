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

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => ({
    color: Dark,
    route: switch (ReasonReact.Router.dangerouslyGetInitialUrl().path) {
    | [] => Home
    | ["story", ..._rest] => Story
    | ["skills", ..._rest] => Skills
    | ["works", ..._rest] => Works
    | ["contact", ..._rest] => Contact
    | _ => Home
    },
  }),
  reducer: (action, state) => {
    switch (action) {
    | HandleRouteChange(route: page) => ReasonReact.Update({ ...state, route: route })
    | HandleColorToggle(color: colorMode) => ReasonReact.Update({ ...state, color: color })
    };
  },
  didMount: self => {
    let routerWatcherID = ReasonReact.Router.watchUrl(url => {
      switch url.path {
      | [] => self.send(HandleRouteChange(Home))
      | ["story", ..._rest] => self.send(HandleRouteChange(Story))
      | ["skills", ..._rest] => self.send(HandleRouteChange(Skills))
      | ["works", ..._rest] => self.send(HandleRouteChange(Works))
      | ["contact", ..._rest] => self.send(HandleRouteChange(Contact))
      | _ => self.send(HandleRouteChange(Home))
      };
    });
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(routerWatcherID));
  },
  render: self => {
    <>
      <Navigation
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
