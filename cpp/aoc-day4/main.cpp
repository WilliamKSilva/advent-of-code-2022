#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pair {
  public:
    string firstSection;
    string secondSection;
};

void readFileData(string & fileName, vector<string>& pairsString) {
  ifstream file{};

  file.open(fileName);

  if (!file) {
    cout << "Error opening input file\n";

    return;
  }

  int fileSize = 0;
  string line;
  while (getline(file, line)) {
    pairsString.push_back(line);
  }
}

vector<Pair> createPairs(vector<string>& pairsString) {
  vector<Pair> pairs;

  for (auto const &section : pairsString) {
    Pair pair;
    bool firstSectionFilled = false;
    
    for (auto const &character : section) {
      if (character == ',') {
        firstSectionFilled = true;
        continue;
      }

      if (!firstSectionFilled) {
        pair.firstSection.push_back(character);

        continue;
      }

      pair.secondSection.push_back(character);
    }

    pairs.push_back(pair);
  }

  return pairs;
}

int main() {
  string fileName = "./input.txt";
  vector<string> pairsString;

  readFileData(fileName, pairsString);

  vector<Pair> pairs = createPairs(pairsString);

  std::cout << pairs[0].firstSection;

  return 0;
}