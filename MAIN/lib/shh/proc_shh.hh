void proc_shh(string arg1) {
 /* variable(s)
 [v1] operation
 [v2] conf-file-bashrc
 [v3] history-backup-file
 [v4] flag
 */
 string cmd = mark("[] ", "blue");
 string err = mark("[FAILED] ", "red");
 string err2 = mark("[WARNING] ", "YELLOW");
 string out1 = mark("DONE.", "blue");
 string err3 = mark("HALTED""\n""[FAILED] ", "red");
 //
 string v1 = arg1;
 string v2 = R"(~/.bashrc)";
 string v3 = R"(~/hist_)" + ts();
 bool v4 = false;
 // command(s)
 int e = 0;
 string cmd1 = R"(cat /dev/null > ~/.bash_history)";
 string cmd2 = "history -c";
 string cmd3 = "history >> " + v3;
 string cmd4 = R"(sed -i -e 's/cat \/dev\/null > ~\/.bash_history/#cat \/dev\/null > ~\/.bash_history/g' ~/.bashrc)";
 string cmd5 = R"(sed -i -e 's/history -c/#history -c/g' ~/.bashrc)";
 string cmd4_ = R"(sed -i -e 's/#cat \/dev\/null > ~\/.bash_history/cat \/dev\/null > ~\/.bash_history/g' ~/.bashrc)";
 string cmd5_ = R"(sed -i -e 's/#history -c/history -c/g' ~/.bashrc)";
 // msg
 string msg1 = "stopping recording history-commands...";
 string msg2 = "restarting recording history-commands...";
 // op(s)
 if (v1 == "--stop") {
  if (has(cat(v2), "# SHUSH""\n" + cmd1 + "\n" + cmd2)) v4 = true;
  if (v4) {
   cout << err2 + "already configured file: " + v2 << endl;
   exit(1);
  }
  note(msg1);
  if (not has(cat(v2), "# SHUSH""\n""#" + cmd1 + "\n""#" + cmd2)) {
   e = drop(v2, "\n""# SHUSH");
   e = drop(v2, "\n" + cmd1);
   e = drop(v2, "\n" + cmd2 + "\n");
   if (e) {
    cout << err + "un-able to write in file:""\t" + quote(v2) << endl;
    exit(1);
   }
  }
  if (has(cat(v2), "# SHUSH""\n""#" + cmd1 + "\n""#" + cmd2)) {
   e = sys(cmd4_);
   if (e) {
    cout << err3 + cmd4_ << endl;
    exit(1);
   }
   e = sys(cmd5_);
   if (e) {
    cout << err3 + cmd5_ << endl;
    exit(1);
   }
   cout << out1 << endl;
  }
  e = cp("~/.bash_history", v3);
  if (e) {
   cout <<
   err + "un-able to copy file(s):""\n"
   "[source] ~/.bash_history""\n"
   "[target] " + v3
   << endl;
   exit(1);
  }
  cout <<
  "\n""remember to back-up:""\n" +
  cmd + cmd3
  << endl;
 }
 if (v1 == "--start") {
  if (has(cat(v2), "# SHUSH""\n""#" + cmd1 + "\n""#" + cmd2)) v4 = true;
  if (v4) {
   cout << err2 + "already configured file: " + v2 << endl;
   exit(1);
  }
  note(msg2);
  e = sys(cmd4);
  if (e) {
   cout << err3 + cmd4 << endl;
   exit(1);
  }
  e = sys(cmd5);
  if (e) {
   cout << err3 + cmd5 << endl;
   exit(1);
  }
  cout << out1 << endl;
 }
}
