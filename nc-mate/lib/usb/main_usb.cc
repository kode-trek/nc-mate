/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

#include "proc_usb.hh"
#include "sim_usb.hh"

int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] color-title
 [v2] color-help
 [v3] color-pattern
 */
 string v1 = color("blue", "-- U niversal S erial B us --");
 string v2 = color("blue", " --help");
 string v3 = color("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "provides access to external storage(s) connected via USB.""\n"
  "nc-mate usb" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate usb --disp""\n"
  "enlists USB-connected device(s). reveals path(s) to MTP/PTP-storage "
  "(ex. android-device).""\n" +
  v3 + "nc-mate usb --ntfs <device>""\n"
  "fixes NTFS-storage-<device> to fit in with <windows:namin'> style.""\n" +
  v3 + "nc-mate usb --ext4 <file | dir>""\n"
  "changes transferred-file(s) permission-mode(s) to fit in with EXT4 "
  "file-system.""\n"
  "changes <file> permission-mode to <664>.""\n"
  "changes <dir>ectory permission-mode to <775>.""\n" +
  v3 + "nc-mate usb --file <file | dir>""\n"
  "displays properties (absolute-path, file-type, size) of <file | dir>.""\n" +
  v3 + "nc-mate usb --fat32 <file | dir>""\n"
  "hints for transfering <file>(s) to/from FAT32 file-system.""\n" +
  v3 + "nc-mate usb --burn <device>""\n"
  "burns ISO-image to portable-<device> (ex. flash-memory, CD/DVD, ...).""\n" +
  v3 + "nc-mate usb --format-fat32 <device>""\n"
  "formats USB-drive-<device> to FAT32. erases file(s).""\n" +
  v3 + "nc-mate usb --format-ntfs <device>""\n"
  "formats USB-drive-<device> to NTFS.""\n" +
  v3 + "nc-mate usb --udf [open | close]""\n"
  "(un-)mounts CD/DVD disk.""\n"
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_usb(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_usb(argv[1], argv[2], argv[3]);
}
