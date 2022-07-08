/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void sim_2dy(string arg1, string arg2) {
 /* variable(s)
 [v1] operation
 [v2] time-zone
 [cmd] color-command
 */
 string cmd = color("blue", "[] ");
 //
 string v1 = arg1;
 string v2 = arg2;
 // command(s)
 string cmd1 = "date";
 string cmd2 = "timedatectl list-timezones | less";
 string cmd3 = "sudo timedatectl set-timezone " + v2;
 // op(s)
 if (v1 == "--show") cout << cmd + cmd1 << endl;
 if (v1 == "--list") cout << cmd + cmd2 << endl;
 if (v1 == "--set") cout << cmd + cmd3 << endl;
}
