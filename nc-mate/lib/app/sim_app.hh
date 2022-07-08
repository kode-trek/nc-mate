/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void sim_app(string arg1) {
 /* variable(s)
 [v1] operation
 [cmd] color-command
 */
 string cmd = color("blue", "[] ");
 //
 string v1 = arg1;
 // command(s)
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
  cout <<
  cmd + "updates APT.""\n" +
  cmd + cmd1 + "\n" +
  cmd + "rm ~/.config/xed""\n" +
  cmd + cmd2 + "\n" +
  cmd + "rm ~/.config/xreader""\n" +
  cmd + cmd3 + "\n" +
  cmd + cmd4 + "\n" +
  cmd + cmd5 + "\n" +
  cmd + cmd6 + "\n" +
  cmd + cmd7 + "\n" +
  cmd + cmd8
  << endl;
 }
}
