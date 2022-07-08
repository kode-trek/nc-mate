/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

#include "proc_cdup.hh"
#include "sim_cdup.hh"

int main(int argc, char* argv[]) {
	/*		variable(s)
	[v1]	color-title
	[v2]	color-help
	[v3]	color-pattern
	*/
	string v1 = color("blue", "-- C luster DUP licate --");
	string v2 = color("blue", "--help");
	string v3 = color("blue", "[PATTERN] ");
	// op(s)
	if (str(argv[1]) == "") {
		cout <<
		v1 + "\n"
		"clusters file(s) by size into multiple group(s).""\n"
		"nc-mate cdup " + v2
		<< endl;
		exit(0);
	}
	if (str(argv[1]) == "--help") {
		cout <<
		v3 + " nc-mate cdup <dir>""\n"
		"clusters file(s) within <dir>ectory into multiple folder(s) containing "
		"files of""\n""the same size."
		<< endl;
		exit(0);
	}
	if (str(argv[1]) == "--sim") {
		sim_cdup(argv[2]);
		exit(0);
	}
	proc_cdup(argv[1]);
}
