#include "proc_snf.hh"
#include "sim_snf.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[SNiFfer] ", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("[EXAMPLE] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "searches for file(s) or certain phrase(s) inside file(s).""\n"
  "nc-mate snf" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate snf --file <file-name> [<dir>=CWD]""\n"
  "looks for file(s)/folder(s) <file-name> by RegEx within <dir>.""\n" +
  v3 + "nc-mate snf --text <phrase> [<dir>=CWD]""\n"
  "looks for <phrase> by RegEx inside all file(s) within <dir>.""\n"
  + v4 + "nc-mate snf --file '*[.]xml'""\n"
  "looks for all '.xml' file(s) within current-working-directory recursively."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_snf(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_snf(argv[1], argv[2], argv[3]);
}
