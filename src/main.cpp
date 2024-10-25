#include <pwn>

#ifdef BUILD_SHARED_LIBS
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
#else
auto wmain(const int argc, const wchar_t* argv) -> int
#endif
{
    ok(L"hack the planet 🌍!!");
    return 0;
}
