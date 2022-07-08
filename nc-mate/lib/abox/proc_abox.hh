/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void proc_abox(string arg1, string arg2) {
 /* variable(s)
 [v1] operation
 [v2] android-application-name
 [v3] genymotion-bin-file
 [v4] genymotion-download-link
 [cmd] color-command
 [out] color-output
 [err] color-error/warning
 */
 string cmd = color("blue", "[] ");
 string out = color("green", "DONE.");
 string err1 = color("red", "[FAILED] ");
 string err2 = color("red", "HALTED.""\n""[FAILED] ");
 string err3 = color("yellow", "[WARNING] ");
 //
 string v1 = arg1;
 string v2 = arg2;
 string v3 = "genymotion-3.2.1-linux_x64.bin";
 string v4 = "https://dl.genymotion.com/releases/genymotion-3.2.1/" + v3;
 // message(s)
 string msg1 = cmd + "retrieving Genymotion...";
 string msg2 = cmd + "installing Genymotion...";
 string msg3 = cmd + "un-installing Genymotion...";
 // command(s)
 int e = 0;
 string cmd1 =
 "wget -q -c --no-check-certificate --tries=0 --read-timeout=32 " + quote(v4);
 string cmd2 = "chmod 755 " + quote(v3);
 string cmd3 = "./" + quote(v3) + " -y";
 string cmd4 = "sudo rm /usr/bin/adb";
 string cmd5 = "sudo cp genymotion/tools/adb /usr/bin/";
 string cmd6 = "adb install " + quote(v2);
 string cmd7 = "adb uninstall " + quote(v2);
 // op(s)
 if (v1 == "--inst") {
  sys("sudo '' 2>/dev/null");// traps sudo-password
  e = cd("~");
  if (e) {
   cout << err1 + "un-able to switch path: " + quote("~") << endl;
   exit(1);
  }
  disp(msg1);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd1 << endl;
   exit(1);
  }
  cout << out << endl;
  apt();
  disp(msg2);
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd2 << endl;
   exit(1);
  }
  e = sys(cmd3);
  if (e) exit(1);
  sys(cmd4 + " 1>/dev/null 2>/dev/null");
  e = sys(cmd5 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd5 << endl;
   exit(1);
  }
 }
 if (v1 == "--rem") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  disp(msg3);
//  sys("~/genymotion-*.bin --uninstall");
  rm("~/genymotion");
  rm("~/.Genymobile");
  rm("~/.config/Genymobile/Genymotion.conf");
  sys(cmd4 + " 1>/dev/null 2>/dev/null");
  cout <<
  out + "\n" +
  err3 + "To remove all programs used by 'Genymotion Desktop', you may also "
  "un-install 'VirtualBox'.""\n" +
  cmd + "nc-mate vbox --rem"
  << endl;
 }
 if (v1 == "--add") sys(cmd6);
 if (v1 == "--del") sys(cmd7);
}
