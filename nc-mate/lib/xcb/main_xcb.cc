/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "proc_xcb.hh"
#include "sim_xcb.hh"

int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] color-title
 [v2] color-help
 [v3] color-pattern
 */
 string v1 = color("blue", "-- X C lip - B oard --");
 string v2 = color("blue", " --help");
 string v3 = color("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "displays text saved in clip-board.""\n"
  "nc-mate xcb" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate xcb --disp""\n"
  "echos text kept in clip-board."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_xcb(argv[2]);
  exit(0);
 }
 proc_xcb(argv[1]);
}
