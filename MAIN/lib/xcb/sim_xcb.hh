void sim_xcb(string arg1) {
 /* variable(s)
 [v1] operation
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = arg1;
 // command(s)
 string cmd1 = "xsel -ob";
 // op(s)
 if (v1 == "--disp") cout << cmd + cmd1 << endl;
}
