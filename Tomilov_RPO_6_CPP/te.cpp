#include <windows.h>
#include <tchar.h>  // Для TCHAR, TEXT(), _T()
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:WinMainCRTStartup")

// Глобальные переменные
LPCTSTR szClassName = TEXT("MyClass");
HINSTANCE hInstance;
LRESULT CALLBACK MyWndProc(HWND, UINT, WPARAM, LPARAM);  // CALLBACK вместо __stdcall

// Точка входа приложения
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance,
    LPSTR szCmdLine, int iCmdShow)
{
    WNDCLASSEX wnd = { 0 };  // Используем WNDCLASSEX вместо WNDCLASS
    MSG msg;
    HWND hwnd;

    hInstance = hInst;

    // Заполнение структуры класса окна
    wnd.cbSize = sizeof(WNDCLASSEX);
    wnd.style = CS_HREDRAW | CS_VREDRAW;
    wnd.lpfnWndProc = MyWndProc;
    wnd.cbClsExtra = 0;
    wnd.cbWndExtra = 0;
    wnd.hInstance = hInstance;
    wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  // COLOR_WINDOW вместо COLOR_BACKGROUND
    wnd.lpszMenuName = NULL;
    wnd.lpszClassName = szClassName;
    wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION);  // Маленькая иконка

    // Регистрация класса окна
    if (!RegisterClassEx(&wnd))
    {
        MessageBox(NULL, TEXT("Не удалось зарегистрировать класс окна"),
            TEXT("Ошибка"), MB_ICONERROR | MB_OK);
        return 0;
    }

    // Создание окна
    hwnd = CreateWindowEx(
        0,                              // Расширенные стили
        szClassName,                    // Имя класса
        TEXT("щ"),         // Заголовок окна (с поддержкой Unicode)
        WS_OVERLAPPEDWINDOW,            // Стиль окна
        CW_USEDEFAULT, CW_USEDEFAULT,   // Позиция
        CW_USEDEFAULT, CW_USEDEFAULT,   // Размер
        NULL, NULL, hInstance, NULL);

    if (!hwnd)  // Проверка на успешное создание
    {
        MessageBox(NULL, TEXT("Не удалось создать окно"),
            TEXT("Ошибка"), MB_ICONERROR | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    // Цикл обработки сообщений
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

// Процедура обработки сообщений окна
LRESULT CALLBACK MyWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_PAINT:  // Обработка перерисовки
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // Пример отрисовки текста
        TextOut(hdc, 100, 100, TEXT("а!"), _tcslen(TEXT("а!")));

        EndPaint(hwnd, &ps);
    }
    return 0;

    case WM_DESTROY:  // Завершение работы
        PostQuitMessage(0);
        return 0;
    }

    // Все остальные сообщения обрабатываем по умолчанию
    return DefWindowProc(hwnd, msg, wParam, lParam);
}