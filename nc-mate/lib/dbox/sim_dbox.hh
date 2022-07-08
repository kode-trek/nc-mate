/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void sim_dbox(string arg1) {
 /* variable(s)
 [v1] operation
 [inp] color-input
 [cmd] color-command
 */
 string cmd = color("blue", "[] ");
 //
 string v1 = arg1;
 // command(s)
 string cmd1 = "sudo apt-get install dosbox -y";
 string cmd2 = "sudo apt-get remove dosbox -y";
 string cmd3 = "dosbox --version";
 // op(s)
 if (v1 == "--inst") {
  cout <<
  cmd + "updates APT.""\n" +
  cmd + cmd1 + "\n" +
  cmd + cmd3 + "\n" +
  cmd + "dosbox"
  << endl;
 }
 if (v1 == "--rem") {
  cout <<
  cmd + cmd2 + "\n" +
  cmd + cmd3
  << endl;
 }
}
