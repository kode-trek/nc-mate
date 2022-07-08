/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void proc_hi(void) {
 /* variable(s)
 [cmd] color-command
 [err] color-error/warning
 */
 string cmd = color("blue", "[] ");
 string err = color("red", "[FAILED] ");
 // command(s)
 int e = 0;
 string cmd1 = R"(dig @resolver4.opendns.com myip.opendns.com +short)";
 string cmd2 = R"(hostname -I | awk '{print $1}')";
 string cmd3 = "date";
 // op(s)
 disp("This is [public] ");
 e = sys(cmd1 + " 2>/dev/null");
 if (e) {
  disp("[local] ");
  sys(cmd2 + " 2>/dev/null");
 }
 e = sys(cmd3 + " 2>/dev/null");
 if (e) cout << err + cmd3 << endl;
 cout <<
 "\n""yet more details could be discovered manually.""\n" +
 color("blue", "[os] ") + "lsb_release -a""\n" +
 color("blue", "[kernel] ") + "uname -a""\n" +
 color("blue", "[disk] ") + "df -h""\n" +
 color("blue", "[usb] ") + "lsusb""\n" +
 color("blue", "[cpu] ") + "cat /proc/cpuinfo""\n" +
 color("blue", "[mem] ") + "cat /proc/meminfo""\n" +
 color("blue", "[ram] ") + "free -m""\n" +
 color("blue", "[net] ") + "ifconfig""\n" +
 color("blue", "[hware] ") + "lshw""\n" +
 color("blue", "[sound] ") + "aplay -l""\n" +
 color("blue", "[pci] ") + "lspci"
 << endl;
}
