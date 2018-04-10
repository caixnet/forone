

/*

  Hardware: 5.0V Arduino Yun
           D2 -> 2
           D3 -> 4
           D4 -> 1
           D5 -> 3
*/
#include <Wire.h>
#include "Keyboard.h"

#define OSX 0
#define WINDOWS 1
#define UBUNTU 2

//
//
#define CHAICODE_POSOHO 1   // 1
#define CHAICODE_QIEHO 2   // 1
#define CHAICODE_TOSOHO 3   // 1
#define CHAICODE_GAHO 4   // 1
//
#define CHAICODE_VOAHO1 231 // BACKSPACE
#define CHAICODE_YOAHO3 232 // BACKSPACE
#define CHAICODE_YOAHO2 241 // DELETE

#define CHAICODE_QAHO 34 // CURSOR RIGHT
#define CHAICODE_QEHO 43 // CURSOR LEFT
#define CHAICODE_QOHO 42 // CURSOR UP
#define CHAICODE_QUHO 24 // CURSOR DOWN
#define CHAICODE_VAHO1 21 // -
#define CHAICODE_XEHO1 12 // +
#define CHAICODE_JUHO1 434  // _
#define CHAICODE_WUHO1 343  // =
#define CHAICODE_VUHO 324  // TAB \t
#define CHAICODE_QEHO1 32  //  /
#define CHAICODE_QUHO1 41   //  "\\"
#define CHAICODE_QIAHO1  31  // |
#define CHAICODE_CEHO1   313  // !
#define CHAICODE_POHO1  4314  // @
#define CHAICODE_POHO2  4134  // @
#define CHAICODE_NOHO1  43124  // #
#define CHAICODE_NOHO2  42134  // #
#define CHAICODE_BOHO1  3412  // $
#define CHAICODE_BOHO2  4321  // $
#define CHAICODE_KOHO1  4324  // %
#define CHAICODE_KOHO2  4234  // %
#define CHAICODE_TOHO1  413  // ^
#define CHAICODE_QOHO1  43214  // &
#define CHAICODE_QOHO2  41234  // &
#define CHAICODE_WOHO1  4132  // *
#define CHAICODE_ZAHO1  4231  // ~
#define CHAICODE_ZEHO1  423  // `
#define CHAICODE_MUHO1  13  // '
#define CHAICODE_BEHO1  314  // "
#define CHAICODE_MAHO1  1313  // ;
#define CHAICODE_BUHO1  2424  // :
#define CHAICODE_JENHO1  432  // <
#define CHAICODE_KEHO1  341  // >
#define CHAICODE_LIOHO1  421  // ?
#define CHAICODE_QONHO1  431  // (
#define CHAICODE_QAHO1  342  // )
#define CHAICODE_PENHO1  4312  // [
#define CHAICODE_FEHO1  3421  // ]
#define CHAICODE_PIENHO1  43123  // {
#define CHAICODE_PIENHO2  43213  // {
#define CHAICODE_VIEHO1  34214  // }
#define CHAICODE_VIEHO2  34124  // }
#define CHAICODE_QASOHO1  32142  // ESC
#define CHAICODE_QASOHO2  32412  // ESC
#define CHAICODE_VUHO1 131 // ,
#define CHAICODE_YUHO1 242 // .
//
#define CHAICODE_RI1 23   // 1
#define CHAICODE_NE1 2143 // 2
#define CHAICODE_CU1 2134 // 3
#define CHAICODE_KU1 234 // 4
#define CHAICODE_DU1 2342 // 5
#define CHAICODE_DU2 2432  // 5
#define CHAICODE_PU1 21341  // 6
#define CHAICODE_PU2 21431  // 6
#define CHAICODE_PU3 24314  // 6
#define CHAICODE_PU4 24134  // 6
#define CHAICODE_GE1 213  // 7
#define CHAICODE_GE2 214  // 7
#define CHAICODE_XU1 2314  // 8
#define CHAICODE_FU1 21324  // 9
#define CHAICODE_FU2 23124  // 9
#define CHAICODE_RO1 213423  // 0
#define CHAICODE_RO2 231243  // 0
#define CHAICODE_RO3 234213  // 0
#define CHAICODE_RO4 243123  // 0
#define CHAICODE_RO5 213243  // 0
#define CHAICODE_RO6 21342  // 0
#define CHAICODE_RO7 24312  // 0

