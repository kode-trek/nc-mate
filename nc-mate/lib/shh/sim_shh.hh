/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void sim_shh(string arg1) {
	/*		variable(s)
	[v1]	operation
	[v2]	conf-file-bashrc
	[v3]	history-backup-file
	[cmd] color-command
	[err] color-error/warning
	*/
	string cmd = color("blue", "[] ");
	//
	string v1 = arg1;
	string v2 = R"(~/.bashrc)";
	string v3 = R"(~/hist_)" + ts();
	// command(s)
	string cmd1 = R"(cat /dev/null > ~/.bash_history)";
	string cmd2 = "history -c";
	string cmd3 = "history >> " + quote(v3);
	// op(s)
	if (v1 == "--clear") {
		cout <<
		cmd + "writes " + cmd1 + " in " + v2 + "\n" +
		cmd + "writes " + cmd2 + " in " + v2 + "\n" +
		cmd + "cp ~/.bash_history " + v3 + "\n"
		"reminds to back-up:""\n" +
		cmd + cmd3
		<< endl;
	}
}
