#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

const char g_szClassName[] = "CalculatorWindow";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_LBUTTONDOWN: // if the user clicks on the left mouse button
        printf("Left mouse button clicked\n");
        break;

    case WM_CLOSE: // if the user clicks the close button
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY: // if the user closes the window
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize = sizeof(WNDCLASSEX);                // size of structure
    wc.style = 0;                                  // class style
    wc.lpfnWndProc = WndProc;                      // pointer to window procedure
    wc.cbClsExtra = 0;                             // extra data allocated for this class
    wc.cbWndExtra = 0;                             // extra data allocated for this window
    wc.hInstance = hInstance;                      // handle to instance
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);    // icon showing when user presses alt-tab
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);      // cursor showing when user hovers over window
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // background color
    wc.lpszMenuName = NULL;                        // name of menu resource
    wc.lpszClassName = g_szClassName;              // name of window class
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);  // small icon in taskbar

    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Creating the Window
    hwnd = CreateWindowEx(
        0,
        g_szClassName,
        "Calculator",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 480, 640,
        NULL, NULL, hInstance, NULL);

    // error handling
    if (hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
                   MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // The Message Loop
    // This is the main loop of the program that keeps the window running
    // Every action that the user does, is put on the message queue
    while (GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}