#include <st/module.h>
#pragma force_active on

extern "C" {
void fn_110_C324(void* a, void* b);
s16* fn_110_C6C4(s16* destination, const s16* source);
s32 fn_110_C404(void* a, s16* b, void* c);
}

struct WarioFlags {
    unsigned char enabled : 1;
    unsigned char pad : 7;
};

extern "C" void fn_110_C374(unsigned char* self, s16* p, void* arg) {
    s16 tmp[4];
    unsigned char* sub = self + 0xC;
    if (p[0] & 2) {
        bool enabled = reinterpret_cast<WarioFlags*>(sub + 5)->enabled;
        if (enabled == true && sub[6] == 0) {
            fn_110_C324(sub, arg);
        }
    }
    fn_110_C6C4(tmp, p);
    fn_110_C404(self + 4, tmp, arg);
}
