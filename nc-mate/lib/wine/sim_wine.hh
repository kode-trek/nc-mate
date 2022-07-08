/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void sim_wine(string arg1) {
 /* variable(s)
 [v1] operation
 [v2] MESA_GL_VERSION_OVERRIDE=4.5 (gpu-intensive video-game)
 [cmd] color-command
 [out] color-output
 */
 string cmd = color("blue", "[] ");
 string out = color("green", "DONE.");
 //
 string v1 = arg1;
 string v2 = "export MESA_GL_VERSION_OVERRIDE=4.5";
 // command(s)
 string cmd1 = "sudo apt-get install wine -y";
 string cmd2 = "sudo apt-get remove wine -y";
 string cmd3 = "sudo apt-get install mono-complete -y";
 string cmd4 = "sudo apt-get remove mono-complete -y";
 string cmd5 = "sudo dpkg --add-architecture i386"; // older x32 software
 string cmd6 = "echo \"" + v2 + "\" >> ~/.bashrc";
 string cmd7 = "echo \"`sed '/" + v2 + "/d' ~/.bashrc`\" > ~/.bashrc";
 string cmd8 = "wine --version";
 // op(s)
 if (v1 == "--inst") {
  cout <<
  cmd + "updates APT...""\n" +
  cmd + cmd1 + "\n" +
  cmd + cmd3 + "\n" +
  cmd + cmd5 + "\n" +
  cmd + cmd7 + "\n" +
  cmd + cmd6 + "\n" +
  cmd + cmd8 + "\n"
  "extra packages (ex. gecko) in '~/.wine' and other configurations could be"
  " achieved manually via a graphical user interface.""\n"
  "> winecfg""\n"
  "> wine uninstall""\n"
  "> nc-mate wine --man"
  << endl;
 }
 if (v1 == "--rem") {
  cout <<
  cmd + cmd2 + "\n" +
  cmd + cmd4 + "\n" +
  cmd + cmd7 + "\n" +
  cmd + "removes ~/.wine""\n" +
  cmd + cmd8
  << endl;
 }
}
