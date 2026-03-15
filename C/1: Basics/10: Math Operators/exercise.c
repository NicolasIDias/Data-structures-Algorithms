float snek_score(int num_files, int num_contributors, int num_commits,
                 float avg_bug_criticality) {
  return ((num_files * num_commits) + num_contributors ) * avg_bug_criticality;
}
