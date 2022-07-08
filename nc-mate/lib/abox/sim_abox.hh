/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void sim_abox(string arg1, string arg2) {
 /* variable(s)
 [v1] operation
 [v2] android-application-name
 [v3] genymotion-bin-file
 [v4] genymotion-download-link
 [cmd] color-command
 [err] color-error/warning
 */
 string cmd = color("blue", "[] ");
 string err = color("yellow", "[WARNING] ");
 //
 string v1 = arg1;
 string v2 = arg2;
 string v3 = "genymotion-3.2.1-linux_x64.bin";
 string v4 = "https://dl.genymotion.com/releases/genymotion-3.2.1/" + v3;
 // command(s)
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
  cout <<
  cmd + "cd ~""\n" +
  cmd + cmd1 + "\n" +
  cmd + "updates APT.""\n" +
  cmd + cmd2 + "\n" +
  cmd + cmd3 + "\n" +
  cmd + cmd4 + "\n" +
  cmd + cmd5
  << endl;
 }
 if (v1 == "--rem") {
  cout <<
  cmd + "rm -r ~/genymotion""\n" +
  cmd + "rm -r ~/.Genymobile""\n" +
  cmd + "rm -r ~/.config/Genymobile/Genymotion.conf""\n" +
  err + "To remove all programs used by 'Genymotion Desktop', you may also "
  "un-install 'VirtualBox'.""\n" +
  cmd + "nc-mate vbox --rem"
  << endl;
 }
 if (v1 == "--add") cout << cmd + cmd6 << endl;
 if (v1 == "--del") cout << cmd + cmd7 << endl;
}
