/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void proc_2dy(string arg1, string arg2) {
 /* variable(s)
 [v1] operation
 [v2] time-zone
 [cmd] color-command
 [out] color-output
 [err] color-error/warning
 */
 string cmd = color("blue", "[] ");
 string out = color("green", "DONE.");
 string err1 = color("red", "[FAILED] ");
 string err2 = color("red", "HALTED.""\n""[FAILED] ");
 //
 string v1 = arg1;
 string v2 = arg2;
 // message(s)
 string msg1 = cmd + "setting clock...";
 // command(s)
 int e = 0;
 string cmd1 = "date";
 string cmd2 = "timedatectl list-timezones | less";
 string cmd3 = "sudo timedatectl set-timezone " + v2;
 // op(s)
 if (v1 == "--show") {
  e = sys(cmd1 + " 2>/dev/null");
  if (e) {
   cout << err1 + cmd1 << endl;
   exit(1);
  }
 }
 if (v1 == "--list") {
  e = sys(cmd2 + " 2>/dev/null");
  if (e) {
   cout << err1 + cmd2 << endl;
   exit(1);
  }
 }
 if (v1 == "--set") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  disp(msg1);
  e = sys(cmd3 + " 2>/dev/null");
  if (e) {
   cout << err2 + cmd3 << endl;
   exit(1);
  }
  cout << out << endl;
 }
}
