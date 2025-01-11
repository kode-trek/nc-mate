/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

int main() {
 string v1 = mark("[PATTERN] ", "blue");
 string v2 = mark("[DEVELOPMENT] ", "green");
 // op(s)
 cout <<
 v1 + "nc-mate cmd""\n"
 "lists commands.""\n" +
 v1 + "nc-mate <cmd> --help""\n"
 "displays manual for <cmd>-command.""\n" +
 v1 + "nc-mate <cmd> --sim [arg(s)...]""\n"
 "simulates process by displaying corresponding <cmd>-command associated with "
 "supplied arguments.""\n" +
 v2 + "github.com/kode-trek""\n"
 "this terminal-app had a test-drive on 'Linux Mint 21.2 (victoria)' platform."
 << endl;
}
