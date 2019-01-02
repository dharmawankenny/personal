type page =
  | Home
  | Story
  | Skills
  | Works
  | Contact;

type colorMode =
  | Light
  | Dark;

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
