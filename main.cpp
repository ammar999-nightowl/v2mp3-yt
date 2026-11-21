#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>

using namespace std;

//now lets make global variables
string cmd;
string url;
//now lets make the main interface
// via a void function and also a void welcome function
void welcome()
{
  const char* wlcome = R"(__     ______  __  __ ____ _____    __   _______
\ \   / /___ \|  \/  |  _ \___ /    \ \ / /_   _|
 \ \ / /  __) | |\/| | |_) ||_ \ ____\ V /  | |
  \ V /  / __/| |  | |  __/___) |_____| |   | |
   \_/  |_____|_|  |_|_|  |____/      |_|   |_|
)";
cout << wlcome << endl;
cout << "BY AMMAR" << endl;
}
void interface()
{
  welcome();
  while(true)
  {
  //now the cmd while loop
  cout << "input-url> ";
  getline(cin, url);
  if(url.empty() || url.find_first_of(";&|`$><\n\r\"'\\") != string::npos)
  {
    cout << "error : invalid input or unsafe url\n";
    continue;
  }
  if (url == "exit")
  {
    break;
  }
  if (url == "help")
  {
    cout << "input the url to download songs via youtube\n";
    cout << "thats it. who needs help for that ?\n";
    continue;
  }
  cmd = "yt-dlp -x --audio-format mp3 --audio-quality 0 " + url;
  system(cmd.c_str());
 }
}

int main()
{
  interface();
  return 0;
}
