/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

#include "proc_ena.hh"
#include "sim_ena.hh"

int main(int argc, char* argv[]) {
	/*		variable(s)
	[v1]	color-title
	[v2]	color-help
	[v3]	color-pattern
	*/
	string v1 = color("blue", "-- E N umerate A ll --");
	string v2 = color("blue", "--help");
	string v3 = color("blue", "[PATTERN] ");
	// op(s)
	if (str(argv[1]) == "") {
		cout <<
		v1 + "\n"
		"enumerates file(s) from N to (N + n).""\n"
		"nc-mate ena " + v2
		<< endl;
		exit(0);
	}
	if (str(argv[1]) == "--help") {
		cout <<
		v3 + "nc-mate ena <dir> [<N>=1]""\n"
		"renames all file(s) in <dir>ectory starting from N."
		<< endl;
		exit(0);
	}
	if (str(argv[1]) == "--sim") {
		sim_ena(argv[2], argv[3]);
		exit(0);
	}
	proc_ena(argv[1], argv[2]);
}
