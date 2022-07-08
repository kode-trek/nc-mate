/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void proc_dns(string arg1) {
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
 // message(s)
 string msg1 = cmd + "fixing nameservers in '/etc/resolv.conf'...";
 string msg2 = cmd + "rolling nameserver back to '127.0.0.X'...";
 // command(s)
 int e = 0;
 string cmd1 = "sudo rm /etc/resolv.conf";
 string cmd2 =
 "sudo cp usr/lib/nc-mate-lib/asset/dns/resolv.conf.1 /etc/resolv.conf";
 string cmd3 = ". ~/.bashrc";
 string cmd4 =
 "sudo cp usr/lib/nc-mate-lib/asset/dns/resolv.conf.0 /etc/resolv.conf";
 // op(s)
 if (v1 == "--bypass") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  disp(msg1);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd2 << endl;
   exit(1);
  }
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd3 << endl;
   exit(1);
  }
  cout << out << endl;
  cout <<
  "\n""[OK] DNS resolved to <shecan.ir> nameservers:""\n"
  "\t""185.51.200.2""\n"
  "\t""178.22.122.100"
  << endl;
 }
 if (v1 == "--reset") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  disp(msg2);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  e = sys(cmd4 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd4 << endl;
   exit(1);
  }
  cout << out << endl;
  cout <<
  "\n""[OK] DNS resolved to its default:""\n"
  "\t""127.0.0.1""\n"
  "\t""127.0.0.53"
  << endl;
 }
}
