/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/nc-mate/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/

#include "proc_job.hh"
#include "sim_job.hh"

int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] color-title
 [v2] color-help
 [v3] color-pattern
 */
 string v1 = color("blue", "-- J O B --");
 string v2 = color("blue", " --help");
 string v3 = color("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "manages job scheduler.""\n"
  "nc-mate job" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate job <clock> <task> [arg(s)...]""\n"
  "runs <task> at specified <clock> date and time."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_job(argv[2], argv[3]);
  exit(0);
 }
 proc_job(argv[1], argv[2]);
}
