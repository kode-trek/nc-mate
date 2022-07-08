/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

#include "proc_dbox.hh"
#include "sim_dbox.hh"

int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] color-title
 [v2] color-help
 [v3] color-pattern
 */
 string v1 = color("blue", "-- D os B O X -- ");
 string v2 = color("blue", " --help");
 string v3 = color("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "(un-)installs DosBox (DOS x86 emulator).""\n"
  "nc-mate dbox" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate dbox --inst""\n"
  "installs DosBox.""\n" +
  v3 + "nc-mate dbox --rem""\n"
  "un-installs DosBox."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_dbox(argv[2]);
  exit(0);
 }
 proc_dbox(argv[1]);
}
