#include <types.h>
#pragma force_active on

struct MgrFlag {
    char _0[0x6d];
    u8 flag;
};

extern MgrFlag* g_ftManager;
extern "C" void fn_118_973C(int, MgrFlag*);
extern "C" void fn_118_960C(int, MgrFlag*);

extern "C" void fn_118_95F0(int a) {
    if (g_ftManager->flag != 0) {
        fn_118_973C(a, g_ftManager);
    } else {
        fn_118_960C(a, g_ftManager);
    }
}
