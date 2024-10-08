#include "proc_xcb.hh"
#include "sim_xcb.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[X ClipBoard] ", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "displays text saved in clip-board.""\n"
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
