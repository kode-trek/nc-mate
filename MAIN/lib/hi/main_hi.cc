#include "proc_hi.hh"
#include "sim_hi.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[HI] ", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "displays properties of this computer (node).""\n"
  "nc-mate hi" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate hi --intl""\n"
  "displays IP, clock, etc."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_hi();
  exit(0);
 }
 proc_hi(argv[1]);
}
