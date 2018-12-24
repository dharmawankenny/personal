open Css;

type palette = {
  lightest: color,
  lighter: color,
  light: color,
  base: color,
  dark: color,
  darker: color,
  darkest: color,
};

let white: color = hex("FFFFFF");
let black: color = hex("000000");
let gray: palette = {
  lightest: hex("FAFAFA"),
  lighter: hex("EEEEEE"),
  light: hex("CCCCCC"),
  base: hex("AAAAAA"),
  dark: hex("888888"),
  darker: hex("666666"),
  darkest: hex("333333"),
};
