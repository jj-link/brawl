#include <types.h>
#include <nw4r/g3d/g3d_anmchr.h>
#pragma force_active on
extern "C" void* fn_80204E5C(s32, u32);
extern "C" char lbl_80465FC0[];
extern "C" char lbl_80465F68[];
extern "C" char lbl_80465F10[];
extern "C" float lbl_805A32AC;

extern "C" void* fn_8019A700(s32 arg0, s32* arg1, nw4r::g3d::ResMdl* arg2, s32 arg3) {
    s32* out;
    s32 n;
    u32 a;
    u32 b;
    u32 c;
    s32 i;
    s32 off;
    float f;
    char* p;

    out = arg1;
    if (!arg2->IsValid()) {
        return 0;
    }
    n = arg2->GetResNodeNumEntries();
    a = ((n * 2) + 0x27) & ~3;
    b = (a + arg3 * 4 + 3) & ~3;
    c = (b + arg3 * 4 + 3) & ~3;
    if (out != 0) {
        *out = c;
    }
    if (arg0 == 0) {
        return 0;
    }
    p = (char*)fn_80204E5C(arg0, c);
    if (p == 0) {
        return 0;
    }
    if (p != 0) {
    *(s32*)(p + 0x4) = 0;
    *(s32*)(p + 0x8) = arg0;
    *(s32*)(p + 0xC) = 0;
    *(char**)(p + 0x0) = lbl_80465FC0;
    *(s32*)(p + 0x10) = n;
    *(char**)(p + 0x14) = p + 0x24;
    ((nw4r::g3d::AnmObjChrRes*)p)->Release();
    *(char**)(p + 0x0) = lbl_80465F68;
    *(s32*)(p + 0x18) = arg3;
    *(char**)(p + 0x1C) = p + a;
    for (i = 0, off = 0; i < *(s32*)(p + 0x18); i++, off += 4) {
        *(s32*)(*(char**)(p + 0x1C) + off) = 0;
    }
    f = 1.0f;
    *(char**)(p + 0x0) = lbl_80465F10;
    *(char**)(p + 0x20) = p + b;
    for (i = 0, off = 0; i < *(s32*)(p + 0x18); i++, off += 4) {
        *(float*)(*(char**)(p + 0x20) + off) = f;
    }
    }
    return p;
}
