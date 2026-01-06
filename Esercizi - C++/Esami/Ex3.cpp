#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <math.h>


struct Domanda{
  int nq;
  char abc[20];
};


int fget_answer(const char *filename, Domanda idStud[], Domanda rispoStud[][20], Domanda rispo[][20], int len, Domanda &lens) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error opening file " << filename << std::endl;
    return -1;
  }
  std::string line;
  int count = 0;
  while (count < len && std::getline(file, line)) {
    int x;
    char y[20];
    std::istringstream iss(line);
    if (iss >> x >> y) {
      if (count == 0) {
        strcpy(rispo[count][0].abc, y);
        lens.nq = x;
        count++;
      }
      else {
        idStud[count - 1].nq = x;
        strcpy(rispoStud[count - 1][0].abc, y);
        count++;
      }
    }
  }
  for(int i = 0; i < count - 1; i++) {
    std::cout << rispoStud[i]->abc <<  "  " << idStud[i].nq << std::endl;
  }
  file.close();
  return count;
}

void get_wrong(Domanda rispotStud[][20],  int len,  Domanda rispota_giusta[][20], float Get_Wrong[]) {
  for (int i = 0; i < len; i++) {
    for (int j = 0; rispota_giusta[0]->abc[j] != '\0'; j++) {
      if (rispota_giusta[0]->abc[j] != rispotStud[i]->abc[j]) {
        Get_Wrong[j] += 1;
      }
    }
  }
  for (int j = 0; rispota_giusta[0]->abc[j] != '\0'; j++) {
    Get_Wrong[j] =  floor((Get_Wrong[j] / len) * 100);
  }
}

void fwrite_report(const char *fileR, Domanda len, Domanda rispott[][20], float Wrong[]) {
  std::ofstream file(fileR);
  if (!file.is_open()) {
    std::cerr << "Error opening file " << fileR << std::endl;
  }
  file << "Exam Report" << std::endl;
  file << "Question ";
  for (int i = 0; i < len.nq; i++) {
      file << i + 1 << " ";
  }
  file << std::endl;
  file << "Answer ";
  for (int i = 0; i < len.nq; i++) {
    for (int j = 0; rispott[i][0].abc[j] != '\0'; j++) {
      file << rispott[i][0].abc[j] << " ";
    }
  }
  file << std::endl;
  file << "Wrong(%) ";
  for (int i = 0; i < len.nq; i++) {
    file << Wrong[i] << " ";
  }
  file.close();
}


int main() {
  constexpr int MAX_RESULT = 50;
  Domanda id_students[MAX_RESULT];
  Domanda answers[MAX_RESULT][20];
  Domanda coor_answers[MAX_RESULT][20];
  Domanda len_answers;
  float GEt_wrong[MAX_RESULT];
  int len_students;

  len_students = fget_answer("C:/Users/Cliente/Downloads/file_essempio3.txt", id_students, answers, coor_answers, MAX_RESULT, len_answers);
  len_students--;
  get_wrong(answers, len_students, coor_answers, GEt_wrong);
  fwrite_report("report.txt", len_answers, coor_answers, GEt_wrong);
  return 0;
}