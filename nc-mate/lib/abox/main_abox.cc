/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

#include "proc_abox.hh"
#include "sim_abox.hh"

int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] color-title
 [v2] color-help
 [v3] color-pattern
 [v4] color-example
 */
 string v1 = color("blue", "-- A ndroid virtual B O X --");
 string v2 = color("blue", " --help");
 string v3 = color("blue", "[PATTERN] ");
 string v4 = color("blue", "[EXAMPLE] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "(un-)installs Genymotion (android-emulator).""\n"
  "nc-mate abox" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate abox --inst""\n"
  "installs Genymotion (android-emulator) which deponds on VirtualBox.""\n" +
  v3 + "nc-mate abox --rem""\n"
  "un-installs Genymotion.""\n" +
  v3 + "nc-mate abox --add <.APK>""\n"
  "installs application in <.APK> package on virtual android-os. <.APK> "
  "packages could be achieved from:""\n"
  R"(https://apps.evozi.com/apk-downloader/)""\n"
  R"(https://apkdl.in)""\n"
  R"(https://apkdl.net)""\n"
  R"(https://apkpure.com)""\n" +
  v3 + "nc-mate abox --del <apk-id>""\n"
  "un-installs android-application by APK-ID.""\n" +
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
