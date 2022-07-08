/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

#include "proc_wine.hh"
#include "sim_wine.hh"

int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] color-title
 [v2] color-help
 [v3] color-pattern
 */
 string v1 = color("blue", "-- W I N dows E mulator --");
 string v2 = color("blue", " --help");
 string v3 = color("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "(un-)installs WINE (WINdows-Emulator).""\n"
  "nc-mate wine" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate wine --inst""\n"
  "installs wine.""\n" +
  v3 + "nc-mate wine --rem""\n"
  "un-installs wine."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_wine(argv[2]);
  exit(0);
 }
 proc_wine(argv[1]);
}
