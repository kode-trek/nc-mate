/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

#include "proc_snf.hh"
#include "sim_snf.hh"

int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] color-title
 [v2] color-help
 [v3] color-pattern
 [v4] color-example
 */
 string v1 = color("blue", "-- S N i F fer --");
 string v2 = color("blue", " --help");
 string v3 = color("blue", "[PATTERN] ");
 string v4 = color("blue", "[EXAMPLE] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "searches for file(s) or certain phrase(s) inside file(s).""\n"
  "nc-mate snf" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate snf --file <file-name> [<dir>=PWD]""\n"
  "looks for file(s) or folder(s) by RegEx <file-name> within <dir>.""\n" +
  v3 + "nc-mate snf --text <phrase> [<dir>=PWD]""\n"
  "looks for <phrase> by RegEx inside all file(s) within <dir>.""\n"
  + v4 + "nc-mate snf --file '*[.]xml'""\n"
  "looks for all '.xml' file(s) within current-directory recursively."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_snf(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_snf(argv[1], argv[2], argv[3]);
}
