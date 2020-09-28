#include "subject.h"
#include <string.h>
#include <stdlib.h>

void Subj::readSubject() {
  printf("Name: ");
  cin >> name;

  printf("Professor name: ");
  cin >> professorName;

  printf("ID: ");
  cin >> ID;
  
  printf("NRC: ");
  cin >> NRC;

  string days[7] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
  };

  printf("Select available days [y/n]\n");
  
  for (int i = 0; i < 7; ++i) {
    cout << days[i] << "? ";
    char op;
    cin >> op;
    if (op == 'y')
      availableDays |= (1 << i);
  }
  
  printf("Start time [hhmm]: ");
  cin >> startTime;
  
  printf("End time [hhmm]: ");
  cin >> endTime;
  
  printf("Section: ");
  cin >> section;
}

void Subj::setName(const string &name) {
  this->name = name;
}

void Subj::setID(const string &ID) {
  this->ID = ID; 
}

void Subj::setNRC(const string &NRC) {
  this->NRC = NRC;
}

void Subj::setProfessorName(const string &professorName) {
  this->professorName = professorName;
}

void Subj::setAvailableDays(int availableDays) {
  this->availableDays = availableDays;
}

void Subj::setStartTime(const string &startTime) {
  this->startTime = startTime;
}

void Subj::setEndTime(const string &endTime) {
  this->endTime = endTime;
}

void Subj::setSection(const string &section) {
  this->section = section;
}


string Subj::getName() {
  return name;
}

string Subj::getID() {
  return ID;
}

string Subj::getNRC() {
  return NRC;
}

string Subj::getProfessorName() {
  return professorName;
}

int Subj::getAvailableDays() {
  return availableDays;
}

string Subj::getStartTime() {
  return startTime;
}

string Subj::getEndTime() {
  return endTime;
}

string Subj::getSection() {
  return section;
}