// yiaeou
#define CHAICODE_A1 1431 // a
#define CHAICODE_A2 1341   // a
#define CHAICODE_E1 12432 // e
#define CHAICODE_E2 12342 // e
#define CHAICODE_O1 12431 // o 
#define CHAICODE_O2 13421 // o 
#define CHAICODE_U 1342 // u
#define CHAICODE_I 14 // i
#define CHAICODE_Y 142 // y
// ieaou
#define CHAICODE_IE1 13412 // ie 
#define CHAICODE_IE2 14312 // ie
#define CHAICODE_IA1 14324 // ia 
#define CHAICODE_IA2 14234 // ia 
#define CHAICODE_IO1 24123 // io 
#define CHAICODE_IO2 21423  // io 
#define CHAICODE_IU1 23143 // iu
#define CHAICODE_IU2 23413 // iu
// dwt
#define CHAICODE_DY1 1231 // d
#define CHAICODE_DY2 1321 // d
#define CHAICODE_WY 1432 // w
#define CHAICODE_TY1 1241 // t
#define CHAICODE_TY2 1421 // t
//rn
#define CHAICODE_RY1 124314 // r
#define CHAICODE_RY2 142134 // r
#define CHAICODE_RY3 143124 // r
#define CHAICODE_RY4 134124 // r
#define CHAICODE_RY5 134214 // r
#define CHAICODE_RY6 124134 // r
#define CHAICODE_NY 1324 // n
// mlh
#define CHAICODE_MY1 132142 // m
#define CHAICODE_MY2 142132 // m
#define CHAICODE_MY3 123142 // m
#define CHAICODE_MY4 124132 // m
#define CHAICODE_MY5 132412 // m
#define CHAICODE_MY6 142312 // m
#define CHAICODE_LY 134  // l
#define CHAICODE_HY1 13241 // h
#define CHAICODE_HY2 14231 // h
// vbpf
#define CHAICODE_VY 132 // v
#define CHAICODE_BY1 123143 // b
#define CHAICODE_BY2 134123  // b
#define CHAICODE_BY3 143123  // b
#define CHAICODE_BY4 143213  // b
#define CHAICODE_BY5 132143  // b
#define CHAICODE_BY6 123413  // b
#define CHAICODE_PY1 12413  // p
#define CHAICODE_PY2 14213  // p
#define CHAICODE_FY1 13423  // f
#define CHAICODE_FY2 13243  // f
// sx

#define CHAICODE_SY1 12341 // s
#define CHAICODE_SY2 14321 // s
#define CHAICODE_XY 1423  // x
// gqk
#define CHAICODE_GY 124  // g
#define CHAICODE_QY1 13214  // q
#define CHAICODE_QY2 12314  // q
#define CHAICODE_KY 123  // k
// zjc
#define CHAICODE_ZY 1234 // z
#define CHAICODE_JY 143  // j
#define CHAICODE_CY 1243 // c

//
#define KEY_ENTER 176  // return
#define KEY_SPACE 32 // space
//

bool DEBUG = true;
bool shift_key = false;
bool ctrl_key = false;
int key = 0;
//String forone = String('0');
String forone = "";
String get_code = "";
//String get_code = "";
int chk_time = 0;
const int max_time = 100;
const int min_time = 20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  Keyboard.begin();
  Serial.println("START");
  delay(500);
  
}


