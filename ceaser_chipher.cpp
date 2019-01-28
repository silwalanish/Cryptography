#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <sstream>

using namespace std;

namespace ASK{

  class CeaserChipher{
    private:
      static char Encrypt(char p, int key){
        return ((p - 'A' + key) % 26) + 'A';
      }

      static char Decrypt(char c, int key){
        return ((c - 'A' + (26 - key)) % 26) + 'A';
      }
    public:
      static string EncryptText(string plainText, int key)
      {
        string chipher;
        transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);
        for (size_t i = 0; i < plainText.length(); i++) {
          if(plainText[i] >= 'A' && plainText[i] <= 'Z'){
            chipher += Encrypt(plainText[i], key);
          }else{
            chipher += plainText[i];
          }
        }
        return chipher;
      }

      static string DecryptChiper(string chiper, int key)
      {
        string plainText;
        transform(chiper.begin(), chiper.end(), chiper.begin(), ::toupper);
        for (size_t i = 0; i < chiper.length(); i++) {
          if(chiper[i] >= 'A' && chiper[i] <= 'Z'){
            plainText += Decrypt(chiper[i], key);
          }else{
            plainText += chiper[i];
          }
        }
        return plainText;
      }
  };
  
};

void MainLoop();

void ShowMainMenu();
void EncryptScreen();
void DecryptScreen();
void GoodByeScreen();

void ScreenChooser();

int ReadChoice();
bool TryAgain();

int main(int argc, char const *argv[]) {
  MainLoop();
  return 0;
}

void MainLoop(){
  do{
    ShowMainMenu();
    ScreenChooser();
  }while(TryAgain());
}

void ScreenChooser(){
  switch (ReadChoice()) {
    case 1:
      EncryptScreen();
      break;
    case 2:
      DecryptScreen();
      break;
    case 3:
      exit(0);
      break;
    default:
      cout << "Enter a valid choice." << endl;
  }
}

void ShowMainMenu(){
  system("CLS");
  cout << "--------------------" << " Ceaser's Chiper Implementation " << "--------------------" << endl;
  cout << "1. Encrypt Text" << endl;
  cout << "2. Decrypt Text" << endl;
  cout << "3. Quit" << endl;
}

void EncryptScreen(){
  string temp;
  string plainText;
  int key;
  system("CLS");
  cout << "--------------------" << " Encrypt Text " << "--------------------" << endl;
  cout << "Enter text to encrypt: ";
  cin.ignore();
  getline(cin, plainText);
  do{
    cout << "Enter valid key: ";
    cin >> temp;
    stringstream(temp) >> key;
  }while(key < 1 || key > 25);

  cout << "Chiper Text is: " << ASK::CeaserChipher::EncryptText(plainText, key) << endl;
}

void DecryptScreen(){
  string chiper;
  string temp;
  int key;
  system("CLS");
  cout << "--------------------" << " Decrypt Chiper " << "--------------------" << endl;
  cout << "Enter chiper text to decrypt: ";
  cin.ignore();
  getline(cin, chiper);
  do{
    cout << "Enter valid key: ";
    cin >> temp;
    stringstream(temp) >> key;
  }while(key < 1 || key > 25);

  cout << "Decrypted Text is: " << ASK::CeaserChipher::DecryptChiper(chiper, key) << endl;
}

int ReadChoice(){
  string temp;
  int choice = 0;
  do{
    cout >> "> ";
    cin >> temp;
    stringstream(temp) >> choice;
  }while(choice < 1 || choice > 3);
  return choice;
}

bool TryAgain()
{
  char ch;
  cout << "Continue (Y/N)?";
  cin >> ch;

  return (ch != 'N' && ch != 'n');
}
