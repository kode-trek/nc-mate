/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void proc_app(string arg1) {
 /* variable(s)
 [v1] operation
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
 string msg1 = cmd + "(un-)installing packages via APT (might take long)...";
 // command(s)
 int e = 0;
 string cmd1 = "sudo apt-get remove xed -y";
 string cmd2 = "sudo apt-get remove xreader -y";
 string cmd3 = "sudo apt-get install evince -y";
 string cmd4 = "sudo apt-get install gedit gedit-plugins -y";
 string cmd5 =
 "sudo apt-get install remmina remmina-plugin-vnc remmina-plugin-rdp -y";
 string cmd6 = "sudo apt-get install tree -y";
 string cmd7 = "sudo apt-get install vlc -y";
 string cmd8 = "sudo apt-get install xchm -y";
 // op(s)
 if (v1 == "--promote") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  apt();
  disp(msg1);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd1 << endl;
   exit(1);
  }
  rm("~/.config/xed");
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd2 << endl;
   exit(1);
  }
  rm("~/.config/xreader");
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd3 << endl;
   exit(1);
  }
  e = sys(cmd4 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd4 << endl;
   exit(1);
  }
  e = sys(cmd5 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd5 << endl;
   exit(1);
  }
  e = sys(cmd6 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd6 << endl;
   exit(1);
  }
  e = sys(cmd7 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd7 << endl;
   exit(1);
  }
  e = sys(cmd8 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd8 << endl;
   exit(1);
  }
  cout << out << endl;
 }
}
