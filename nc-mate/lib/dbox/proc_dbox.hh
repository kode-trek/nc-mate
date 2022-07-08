/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void proc_dbox(string arg1) {
 /* variable(s)
 [v1] operation
 [inp] color-input
 [cmd] color-command
 [out] color-output
 [err] color-error/warning
 */
 string cmd = color("blue", "[] ");
 string out = color("green", "DONE.");
 string err1 = color("red", "HALTED.""\n""[FAILED] ");
 string err2 = color("yellow", "\n""[WARNING] ");
 //
 string v1 = arg1;
 // message(s)
 string msg1 = cmd + "installing DosBox...";
 string msg2 = cmd + "un-installing DosBox...";
 // command(s)
 int e = 0;
 string cmd1 = "sudo apt-get install dosbox -y";
 string cmd2 = "sudo apt-get remove dosbox -y";
 string cmd3 = "dosbox --version";
 // op(s)
 if (v1 == "--inst") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  apt();
  disp(msg1);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd1 << endl;
   exit(1);
  }
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 +"DosBox not installed properly." << endl;
   exit(1);
  }
  cout <<
  out + "\n" +
  cmd + "dosbox"
  << endl;
 }
 if (v1 == "--rem") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  disp(msg2);
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd2 << endl;
   exit(1);
  }
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (not e) {
   cout << err2 + "DosBox not un-installed properly." << endl;
   exit(1);
  }
  cout << out << endl;
 }
}
