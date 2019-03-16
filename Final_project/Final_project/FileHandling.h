#pragma once

#include "Persoana.h"
#include <fstream>
#include <string>
#include <sstream>

#define PERSOANE_FILE "PERSOANE.TXT"
#define STUDENTI_FILE "STUDENTI.TXT"
#define PROFESORI_FILE "PROFESORI.TXT"

int getPersoaneNr(std::string);
int* getStudentiId(void);