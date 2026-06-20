#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

struct LyricWord {
  const char* word;
  unsigned long showAt;
  bool newLine;
};

LyricWord words[] = {
  {"Mahal,",     0UL,      false},
  {"ikaw",       979UL,    false},
  {"ang",        1693UL,   true},
  {"uuwian",     1693UL,   true},
  {"At",         6543UL,   false},
  {"kung",       7323UL,   false},
  {"umabot",     8079UL,   true},
  {"man",        9006UL,   false},
  {"sa",         9006UL,   false},
  {"dulo",       10329UL,  true},
  {"At",         11583UL,  false},
  {"tatanda",    11704UL,  false},
  {"na",         13554UL,  true},
  {"tayo",       14632UL,  true},
  {"Ikaw",       16188UL,  false},
  {"pa",         16847UL,  false},
  {"rin",        16847UL,  false},
  {"ang",        17951UL,  true},
  {"uuwian",     18777UL,  true},
  {"At",         22863UL,  false},
  {"kahit",      23043UL,  false},
  {"na",         23322UL,  true},
  {"maghirap",   24102UL,  false},
  {"tayo",       26051UL,  true},
  {"Di",         28074UL,  false},
  {"na",         28835UL,  false},
  {"magbabago",  29381UL,  true},
  {"ikaw",       33344UL,  false},
  {"pa",         34592UL,  false},
  {"rin",        34592UL,  false},
  {"ang",        35791UL,  true},
  {"uuwian",     36634UL,  true},
};

int totalWords = 32;
int currentWord = -1;
unsigned long startTime;
String row0 = "";
String row1 = "";
bool onRow1 = false;
bool pendingNewSlide = false; 

void displayRows() {
  String padded0 = row0;
  String padded1 = row1;
  while (padded0.length() < 16) padded0 += " ";
  while (padded1.length() < 16) padded1 += " ";
  lcd.setCursor(0, 0);
  lcd.print(padded0);
  lcd.setCursor(0, 1);
  lcd.print(padded1);
}

void addWord(const char* word, bool newLine) {
  String w = String(word);

  if (pendingNewSlide) {
    lcd.clear();
    row0 = "";
    row1 = "";
    onRow1 = false;
    pendingNewSlide = false;
  }

  if (!onRow1) {
    if (row0.length() == 0) {
      row0 = w;
    } else {
      row0 += " " + w;
    }
    displayRows();
    if (newLine) onRow1 = true;
  } else {
    if (row1.length() == 0) {
      row1 = w;
    } else {
      row1 += " " + w;
    }
    displayRows();
    if (newLine) pendingNewSlide = true; 
  }
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Libu-Libong");
  lcd.setCursor(3, 1);
  lcd.print("Buwan");
  delay(3000);
  lcd.clear();
  startTime = millis();
}

void loop() {
  unsigned long elapsed = millis() - startTime;
  if (currentWord + 1 < totalWords) {
    if (elapsed >= words[currentWord + 1].showAt) {
      currentWord++;
      addWord(words[currentWord].word, words[currentWord].newLine);
    }
  }
}