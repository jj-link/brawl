#include <types.h>

extern "C" void fn_801B92BC(void* p, int n);

struct Obj {
    char pad[0x9C];
    s32 unk9C;
    s32 unkA0;
    char padA4[0xB4 - 0xA4];
    s32 unkB4;
};

#pragma force_active on
extern "C" void fn_801D16D0(Obj* obj) {
    if (obj->unkB4 != 1) {
        char* p = (char*)obj;
        char* q;
        s32 i = 0;
        for (; i < obj->unk9C; i++) {
            q = p;
            s32 j = 0;
            for (; j < obj->unkA0; j++) {
                void* v = *(void**)(q + 0xC);
                if (v != 0) {
                    fn_801B92BC(v, 0x10);
                }
                q += 4;
            }
            p += 0x10;
        }
    }
}
