#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <system_error>
#include <vector>

using namespace std;

class Pair {
public:
  int start;
  int end;
};

class Section {
public:
  Pair first;
  Pair second;
};

void readFileData(string &fileName, vector<string> &pairsString) {
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

vector<Section> readPairs(vector<string> &pairsString) {
  vector<Section> sections;

  for (auto const &sectionString : pairsString) {
    Pair pair;
    Section section;
    string firstSection;
    string secondSection;
    bool firstSectionFilled = false;

    for (auto const &character : sectionString) {
      if (character == ',') {
        firstSectionFilled = true;
        continue;
      }

      if (!firstSectionFilled) {
        firstSection.push_back(character);

        continue;
      }

      secondSection.push_back(character);
    }

    string sectionValue;

    for (int i = 0; i <= firstSection.size(); i++) {
      char character = firstSection[i];

      if (character == '-') {
        int convertedSectionValue = atoi(sectionValue.c_str());
        pair.start = convertedSectionValue;
        sectionValue = "";
        continue;
      }

      sectionValue.push_back(character);

      if (i == firstSection.size() - 1) {
        int convertedSectionValue = atoi(sectionValue.c_str());
        pair.end = convertedSectionValue;
        sectionValue = "";
        continue;
      }
    }

    section.first = pair;
    sectionValue = "";

    for (int i = 0; i <= secondSection.size(); i++) {
      char character = secondSection[i];

      if (character == '-') {
        int convertedSectionValue = atoi(sectionValue.c_str());
        pair.start = convertedSectionValue;
        sectionValue = "";
        continue;
      }

      sectionValue.push_back(character);

      if (i == secondSection.size() - 1) {
        int convertedSectionValue = atoi(sectionValue.c_str());
        pair.end = convertedSectionValue;
        sectionValue = "";
        continue;
      }
    }

    section.second = pair;

    sections.push_back(section);
  }

  return sections;
}

int fullyContainsCount(const vector<Section> &sections) {
  int fullyContains = 0;

  for (auto const &section : sections) {
    Pair firstPair = section.first;
    cout << firstPair.start << "\n";
    cout << firstPair.end << "\n\n";
    Pair secondPair = section.second;
    cout << secondPair.start << "\n";
    cout << secondPair.end << "\n\n\n";
    vector<int> firstPairValues;
    vector<int> secondPairValues;

    for (int i = firstPair.start; i <= firstPair.end; i++) {
      firstPairValues.push_back(i);
    }

    for (int i = secondPair.start; i <= secondPair.end; i++) {
      secondPairValues.push_back(i);
    }

    bool contains = false;

    if (firstPair.start <= secondPair.start && firstPair.end >= secondPair.end) {
      for (int i = 0; i < secondPairValues.size(); i++) {
        int secondValue = secondPairValues[i];
        for (int j = 0; firstPairValues[j] <= secondPair.end; j++) {
          int firstValue = firstPairValues[j];
          if (firstValue < secondPair.start) {
            continue;
          }

          if (firstValue == secondValue) {
            contains = true;
            break;
          }
        }
      }
    }

    if (secondPair.start <= firstPair.start && secondPair.end >= firstPair.end) {
      for (int i = 0; i < firstPairValues.size(); i++) {
        int firstValue = firstPairValues[i];
        for (int j = 0; secondPairValues[j] <= firstPair.end; j++) {
          int secondValue = secondPairValues[j];
          if (secondValue < firstPair.start) {
            continue;
          }

          if (secondValue == firstValue) {
            contains = true;
            break;
          }
        }
      }
    }

    if (contains) {
      fullyContains++;
    }
  }

  return fullyContains;
}

int main() {
  string fileName = "./input.txt";
  vector<string> pairsString;

  readFileData(fileName, pairsString);

  vector<Section> sections = readPairs(pairsString);

  int fullyContains = fullyContainsCount(sections);

  cout << fullyContains << "\n";

  return 0;
}