#include "proc_abox.hh"
#include "sim_abox.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[Android virtual BOX] ", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("[EXAMPLE] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "(un-)installs Genymotion (an android-emulator).""\n"
  "nc-mate abox" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate abox --inst""\n"
  "installs Genymotion (android-emulator) that may deponds on VirtualBox.""\n" +
  v3 + "nc-mate abox --rem""\n"
  "un-installs Genymotion.""\n" +
  v3 + "nc-mate abox --add <.APK>""\n"
  "installs application in <.APK> package on virtual android-os. those <.APK> "
  "packages could be obtained from:""\n"
  R"(https://apps.evozi.com/apk-downloader/)""\n" +
  v3 + "nc-mate abox --del <apk-id>""\n"
  "un-installs android application by APK-ID.""\n" +
  v4 + "nc-mate abox --del " + quote("com.karmangames.spades")
  << endl;
  exit(0);
 }
 if(str(argv[1]) == "--sim") {
  sim_abox(argv[2], argv[3]);
  exit(0);
 }
 proc_abox(argv[1], argv[2]);
}
