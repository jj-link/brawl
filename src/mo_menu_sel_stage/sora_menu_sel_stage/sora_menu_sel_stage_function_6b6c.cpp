#include <types.h>
#include <mt/mt_prng.h>
#include <string.h>

#pragma force_active on

extern "C" s32 fn_11_6FDC(void*, void*, s32, s32, s32, s32);
extern mtRand lbl_805A0420;

struct Result { s32 a, b, c; };

inline s32 randomInt(s32 max) {
    return (s32)((f32)max * lbl_805A0420.mtRand::randf());
}

extern "C" Result fn_11_6B6C(void* arg1, s32 arg2) {
    s32* p = *(s32**)((char*)arg1 + 0x264);
    s32 records[0xD18];
    s32 count = fn_11_6FDC(arg1, records, p[0], p[1], 1, arg2);
    if (count <= 0) {
        p[1] = 0;
        p[0] = 0;
        memset(*(void**)((char*)arg1 + 0x268), 0, 0x80);
        count = fn_11_6FDC(arg1, records, p[0], p[1], 1, arg2);
        if (count <= 0) {
            count = fn_11_6FDC(arg1, records, p[0], p[1], 0, arg2);
        }
    }
    return ((Result*)records)[randomInt(count)];
}