void loop() {
  // put your main code here, to run repeatedly:
 //  if (digitalRead(2) == 0) Serial.println(2);
 //  if (digitalRead(3) == 0) Serial.println(4);
 //  if (digitalRead(4) == 0) Serial.println(1);
  // if (digitalRead(5) == 0) Serial.println(3);
//
 //Serial.println("Hello");
 // key = CapaTouch.keyPad();
  //Serial.println(key);


  forone = getChaiCode(key);
  //Serial.println(forone);

  // Serial.println(forone);
  if (chk_time > max_time) {
    //Serial.println(forone);
    chk_time = 0;
    get_code = make_code(forone);

    if ( get_code != "")
    {
      Serial.print(get_code);
      Serial.print(" : ");
    }else{
      //Serial.print(get_code);
      //Serial.print(" @ ");
    }

    //Serial.println("----");
    getKey(get_code);
    //Serial.print(getKey(get_code));
    forone = "";
  } else {
    //Serial.println(chk_time);
  }


  //forone = "";
  //shift_key = false;
  //get_code = "";

  delay(min_time);
  Keyboard.releaseAll();


  //
  // delay(min_time);
}




//
String getChaiCode(char key) {
  if (digitalRead(2) == 0) {
    //Serial.print("2s");
    forone += 2;
  }
  else if (digitalRead(3) == 0) {
    //Serial.print("4s");
    forone += 4;
  }
  else if (digitalRead(5) == 0) {
    //Serial.print("5s");
    forone += 3;
  }
  else if (digitalRead(4) == 0)  {
    //Serial.print("6s");
    forone += 1;
  } else {
    //Serial.print("key:");
    //Serial.println(key);
    chk_time += min_time;
  }
  return forone;
}

