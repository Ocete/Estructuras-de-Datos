#include <iostream>
#include <set>

using namespace std;

// This methods returns a set with the elements which are in both S1 and S2 and are not in S3
set<int> intersectionWithoutThird(set<int> S1, set<int> S2, set<int> S3) {
  set<int> result;
  set<int>::iterator it;
  for (it = S1.begin(); it != S1.end(); it++) {
    if (S2.count(*it) != 0 && S3.count(*it) == 0) {
      result.insert(*it);
    }
  }
  return result;
}

void printSet(set<int> S) {
  for (set<int>::iterator it = S.begin(); it != S.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

int main() {
  set<int> S1, S2, S3;
  for (int i=0; i<20; i++) {
    S1.insert(i);
  }
  for (int i=10; i<30; i++) {
    S2.insert(i);
  }
  for (int i=0; i<20; i+=2) {
    S3.insert(i);
  }
  cout << "S1:" << endl;
  printSet(S1);
  cout << "S2:" << endl;
  printSet(S2);
  cout << "S3:" << endl;
  printSet(S3);
  cout << "Method:" << endl;
  printSet( intersectionWithoutThird(S1, S2, S3) );
}
