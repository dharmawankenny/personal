type page =
  | Home
  | Story
  | Skills
  | Works
  | Contact;

type state = { route: page };

type action =
  | HandleRouteChange(page);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => ({
    route: switch (ReasonReact.Router.dangerouslyGetInitialUrl().path) {
    | [] => Home
    | ["story", ..._rest] => Story
    | ["skills", ..._rest] => Skills
    | ["works", ..._rest] => Works
    | ["contact", ..._rest] => Contact
    | _ => Home
    },
  }),
  reducer: (action, _state) => {
    switch (action) {
    | HandleRouteChange(route: page) => ReasonReact.Update({ route: route })
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
