/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
void proc_xcb(string arg1) {
 /* variable(s)
 [v1] operation
 [v2] start-of-text-in-clipboard
 [v3] end-of-text-in-clipboard
 [err] color-error/warning
 */
 string err = color("red", "\n""[FAILED] ");
 //
 string v1 = arg1;
 string v2 = color("yellow", "START#");
 string v3 = color("yellow", "#STOP");
 // command(s)
 int e = 0;
 string cmd1 = "xsel -ob";
 //
 if (v1 == "--disp") {
  disp(v2);
  e = sys(cmd1 + " 2>/dev/null");
  if (e) {
   cout << err + cmd1 << endl;
   exit(1);
  }
  cout << v3 << endl;
 }
}
