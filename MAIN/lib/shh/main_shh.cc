#include "proc_shh.hh"
#include "sim_shh.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[SHush History] ", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "turns off terminal command-history.""\n"
  "nc-mate shh" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate shh --clear""\n"
  "clears command-history when terminal-session ends."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_shh(argv[2]);
  exit(0);
 }
 proc_shh(argv[1]);
}
