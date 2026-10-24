#include <types.h>
#pragma force_active on

struct FnVisInfo {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual s8 getFlag(u32 idx);
    u8 pad[0x10];
    u8* flags;
};

extern "C" u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(void*);

extern "C" void fn_80197AFC(s8* out, void* mdl, FnVisInfo* info) {
    u32 count = GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(mdl);
    u32 off;
    u32 i;
    i = 0;
    off = 0;
    while (i < count) {
        if ((*(u16*)(info->flags + off) & 0xC000) == 0) {
            *out = info->getFlag(i);
        }
        off += 2;
        i++;
        out++;
    }
}
