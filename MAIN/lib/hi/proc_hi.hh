void proc_hi(string arg1) {
 /* variable(s)
 [v1] switch
 */
 string cmd = mark("[] ", "blue");
 string err = mark("[FAILED] ", "red");
 //
 string v1 = arg1;
 // command(s)
 int e = 0;
 string cmd1 = R"(dig @resolver4.opendns.com myip.opendns.com +short)";
 string cmd2 = "hostname -I";
 string cmd2_ = "hostname";
 string cmd3 = "date";
 // op(s)
 if (v1 == "--intl") {
  note(mark("[hostname]""\t", "blue"));
  sys(cmd2_ + " 2>/dev/null");
  note(mark("[public-ip]""\t", "blue"));
  e = sys(cmd1 + " 2>/dev/null");
  if (e) cout << endl;
  note(mark("[private-ip]""\t", "blue"));
  e = sys(cmd2 + " 2>/dev/null");
  if (e) cout << endl;
  note(mark("[date/time]""\t", "blue"));
  sys(cmd3 + " 2>/dev/null");
  cout <<
  "\n""yet more details could be discovered via:""\n" +
  mark("[os]""\t""\t", "blue") + "lsb_release -a""\n" +
  mark("[kernel]""\t", "blue") + "uname -a""\n" +
  mark("[disk]""\t""\t", "blue") + "df -h""\n" +
  mark("[usb]""\t""\t", "blue") + "lsusb""\n" +
  mark("[cpu]""\t""\t", "blue") + "cat /proc/cpuinfo""\n" +
  mark("[mem]""\t""\t", "blue") + "cat /proc/meminfo""\n" +
  mark("[ram]""\t""\t", "blue") + "free -m""\n" +
  mark("[net]""\t""\t", "blue") + "ifconfig""\n" +
  mark("[hware]""\t""\t", "blue") + "lshw""\n" +
  mark("[sound]""\t""\t", "blue") + "aplay -l""\n" +
  mark("[pci]""\t""\t", "blue") + "lspci"
  << endl;
 }
}
