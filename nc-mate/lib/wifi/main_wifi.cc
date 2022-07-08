/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

#include "proc_wifi.hh"
#include "sim_wifi.hh"

int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] color-title
 [v2] color-help
 [v3] color-pattern
 */
 string v1 = color("blue", "-- W I F I --");
 string v2 = color("blue", " --help");
 string v3 = color("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "establishes/disbands WiFi connection.""\n"
  "nc-mate wifi" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate wifi --disp [-full]""\n"
  "enlists available WiFi hotspot(s).""\n" +
  v3 + "nc-mate wifi --connect <ssid> <pass>""\n"
  "connects to WiFi hotspot.""\n" +
  v3 + "nc-mate wifi --forget <name>""\n"
  "removes WiFi connection."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_wifi(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_wifi(argv[1], argv[2], argv[3]);
}
