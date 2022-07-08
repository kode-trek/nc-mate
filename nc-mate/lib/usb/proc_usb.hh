/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

void proc_usb(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] operation
 [v2] input
 [v3] attached-media
 [v4] temporary-list
 [inp] color-input
 [cmd] color-command
 [out] color-output
 [err] color-error/warning
 */
 string inp = color("blue", "[inp] ");
 string cmd = color("blue", "[] ");
 string out1 = color("blue", "[out] ");
 string out2 = color("green", "DONE.");
 string err1 = color("red", "[FAILED] ");
 string err2 = color("red", "HALTED.""\n""[FAILED] ");
 //
 string v1 = arg1;
 string v2 = arg2;
 string v3 = arg3;
 if (v3 == "") v3 = "disk_" + ts();
 vector<string> v4 = {};
 // message(s)
 string msg1 =
 "disk-space/file-system/USB-connected-device(s):""\n" +
 cmd + "lsblk""\n" +
 cmd + "lsusb""\n" +
 cmd + "df -hT""\n" +
 cmd + "sudo fdisk -l""\n"
 "MTP/PTP-storage (ex. android-device) | external-storage(s):""\n" +
 cmd + R"(ls /run/user/$UID/gvfs/)""\n" +
 cmd + R"(ls /media/$USER/)";
 string msg2 = "formatting USB-drive to FAT32 and erasing file(s)...";
 string msg3 = "fixing NTFS-storage to fit in with <windows:namin'> style...";
 string msg4 =
 "changing transferred-file(s) permission-mode(s) to fit in with EXT4 "
 "file-system...";
 string msg5 = "burning ISO image to portable-device...";
 // command(s)
 int e = 0;
 string cmd0 = "file -b --mime-type " + quote(v2);
 string cmd1 = "sudo umount /dev/" + v2;
 string cmd2 =
 "sudo mkdosfs -F 32 -n 'PENDRIVE_FAT32_" + ts() + "' -I /dev/" + v2;
// "sudo mkfs.vfat -F 32 -n 'PENDRIVE_FAT32_" + ts() + "' -I /dev/" + v2;
 string cmd3 = "sudo mkdir /media/$USER/" + v3;
 string cmd4 =
 "sudo mount -t ntfs-3g -o permissions /dev/" + v2 + " /media/$USER/" + v3;
 string cmd5 = "find " + quote(v2) + R"( -type f -exec chmod 664 {} \;)";
 string cmd6 = "find " + quote(v2) + R"( -type d -exec chmod 775 {} \;)";
 string cmd8 =
 "sudo dd bs=4M if=" + quote(v2) + " of=/dev/" + v3 + " conv=fdatasync";
 string cmd9 =
 "mkisofs -l -L -input-charset default -allow-lowercase -allow-multidot -o " +
 quote(v3) + ".iso " + quote(v2);
// mkisofs -o [filename.iso] [directory_path]
 string cmd10 = "sudo isoinfo -l -i " + quote(v3) + ".iso";
 string cmd11 = "sudo mkdir /cdrom/" + quote(v3);
 string cmd12 = "sudo mount -o loop " + quote(v2) + " /cdrom/" + quote(v3);
// ls testiso
// ls /boot
 string cmd13 = "sudo mount -t udf /dev/sr0 /cdrom";
 string cmd14 = "sudo umount /cdrom";
 // op(s)
 if (v1 == "--report") {
  cout << msg1 << endl;
  if (dir(v2)) {
   v4 = tree(v2, false);
   for (int i = 0; i < v4.size(); i++) {
    cout << cmd;
    cmd6 = "file -b --mime-type " + quote(v4[i]);
    cout << v4[i] << endl;
    sys(cmd7);
    cout << fsize(v4[i]) << " Byte(s)." << endl;
   }
  }
  if (not dir(v2)) sys(cmd7 + " 2>/dev/null");
 }
 if (v1 == "--ntfs-3g") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  disp(cmd + msg3);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd1 << endl;
   exit(1);
  }
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd3 << endl;
   exit(1);
  }
  e = sys(cmd4 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd4 << endl;
   exit(1);
  }
  cout << out << endl;
 }
 if (v1 == "--ext4") {
  disp(cmd + msg4);
  e = sys(cmd5 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd5 << endl;
   exit(1);
  }
  e = sys(cmd6 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd6 << endl;
   exit(1);
  }
  cout <<
  out + "\n" +
  cmd + "chmod MODE FILE""\n"
  "directory       775""\n"
  "regular-file    664""\n"
  "application     755""\n"
  "permission-mode(s) for some file(s) (ex. text/x-shellscript) need "
  "maintenance manually."
  << endl;
 }
 if (v1 == "--fat32") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  disp(cmd + msg2);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd1 << endl;
   exit(1);
  }
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd2 << endl;
   exit(1);
  }
  cout << out << endl;
 }
 if (op == "--burn") {
  disp(cmd + msg5);
  e = sys(cmd8 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd8 << endl;
   exit(1);
  }
  cout << out << endl;
 }
 if (op == "--udf") {
  if (v1 == "open") {
   sys();
  }
  if (v1 == "close") {
   sys();
  }
 }
}
