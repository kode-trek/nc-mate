/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void sim_cdup(string arg1) {
	/*		variable(s)
	[v1]	directory
	[v2]	list-of-file(s)-in-[v1]
	[v3]	same-list-with-folder(s)-excluded
	[v4]	size(s)-of-file(s)-in-[v3]
	[cmd]	color-command
	*/
	string cmd = color("blue", "[] ");
	//
	if (arg1 == "") arg1 = pwd();
	string v1 = arg1 + "/";
	// op(s)
	cout <<
	cmd + "ignores folder(s) inside " + quote(v1) + ".""\n" +
	cmd + "creates folder(s) with common file-size as their name(s).""\n" +
	cmd + "eliminates clusters with only 1 item."
	<< endl;
}
