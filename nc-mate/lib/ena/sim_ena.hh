/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void sim_ena(string arg1, string arg2) {
	/*		variable(s)
	[v1]	directory-name
	[v2]	<N>-initial-of-file-name(s)
	[v3]	<n>-number-of-item(s)-in-[v1]
	[v4]	list-of-item(s)-in-[v1]
	[v5]	temporary-directory-name-in-[v1]
	[v6]	source
	[v7]	target
	*/
	string v1 = arg1 + "/";
	int v2, v3 = 0;
	if (arg2 == "") v2 = 1;
	else v2 = str2num(arg2);
	vector<string> v4 = {};
	string v5 = "." + ts();
	string v6, v7 = "";
	// command | comment
	string cmd = color("blue", "[] ");
	string cmt = color("blue", "[...] ");
	// op(s)
	cd(v1);
	v4 = tree(pwd(), false);
	v3 = v2;
	for(int i = 0; i < v4.size(); i++) {
		if (dir(v4[i])) continue;
		else v3++;
	}
	cout <<
	cmt + "creates " + quote(v5) + " directory inside " + shortq(v1) + ".""\n" +
	cmt + "moves file(s) within " + shortq(v1) + " to " + quote(v5) + ".""\n" +
	cmt + "enumerates them: " + str(v2) + "~" + str(v3 - 1) + ".""\n" +
	cmt + "replaces them back to " + shortq(v1) + ".""\n" +
	cmt + "removes " + quote(v5) + "."
	<< endl;
}
