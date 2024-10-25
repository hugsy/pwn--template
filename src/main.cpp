#include <pwn>
using namespace pwn;

// uncomment below if cmake was configured with BUILD_SHARED_LIBS
// BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) 

auto 
wmain(const int argc, const wchar_t** argv) -> int
{
    ok(L"hack the planet 🌍!!");
    return 0;
}
