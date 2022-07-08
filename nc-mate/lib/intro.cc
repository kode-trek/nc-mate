/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

int main() {
 /* variable(s)
 [v1] color-title
 [v2] color-pattern
 [v3] OS
 */
 string v1 = color("blue", "-- N et C ommander - M A T E --");
 string v2 = color("blue", " --help");
 string v3 = color("yellow", "Linux Mint 20.2 (uma)");
 // op(s)
 cout <<
 v1 + "\n"
 "collection of tools to facilitate working with Linux Mint.""\n"
 "nc-mate" + v2 + "\n""\n"
 "this terminal-app has been tested on " + v3 + " platform.""\n"
 "[developer] github.com/kode-trek"
 << endl;
}
