/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

#include "proc_ff.hh"
#include "sim_ff.hh"

int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] color-title
 [v2] color-help
 [v3] color-pattern
 */
 string v1 = color("blue", "-- F ire F ox --");
 string v2 = color("blue", " --help");
 string v3 = color("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "upgrades FireFox.""\n"
  "nc-mate ff" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate ff --upgrade [-reset]""\n"
  "upgrades Mozilla FireFox to the latest stable version.""\n"
  "(-reset) deletes all JSON databases (bookmarks, settings, ...)."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_ff(argv[2], argv[3]);
  exit(0);
 }
 proc_ff(argv[1], argv[2]);
}
