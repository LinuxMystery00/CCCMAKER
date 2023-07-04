#include <windows.h>

// Procedimento de janela personalizado

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Registrar a classe da janela
    const wchar_t CLASS_NAME[] = L"CCCMAKER";
    
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    
    RegisterClass(&wc);
    
    // Criar a janela
    HWND hwnd = CreateWindowEx(
        0,                                  // Estilo adicional
        CLASS_NAME,                         // Nome da classe da janela
        L"CCCMAKER",                        // Título da janela
        WS_OVERLAPPEDWINDOW,                // Estilo da janela
        CW_USEDEFAULT, CW_USEDEFAULT,       // Posição da janela
        800, 600,                           // Tamanho da janela
        NULL,                               // Janela pai
        NULL,                               // Menu da janela
        hInstance,                          // Instância do aplicativo
        NULL                                // Dados adicionais
    );
    
    if (hwnd == NULL)
    {
        return 0;
    }
    
    // Exibir a janela
    ShowWindow(hwnd, nCmdShow);
    
    // Loop de mensagens da janela
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}