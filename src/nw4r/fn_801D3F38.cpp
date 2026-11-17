#include <types.h>
#pragma force_active on

struct soHeader {
    u32 unk0;
    u16 unk4;
    u16 version;
};

struct soObj {
    void* v;
};

struct soArchive {
    soHeader* header;
    u32 unk4;
    char* data;
};

extern "C" void fn_801D36BC(soObj*, s32);
extern "C" s32 fn_801D36C4(soObj*, s32, s32);

extern "C" s32 fn_801D3F38(soArchive self, u32 idx, s32 a, s32 b) {
    s32 p;
    soObj obj;

    if (self.header->version == 0x100) {
        char* data = self.data;
        u32 val = *(u32*)(data + idx * 4 + 8);
        p = (s32)(val + (u32)data);
    } else {
        char* data = self.data;
        if (idx >= *(u32*)(data + 8)) {
            return 0;
        }
        u32 val = *(u32*)(data + idx * 4 + 12);
        p = (s32)(val + (u32)data);
    }

    fn_801D36BC(&obj, p);
    return fn_801D36C4(&obj, a, b);
}
