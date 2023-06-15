#include "..\include\info.h"

#include <iomanip>
#include "..\include\show.h"

Score::Score() {
  mathScore = languageScore = politicsScore = majorScore = 0;
  totalScore = 0;
}

Score::Score(int ms, int ls, int ps, int mjs) {
  mathScore = ms;
  languageScore = ls;
  politicsScore = ps;
  majorScore = mjs;

  totalScore = ms + ls + ps + mjs;
}

void Score::setMathScore(int x) {
  if (x < 0 || x > 150) {
    throw "Math score is out of range.";
  }
  mathScore = x;
  totalScore = mathScore + languageScore + politicsScore + majorScore;
}

void Score::setLanguageScore(int x) {
  if (x < 0 || x > 100) {
    throw "Language score is out of range.";
  }
  languageScore = x;
  totalScore = mathScore + languageScore + politicsScore + majorScore;
}

void Score::setPoliticsScore(int x) {
  if (x < 0 || x > 100) {
    throw "Politics score is out of range.";
  }
  politicsScore = x;
  totalScore = mathScore + languageScore + politicsScore + majorScore;
}

void Score::setMajorScore(int x) {
  if (x < 0 || x > 150) {
    throw "Major score is out of range.";
  }
  majorScore = x;
  totalScore = mathScore + languageScore + politicsScore + majorScore;
}

void Score::setTotalScore(int x) {
  if (x < 0 || x > 500) {
    throw "Total score is out of range.";
  }
  totalScore = x;
}

int Score::getMathScore() const {
  return mathScore;
}

int Score::getLanguageScore() const {
  return languageScore;
}

int Score::getPoliticsScore() const {
  return politicsScore;
}

int Score::getMajorScore() const {
  return majorScore;
}

int Score::getTotalScore() const {
  return totalScore;
}

bool Score::operator==(const Score& rhs) const {
  return (mathScore == rhs.mathScore) && (languageScore == rhs.languageScore) 
      && (politicsScore >= rhs.politicsScore) && (majorScore == rhs.majorScore);
}

bool Score::operator!=(const Score& rhs) const {
  return !(*this == rhs);
}

Score& Score::operator=(const Score& rhs) {
  mathScore = rhs.mathScore;
  languageScore = rhs.languageScore;
  politicsScore = rhs.politicsScore;
  majorScore = rhs.majorScore;
  totalScore = rhs.totalScore;
  return *this;
}

bool Score::isAccess(const Score& stand) const {
  if (stand.totalScore > totalScore) {
    return false;
  }
  if (stand.mathScore > mathScore) {
    return false;
  }
  if (stand.politicsScore > politicsScore) {
    return false;
  }
  if (stand.languageScore > languageScore) {
    return false;
  }
  if (stand.majorScore > majorScore) {
    return false;
  }
  return true;
}

std::istream& operator>>(std::istream& is, Score& sc) {
  is >> sc.mathScore >> sc.languageScore >> sc.politicsScore >> sc.majorScore;
  sc.totalScore = sc.mathScore + sc.languageScore + sc.politicsScore + sc.majorScore;
  return is;
}

StudInfo::StudInfo() {
  name = id = major = "";
  isF = false;
  sc = Score(0, 0, 0, 0);
}

StudInfo::StudInfo(std::string n, std::string i, std::string m, bool f, Score s) {
  name = n;
  id = i;
  major = m;
  isF = f;
  sc = s;
}

bool StudInfo::operator==(const StudInfo& rhs) const {
  return (name == rhs.name) && (id == rhs.id) && (major == rhs.major) && (isF == rhs.isF) && (sc == rhs.sc);
}

bool StudInfo::operator!=(const StudInfo& rhs) const {
  return !(*this == rhs);
}

StudInfo& StudInfo::operator=(const StudInfo& rhs) {
  name = rhs.name;
  id = rhs.id;
  major = rhs.major;
  isF = rhs.isF;
  sc = rhs.sc;
  return *this;
}

std::string StudInfo::getName() const {
  return name;
}

std::string StudInfo::getId() const {
  return id;
}

std::string StudInfo::getMajor() const {
  return major;
}

bool StudInfo::getIsF() const {
  return isF;
}

Score StudInfo::getScore() const {
  return sc;
}

void StudInfo::setName(std::string n) {
  name = n;
}

void StudInfo::setId(std::string i) {
  id = i;
}

void StudInfo::setMajor(std::string m) {
  major = m;
}

void StudInfo::setIsF(bool f) {
  isF = f;
}

void StudInfo::setScore(Score s) {
  sc = s;
}

bool StudInfo::isAccess(const Score& stand) const {
  return sc.isAccess(stand);
}

void StudInfo::setScore(std::string type, int score) {
  if (type == "math") {
    sc.setMathScore(score);
  } else if (type == "language") {
    sc.setLanguageScore(score);
  } else if (type == "politics") {
    sc.setPoliticsScore(score);
  } else {
    sc.setMajorScore(score);
  }
}

std::istream& operator>>(std::istream& is, StudInfo& si) {
  std::string isFR;
  is >> si.name >> si.id >> si.major >> isFR >> si.sc;
  if (isFR == "true") {
    si.isF = true;
  } else {
    si.isF = false;
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const StudInfo& si) {
  os << std::left << std::setw(BOARD_SIZE) << si.name << 
        std::left << std::setw(BOARD_SIZE) << si.id << 
        std::left << std::setw(BOARD_SIZE * 2) << si.major << 
        std::left << std::setw(BOARD_SIZE) << (si.isF ? "true" : "false") << 
        std::left << std::setw(BOARD_SIZE) << si.sc.getMathScore() << 
        std::left << std::setw(BOARD_SIZE) << si.sc.getLanguageScore() << 
        std::left << std::setw(BOARD_SIZE) << si.sc.getPoliticsScore() << 
        std::left << std::setw(BOARD_SIZE) << si.sc.getMajorScore();
  return os;
}
