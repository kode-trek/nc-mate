/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

#include "proc_app.hh"
#include "sim_app.hh"

int main(int argc , char* argv[]) {
 /* variable(s)
 [v1] color-title
 [v2] color-help
 [v3] color-pattern
 */
 string v1 = color("blue", "-- A P plication P romotion --");
 string v2 = color("blue", " --help");
 string v3 = color("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "promotes some applications via Advanced Package Tool (APT).""\n"
  "nc-mate app" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate app --promote""\n"
  "replaces and upgrades some applications via Advanced Package Tool (APT) to "
  "improve productivity."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_app(argv[2]);
  exit(0);
 }
 proc_app(argv[1]);
}
