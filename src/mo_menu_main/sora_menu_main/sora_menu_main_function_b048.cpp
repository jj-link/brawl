#include <types.h>
#include <revolution/MTX/mtx.h>
#pragma force_active on

extern "C" void* fn_8018EED0(void* handle, int index);
extern "C" s32 fn_8018EF78(void* handle, void* obj);

extern "C" s32 fn_2_B048(char* self, f32* arg1, f32* arg2, f32* arg3, f32* arg4) {
    void* sp8;
    Vec a;
    Vec b;
    char* base;
    char* p;
    char* obj;
    s32 count;
    s32 i;
    char* q;

    sp8 = 0;
    base = self + (*(s32*)(self + 0x2BC) + 2) * 4;
    p = *(char**)(base + 0xE8);
    obj = *(char**)(p + 0x10);
    sp8 = *(void**)(obj + 0xE8);
    count = fn_8018EF78(&sp8, obj);
    if (count == 0) {
        return 0;
    }
    for (i = 0; (u32)i < (u32)count; i++) {
        q = (char*)fn_8018EED0(&sp8, i);
        a = *(Vec*)(q + 0x20);
        b = *(Vec*)(q + 0x2C);
        if (i <= 0) {
            *arg1 = a.x;
            *arg2 = a.z;
            *arg3 = b.x;
            *arg4 = b.z;
        } else {
            if (a.x < *arg1) {
                *arg1 = a.x;
            }
            if (b.x > *arg3) {
                *arg3 = b.x;
            }
            if (a.z < *arg2) {
                *arg2 = a.z;
            }
            if (b.z > *arg4) {
                *arg4 = b.z;
            }
        }
    }
    return 1;
}
