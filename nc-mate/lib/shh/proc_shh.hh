/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void proc_shh(string arg1) {
	/*		variable(s)
	[v1]	operation
	[v2]	conf-file-bashrc
	[v3]	history-backup-file
	[cmd] color-command
	[err] color-error/warning
	*/
	string cmd = color("blue", "[] ");
	string err = color("red", "[FAILED] ");
	//
	string v1 = arg1;
	string v2 = R"(~/.bashrc)";
	string v3 = R"(~/hist_)" + ts();
	// command(s)
	int e = 0;
	string cmd1 = R"(cat /dev/null > ~/.bash_history)";
	string cmd2 = "history -c";
	string cmd3 = "history >> " + quote(v3);
	// op(s)
	if (v1 == "--clear") {
		e = drop(v2, "\n" + cmd1);
		e = drop(v2, "\n" + cmd2);
		if (e) {
			cout << err + "un-able to write in file:""\t" + quote(v2) << endl;
			exit(1);
		}
		e = cp("~/.bash_history", v3);
		if (e) {
			cout <<
			err + "un-able to copy file(s):""\n"
			"[source] " + quote("~/.bash_history") + "\n"
			"[target] " + quote(v3)
			<< endl;
			exit(1);
		}
		cout <<
		"remember to back-up:""\n" +
		cmd + cmd3
		<< endl;
	}
}
