/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void sim_dns(string arg1) {
 /* variable(s)
 [v1] operation
 [inp] color-input
 [cmd] color-command
 [out] color-output
 [err] color-error/warning
 */
 string cmd = color("blue", "[] ");
 string out = color("green", "DONE.");
 string err = color("red", "HALTED.""\n""[FAILED] ");
 //
 string v1 = arg1;
 // command(s)
 string cmd1 = "sudo rm /etc/resolv.conf";
 string cmd2 =
 "sudo cp usr/lib/nc-mate-lib/asset/dns/resolv.conf.1 /etc/resolv.conf";
 string cmd3 = ". ~/.bashrc";
 string cmd4 =
 "sudo cp usr/lib/nc-mate-lib/asset/dns/resolv.conf.0 /etc/resolv.conf";
 // op(s)
 if (v1 == "--bypass") {
  cout <<
  cmd + cmd1 + "\n" +
  cmd + cmd2 + "\n" +
  cmd + cmd3 +
  "\n""[OK] DNS resolved to <shecan.ir> nameservers:""\n"
  "\t""185.51.200.2""\n"
  "\t""178.22.122.100"
  << endl;
 }
 if (v1 == "--reset") {
  cout <<
  cmd + cmd1 + "\n" +
  cmd + cmd4 +
  "\n""[OK] DNS resolved to its default:""\n"
  "\t""127.0.0.1""\n"
  "\t""127.0.0.53"
  << endl;
 }
}
