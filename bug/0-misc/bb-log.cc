void f1() {
 string v1 = "/media/" + uname() + "/Seagate Backup Plus Drive/_BlackBox_";
 vector<string> v2 = {
 "Desktop",
 "Documents",
 "Downloads",
 "Music",
 "Pictures",
 "Public",
 "Templates",
 "Videos",
 };
 vector<string> v3 = {};
 string v4 = "_TMP_" + ts();
 // op(s)
 v1 = v1 + "/" + ts();
 md(v1);
 v3 = tree("~");
 for (int i = 0; i < v3.size(); i++) drop(v1 + "/HOME.txt", v3[i] + "\n");
 for (int i = 0; i < v2.size(); i++) {
  v3 = tree("~/" + v2[i], true);
  for (int j = 0; j < v3.size(); j++) {
   drop(v1 + "/" + v2[i] + ".txt", v3[j] + "\n");
   sys("file --mime -b " + quote(v3[j]) + " > " + v4);
   if (split(cat(v4), "/")[0] == "text") {
    md(v1 + "/" + v2[i]);
    cp(v3[j], v1 + "/" + v2[i]);
   }
   rm(v4);
  }
 }
 v4 = "/media/" + uname() + "/Seagate Backup Plus Drive/_BlackBox_";;
 v3 = tree(v4);
 if (v3.size() > 2) rm(v3[0]);
}

int main() {
 while(true) {
  sys("notify-send " + quote("creating log backup.."));
  f1();
  wait(60);
 }
}
