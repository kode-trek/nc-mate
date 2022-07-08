/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void proc_ff(string arg1, string arg2) {
 /* variable(s)
 [v1] upgrade
 [v2] reset
 [v3] FireFox-download-link
 [v4] FireFox-tarball
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
 string v2 = arg2;
 string v3 =
 R"(https://download.mozilla.org/?)"
 R"(product=firefox-latest&os=linux64&lang=en-US)";
 string v4 = "firefox-latest.tar.bz2";
 // message(s)
 string msg1 = cmd + "retrieving latest stable version of firefox...";
 string msg2 = cmd + "removing all JSON data-bases (bookmarks, settings, etc)...";
 string msg3 = cmd + "installing firefox...";
 // command(s)
 int e = 0;
 string cmd1 =
 "wget -q --no-check-certificate --tries=0 --read-timeout=32 " + quote(v3) +
 " -O" + quote(v4);
 string cmd2 =
 "sudo rm -rf /usr/lib/firefox /usr/lib/firefox-a* /usr/bin/firefox";
 string cmd3 = "sudo tar -xf " + quote(v4) + " -C /usr/lib/";
 string cmd4 = "sudo ln -s /usr/lib/firefox/firefox /usr/bin/";
 string cmd5 = "firefox --version";
 // op(s)
 if (v1 == "--upgrade") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  disp(msg1);
  e = cd("~");
  if (e) {
   cout << err + "unable to switch path: ""~" << endl;
   exit(1);
  }
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd1 << endl;
   exit(1);
  }
  cout << out << endl;
  if (v2 == "--reset") {
   disp(msg2);
   rm("~/.mozilla/");
   cout << out << endl;
  }
  disp(msg3);
  sys(cmd2 + " 1>/dev/null 2>/dev/null");
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
   cout << err + "FireFox is not upgraded properly." << endl;
   exit(1);
  }
  cout << out << endl;
 }
}