//
int getKey(String get_code) {
  char chai_key = -1;
  switch (get_code.toInt()) {
    case CHAICODE_POSOHO: if (!shift_key) {
        Serial.println("Shift");
        shift_key = !shift_key;
      } else {
        shift_key = !shift_key;
      }; break;
    case CHAICODE_QIEHO: Serial.println("Space"); chai_key = KEY_SPACE; break;
    case CHAICODE_TOSOHO: Serial.println("Ctrl");  ctrl_key != ctrl_key; break;
    case CHAICODE_GAHO: Serial.println("Enter"); chai_key = KEY_ENTER; break;

    case CHAICODE_RI1: Serial.println("1"); ctrl_key ? chai_key = KEY_F1 : shift_key ? chai_key = '!' : chai_key = '1'; break;
    case CHAICODE_NE1: Serial.println("2"); ctrl_key ? chai_key = KEY_F2 : shift_key ? chai_key = '@' : chai_key = '2'; break;
    case CHAICODE_CU1: Serial.println("3"); ctrl_key ? chai_key = KEY_F3 : shift_key ? chai_key = '#' : chai_key = '3'; break;
    case CHAICODE_KU1: Serial.println("4"); ctrl_key ? chai_key = KEY_F4 : shift_key ? chai_key = '$' : chai_key = '4'; break;
    case CHAICODE_DU1: Serial.println("5"); ctrl_key ? chai_key = KEY_F5 : shift_key ? chai_key = '%' : chai_key = '5'; break;
    case CHAICODE_DU2: Serial.println("5"); ctrl_key ? chai_key = KEY_F5 : shift_key ? chai_key = '%' : chai_key = '5'; break;
    case CHAICODE_PU1: Serial.println("6"); ctrl_key ? chai_key = KEY_F6 : shift_key ? chai_key = '^' : chai_key = '6'; break;
    case CHAICODE_PU2: Serial.println("6"); ctrl_key ? chai_key = KEY_F6 : shift_key ? chai_key = '^' : chai_key = '6'; break;
    case CHAICODE_PU3: Serial.println("6"); ctrl_key ? chai_key = KEY_F6 : shift_key ? chai_key = '^' : chai_key = '6'; break;
    case CHAICODE_PU4: Serial.println("6"); ctrl_key ? chai_key = KEY_F6 : shift_key ? chai_key = '^' : chai_key = '6'; break;
    case CHAICODE_GE1: Serial.println("7"); ctrl_key ? chai_key = KEY_F7 : shift_key ? chai_key = '&' : chai_key = '7'; break;
    case CHAICODE_GE2: Serial.println("7"); ctrl_key ? chai_key = KEY_F7 : shift_key ? chai_key = '&' : chai_key = '7'; break;
    case CHAICODE_XU1: Serial.println("8"); ctrl_key ? chai_key = KEY_F8 : shift_key ? chai_key = '*' : chai_key = '8';  break;
    case CHAICODE_FU1: Serial.println("9"); ctrl_key ? chai_key = KEY_F9 : shift_key ? chai_key = '(' : chai_key = '9';  break;
    case CHAICODE_FU2: Serial.println("9"); ctrl_key ? chai_key = KEY_F9 : shift_key ? chai_key = '(' : chai_key = '9'; break;
    case CHAICODE_RO1: Serial.println("0"); ctrl_key ? chai_key = KEY_F10 : shift_key ? chai_key = ')' : chai_key = '0'; break;
    case CHAICODE_RO2: Serial.println("0"); ctrl_key ? chai_key = KEY_F10 : shift_key ? chai_key = ')' : chai_key = '0'; break;
    case CHAICODE_RO3: Serial.println("0"); ctrl_key ? chai_key = KEY_F10 : shift_key ? chai_key = ')' : chai_key = '0'; break;
    case CHAICODE_RO4: Serial.println("0"); ctrl_key ? chai_key = KEY_F10 : shift_key ? chai_key = ')' : chai_key = '0'; break;
    case CHAICODE_RO5: Serial.println("0"); ctrl_key ? chai_key = KEY_F10 : shift_key ? chai_key = ')' : chai_key = '0'; break;
    case CHAICODE_RO6: Serial.println("0"); ctrl_key ? chai_key = KEY_F10 : shift_key ? chai_key = ')' : chai_key = '0'; break;
    case CHAICODE_RO7: Serial.println("0"); ctrl_key ? chai_key = KEY_F10 : shift_key ? chai_key = ')' : chai_key = '0'; break;
    //case CHAICODE_RO8: Serial.println("0"); break;
    case CHAICODE_A1: Serial.println("a"); shift_key ? chai_key = 'A' : chai_key = 'a'; break;
    case CHAICODE_A2: Serial.println("a"); shift_key ? chai_key = 'A' : chai_key = 'a'; break;
    case CHAICODE_E1: Serial.println("e"); shift_key ? chai_key = 'E' : chai_key = 'e'; break;
    case CHAICODE_E2: Serial.println("e"); shift_key ? chai_key = 'E' : chai_key = 'e'; break;
    case CHAICODE_O1: Serial.println("o"); shift_key ? chai_key = 'O' : chai_key = 'o'; break;
    case CHAICODE_O2: Serial.println("o"); shift_key ? chai_key = 'O' : chai_key = 'o'; break;
    case CHAICODE_U: Serial.println("u"); shift_key ? chai_key = 'U' : chai_key = 'u'; break;
    case CHAICODE_I: Serial.println("i"); shift_key ? chai_key = 'I' : chai_key = 'i'; break;
    case CHAICODE_Y: Serial.println("y"); shift_key ? chai_key = 'Y' : chai_key = 'y'; break;
    case CHAICODE_IE1: Serial.println("ie"); chai_key = 138; break;
    case CHAICODE_IE2: Serial.println("ie"); chai_key = 138; break;
    case CHAICODE_IA1: Serial.println("ia"); chai_key = 133; break;
    case CHAICODE_IA2: Serial.println("ia"); chai_key = 133; break;
    case CHAICODE_IO1: Serial.println("io"); chai_key = 149; break;
    case CHAICODE_IO2: Serial.println("io"); chai_key = 149; break;
    case CHAICODE_IU1: Serial.println("iu"); chai_key = 151; break;
    case CHAICODE_IU2: Serial.println("iu"); chai_key = 151; break;
    case CHAICODE_DY1: Serial.println("d"); shift_key ? chai_key = 'D' : chai_key = 'd'; break;
    case CHAICODE_DY2: Serial.println("d"); shift_key ? chai_key = 'D' : chai_key = 'd'; break;
    case CHAICODE_WY: Serial.println("w"); shift_key ? chai_key = 'W' : chai_key = 'w'; break;
    case CHAICODE_TY1: Serial.println("t"); shift_key ? chai_key = 'T' : chai_key = 't';  break;
    case CHAICODE_TY2: Serial.println("t"); shift_key ? chai_key = 'T' : chai_key = 't'; break;
    case CHAICODE_RY1: Serial.println("r"); shift_key ? chai_key = 'R' : chai_key = 'r'; break;
    case CHAICODE_RY2: Serial.println("r"); shift_key ? chai_key = 'R' : chai_key = 'r'; break;
    case CHAICODE_RY3: Serial.println("r"); shift_key ? chai_key = 'R' : chai_key = 'r'; break;
    case CHAICODE_RY4: Serial.println("r"); shift_key ? chai_key = 'R' : chai_key = 'r'; break;
    case CHAICODE_RY5: Serial.println("r"); shift_key ? chai_key = 'R' : chai_key = 'r'; break;
    case CHAICODE_RY6: Serial.println("r"); shift_key ? chai_key = 'R' : chai_key = 'r'; break;
    case CHAICODE_NY: Serial.println("n"); shift_key ? chai_key = 'N' : chai_key = 'n'; break;
    case CHAICODE_MY1: Serial.println("m"); shift_key ? chai_key = 'M' : chai_key = 'm'; break;
    case CHAICODE_MY2: Serial.println("m"); shift_key ? chai_key = 'M' : chai_key = 'm'; break;
    case CHAICODE_MY3: Serial.println("m"); shift_key ? chai_key = 'M' : chai_key = 'm'; break;
    case CHAICODE_MY4: Serial.println("m"); shift_key ? chai_key = 'M' : chai_key = 'm'; break;
    case CHAICODE_MY5: Serial.println("m"); shift_key ? chai_key = 'M' : chai_key = 'm'; break;
    case CHAICODE_MY6: Serial.println("m"); shift_key ? chai_key = 'M' : chai_key = 'm'; break;
    case CHAICODE_LY: Serial.println("l"); shift_key ? chai_key = 'L' : chai_key = 'l'; break;

    case CHAICODE_HY1: Serial.println("h"); shift_key ? chai_key = 'H' : chai_key = 'h'; break;
    case CHAICODE_HY2: Serial.println("h"); shift_key ? chai_key = 'H' : chai_key = 'h'; break;
    case CHAICODE_VY: Serial.println("v"); shift_key ? chai_key = 'V' : chai_key = 'v'; break;
    case CHAICODE_BY1: Serial.println("b"); shift_key ? chai_key = 'B' : chai_key = 'b'; break;
    case CHAICODE_BY2: Serial.println("b"); shift_key ? chai_key = 'B' : chai_key = 'b'; break;
    case CHAICODE_BY3: Serial.println("b"); shift_key ? chai_key = 'B' : chai_key = 'b'; break;
    case CHAICODE_BY4: Serial.println("b"); shift_key ? chai_key = 'B' : chai_key = 'b'; break;
    case CHAICODE_BY5: Serial.println("b"); shift_key ? chai_key = 'B' : chai_key = 'b'; break;
    case CHAICODE_BY6: Serial.println("b"); shift_key ? chai_key = 'B' : chai_key = 'b'; break;
    case CHAICODE_PY1: Serial.println("p"); shift_key ? chai_key = 'P' : chai_key = 'p'; break;
    case CHAICODE_PY2: Serial.println("p"); shift_key ? chai_key = 'P' : chai_key = 'p'; break;
    case CHAICODE_FY1: Serial.println("f"); shift_key ? chai_key = 'F' : chai_key = 'f'; break;
    case CHAICODE_FY2: Serial.println("f"); shift_key ? chai_key = 'F' : chai_key = 'f'; break;
    case CHAICODE_SY1: Serial.println("s"); shift_key ? chai_key = 'S' : chai_key = 's'; break;
    case CHAICODE_SY2: Serial.println("s"); shift_key ? chai_key = 'S' : chai_key = 's'; break;
    case CHAICODE_XY: Serial.println("x"); shift_key ? chai_key = 'X' : chai_key = 'x'; break;
    case CHAICODE_GY: Serial.println("g"); shift_key ? chai_key = 'G' : chai_key = 'g';  break;
    case CHAICODE_QY1: Serial.println("q"); shift_key ? chai_key = 'Q' : chai_key = 'q';  break;
    case CHAICODE_QY2: Serial.println("q"); shift_key ? chai_key = 'Q' : chai_key = 'q';  break;
    case CHAICODE_KY: Serial.println("k"); shift_key ? chai_key = 'K' : chai_key = 'k';  break;
    case CHAICODE_ZY: Serial.println("z"); shift_key ? chai_key = 'Z' : chai_key = 'z';  break;
    case CHAICODE_JY: Serial.println("j"); shift_key ? chai_key = 'J' : chai_key = 'j';  break;
    case CHAICODE_CY: Serial.println("c"); shift_key ? chai_key = 'C' : chai_key = 'c';  break;
    //
    case CHAICODE_VOAHO1: Serial.println("bs"); shift_key ? chai_key = 178 : chai_key = KEY_BACKSPACE;  break;
    case CHAICODE_YOAHO2: Serial.println("del"); shift_key ? chai_key = 212 : chai_key = KEY_DELETE;  break;
    case CHAICODE_YOAHO3: Serial.println("bs1"); shift_key ? chai_key = 178 : chai_key = KEY_BACKSPACE;  break;
    case CHAICODE_QAHO: Serial.println("rt"); shift_key ? chai_key = KEY_END : chai_key = KEY_RIGHT_ARROW;  break;
    case CHAICODE_QEHO: Serial.println("lt"); shift_key ? chai_key = KEY_HOME : chai_key = KEY_LEFT_ARROW;  break;
    case CHAICODE_QOHO: Serial.println("up"); shift_key ? chai_key = KEY_PAGE_UP : chai_key = KEY_UP_ARROW;  break;
    case CHAICODE_QUHO: Serial.println("dn"); shift_key ? chai_key = KEY_PAGE_DOWN : chai_key = KEY_DOWN_ARROW;  break;
    case CHAICODE_VUHO: Serial.println("tab"); shift_key ? chai_key = 179 : chai_key = KEY_TAB;  break;
    //
    case CHAICODE_VAHO1: Serial.println("-"); shift_key ? chai_key = '-' : chai_key = '-';  break;
    case CHAICODE_XEHO1: Serial.println("+"); shift_key ? chai_key = '+' : chai_key = '+';  break;
    case CHAICODE_JUHO1: Serial.println("_"); shift_key ? chai_key = '_' : chai_key = '_';  break;
    case CHAICODE_WUHO1: Serial.println("="); shift_key ? chai_key = '=' : chai_key = '=';  break;
    case CHAICODE_QEHO1: Serial.println("/"); shift_key ? chai_key = '/' : chai_key = '/';  break;
    case CHAICODE_QUHO1: Serial.println("\\"); shift_key ? chai_key = '\\' : chai_key = '\\';  break;
    case CHAICODE_QIAHO1: Serial.println("|"); shift_key ? chai_key = '|' : chai_key = '|';  break;
    case CHAICODE_CEHO1: Serial.println("!"); shift_key ? chai_key = '!' : chai_key = '!';  break;
    case CHAICODE_POHO1: Serial.println("@"); shift_key ? chai_key = '@' : chai_key = '@';  break;
    case CHAICODE_POHO2: Serial.println("@"); shift_key ? chai_key = '@' : chai_key = '@';  break;
    case CHAICODE_NOHO1: Serial.println("#"); shift_key ? chai_key = '#' : chai_key = '#';  break;
    case CHAICODE_NOHO2: Serial.println("#"); shift_key ? chai_key = '#' : chai_key = '#';  break;
    case CHAICODE_BOHO1: Serial.println("$"); shift_key ? chai_key = '$' : chai_key = '$';  break;
    case CHAICODE_BOHO2: Serial.println("$"); shift_key ? chai_key = '$' : chai_key = '$';  break;
    case CHAICODE_KOHO1: Serial.println("%"); shift_key ? chai_key = '%' : chai_key = '%';  break;
    case CHAICODE_KOHO2: Serial.println("%"); shift_key ? chai_key = '%' : chai_key = '%';  break;
    case CHAICODE_TOHO1: Serial.println("^"); shift_key ? chai_key = '^' : chai_key = '^';  break;
    case CHAICODE_QOHO1: Serial.println("&"); shift_key ? chai_key = '&' : chai_key = '&';  break;
    case CHAICODE_QOHO2: Serial.println("&"); shift_key ? chai_key = '&' : chai_key = '&';  break;
    case CHAICODE_WOHO1: Serial.println("*"); shift_key ? chai_key = '*' : chai_key = '*';  break;
    case CHAICODE_ZAHO1: Serial.println("~"); shift_key ? chai_key = '~' : chai_key = '~';  break;
    case CHAICODE_ZEHO1: Serial.println("`"); shift_key ? chai_key = '`' : chai_key = '`';  break;
    case CHAICODE_MUHO1: Serial.println("'"); shift_key ? chai_key = '\'' : chai_key = '\'';  break;
    case CHAICODE_BEHO1: Serial.println("\""); shift_key ? chai_key = '"' : chai_key = '"';  break;
    case CHAICODE_VUHO1: Serial.println(","); shift_key ? chai_key = ',' : chai_key = ',';  break;
    case CHAICODE_YUHO1: Serial.println("."); shift_key ? chai_key = '.' : chai_key = '.';  break;
    case CHAICODE_JENHO1: Serial.println("<"); shift_key ? chai_key = '<' : chai_key = '<';  break;
    case CHAICODE_KEHO1: Serial.println(">"); shift_key ? chai_key = '>' : chai_key = '>';  break;
    case CHAICODE_QONHO1: Serial.println("("); shift_key ? chai_key = '(' : chai_key = '(';  break;
    case CHAICODE_QAHO1: Serial.println(")"); shift_key ? chai_key = ')' : chai_key = ')';  break;
    case CHAICODE_PENHO1: Serial.println("["); shift_key ? chai_key = '[' : chai_key = '[';  break;
    case CHAICODE_FEHO1: Serial.println("]"); shift_key ? chai_key = ']' : chai_key = ']';  break;
    case CHAICODE_PIENHO1: Serial.println("{"); shift_key ? chai_key = '{' : chai_key = '{';  break;
    case CHAICODE_VIEHO1: Serial.println("}"); shift_key ? chai_key = '}' : chai_key = '}';  break;
     case CHAICODE_PIENHO2: Serial.println("{"); shift_key ? chai_key = '{' : chai_key = '{';  break;
    case CHAICODE_VIEHO2: Serial.println("}"); shift_key ? chai_key = '}' : chai_key = '}';  break;
    case CHAICODE_QASOHO1: Serial.println("ESC"); shift_key ? chai_key = KEY_ESC : chai_key = KEY_ESC;  break;
    case CHAICODE_QASOHO2: Serial.println("ESC"); shift_key ? chai_key = KEY_ESC : chai_key = KEY_ESC;  break;
    case CHAICODE_LIOHO1: Serial.println("?"); shift_key ? chai_key = '?' : chai_key = '?';  break;
    case CHAICODE_MAHO1: Serial.println(";"); shift_key ? chai_key = ';' : chai_key = ';';  break;
    case CHAICODE_BUHO1: Serial.println(":"); shift_key ? chai_key = ':' : chai_key = ':';  break;
    
    default: ;//Serial.println(get_code.toInt());
      break;
  }
  //Keyboard.press(chai_key);
  if (chai_key != -1) Keyboard.press(chai_key); //Serial.println(chai_key);
  return chai_key;
}

//
String make_code(String str) {
  if (str == "") return "";
  if (str.length() < 2) {
    return str;
  }
  String str_bufer = "";
  str_bufer = str.charAt(0);

  for (int i = 1; i < str.length() - 1; i++) {
    if (str.charAt(i - 1) != str.charAt(i)) {
      str_bufer += str.charAt(i);
    }
  }
  return str_bufer;
}

