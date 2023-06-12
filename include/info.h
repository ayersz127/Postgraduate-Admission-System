#ifndef PPTAS_INFO_H
#define PPTAS_INFO_H

#include <cstring>
#include <iostream>

class Score {
private:
  int mathScore;
  int languageScore;
  int politicsScore;
  int majorScore;

  int totalScore;

public:
  Score();
  Score(int, int, int, int);

  void setMathScore(int);
  void setLanguageScore(int);
  void setPoliticsScore(int);
  void setMajorScore(int);
  void setTotalScore(int);

  int getMathScore() const;
  int getLanguageScore() const;
  int getPoliticsScore() const;
  int getMajorScore() const;
  int getTotalScore() const;

  bool operator==(const Score&) const;
  bool operator!=(const Score&) const;

  Score& operator=(const Score&);

  bool isAccess(const Score&) const;

  friend std::istream& operator>>(std::istream&, Score&);
};

class StudInfo {
private:
  std::string name;
  std::string id;
  std::string major;
  bool isF;

  Score sc;

public:
  StudInfo();
  StudInfo(std::string, std::string, std::string, bool, Score);

  bool operator==(const StudInfo&) const;
  bool operator!=(const StudInfo&) const;

  StudInfo& operator=(const StudInfo&);

  std::string getName() const;
  std::string getId() const;
  std::string getMajor() const;
  bool getIsF() const;
  Score getScore() const;

  void setName(std::string);
  void setId(std::string);
  void setMajor(std::string);
  void setIsF(bool);
  void setScore(Score);

  bool isAccess(const Score&) const;

  void setScore(std::string, int);

  friend std::istream& operator>>(std::istream&, StudInfo&);

  friend std::ostream& operator<<(std::ostream&, const StudInfo&);
};

#endif