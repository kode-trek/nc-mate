void proc_snf(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] operation
 [v2] entry
 [v3] path-to-directory
 */
 string cmd = mark("[] ", "blue");
 string out = mark("\n""[DONE] ", "green");
 //
 string v1 = arg1;
 string v2 = arg2;
 string v3 = arg3;
 if (v3 == "") v3 = pwd();
 // command(s)
 string cmd1 = "find " + quote(v3) + " -type f -iname " + quote(v2);
 string cmd2 = "find " + quote(v3) + " -type d -iname " + quote(v2);
 string cmd3 = "grep -rnw " + quote(v3) + " -e " + quote(v2);
 // op(s)
 if (v1 == "--file") {
  sys(cmd1);
  sys(cmd2);
  cout << out + cmd1 + out + cmd2 << endl;
 }
 if (v1 == "--text") {
  sys(cmd3);
  cout << out + cmd3 << endl;
 }
}
