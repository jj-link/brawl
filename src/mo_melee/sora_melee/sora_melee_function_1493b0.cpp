#include <types.h>
#pragma force_active on

struct Holder {
    s32 pad[9];
    s32* p;
};

struct Root {
    s32 pad[9];
    Holder* h;
};

extern Root lbl_27_bss_3210[];

extern "C" s32 fn_27_1493B0(void* self, s32 kind, s32 unused) {
    switch (kind) {
    case 3:
        return *reinterpret_cast<s32*>(
            reinterpret_cast<char*>(lbl_27_bss_3210[0].h) + 136);
    default:
        return 0;
    }
}
