/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void proc_ena(string arg1, string arg2) {
	/*		variable(s)
	[v1]	directory-name
	[v2]	<N>-initial-of-file-name(s)
	[v3]	<n>-number-of-item(s)-in-[v1]
	[v4]	list-of-item(s)-in-[v1]
	[v5]	temporary-directory-name-in-[v1]
	[v6]	source
	[v7]	target
	[inp] color-input
	[cmd] color-command
	[out] color-output
	[err] color-error/warning
	*/
	string inp = color("blue", "[inp] ");
	string out = color("green", "[OK] ");
	string err = color("yellow", "[WARNING] ");
	//
	string v1 = arg1 + "/";
	int v2, v3 = 0;
	if (arg2 == "") v2 = 1;
	else v2 = str2num(arg2);
	vector<string> v4 = {};
	string v5 = "." + ts();
	string v6, v7 = "";
	// op(s)
	if (not dir(v1)) {
		cout <<
		inp + v1 + "\n" +
		err + "directory not found."
		<< endl;
		exit(1);
	}
	if (not write_access(v1)) {
		cout <<
		inp + pwd() + "\n" +
		err + "write-permission denied."
		<< endl;
		exit(1);
	}
	cd(v1);
	v4 = tree(pwd(), false);
	md(v5);
	v3 = v2;
	for(int i = 0; i < v4.size(); i++) {
		if (dir(v4[i])) continue;
		else {
			v6 = v4[i];
			v7 = v5 + "/" + str(v3) + uri(v4[i])[3];
			mv(v6, v7);
			(v3)++;
		}
	}
	v4 = tree(v5);
	for(int i = 0; i < v4.size(); i++) {
		v6 = v4[i];
		v7 = pwd();
		mv(v6, v7);
	}
	rm(v5);
	cout << out + "file(s) renamed: " + str(v2) + "~" + str(v3 - 1) << endl;
}
