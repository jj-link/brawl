#include <types.h>
#pragma force_active on

struct Self {
    u8 pad[0x14C];
    u8 fileInfo[0x3C];
    bool enabled;
};

struct Obj {
    void* vtable;
    u8 pad04[0x10];
    s32 field14;
    u8 pad18[0x58];
    s32 field70;
    s32 field74;
};

extern "C" void fn_8015D294(Obj*, s32, s32);
extern "C" void fn_8015D3F0(Obj*, const void*, s32);
extern char lbl_80466650[];

extern "C" Obj* fn_801BEDB8(
    const Self* self, void* buf, int size, u32 arg3, u32 arg4
) {
    if (!self->enabled)
        return 0;

    if (size < sizeof(Obj))
        return 0;

    Obj* obj = (Obj*)buf;
    if (obj) {
        fn_8015D3F0(obj, self->fileInfo, 0);
        obj->field70 = arg3;
        obj->vtable = lbl_80466650;
        obj->field74 = arg4;
        if (!arg4)
            obj->field74 = obj->field14;
        fn_8015D294(obj, obj->field70, 0);
    }
    return obj;
}
