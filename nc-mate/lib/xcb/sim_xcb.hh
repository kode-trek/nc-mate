/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
void sim_xcb(string arg1) {
 /* variable(s)
 [v1] operation
 */
 string cmd = color("blue", "[] ");
 //
 string v1 = arg1;
 // command(s)
 string cmd1 = "xsel -ob";
 // op(s)
 if (v1 == "--disp") cout << cmd + cmd1 << endl;
}
