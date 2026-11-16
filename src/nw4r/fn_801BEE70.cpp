#include <types.h>
#pragma force_active on
#pragma optimization_level 4

struct Context {
    u8 pad[0x188];
    u8 flag;
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
extern "C" void* fn_8015D36C(void*, int);
extern "C" int fn_801F5F08(const char*);
extern char lbl_80466650[];

extern "C" Obj* fn_801BEE70(
    const Context* self, Obj* obj, u32 size, const char* path, s32 value, s32 other
) {
    if (!self->flag)
        return 0;
    if (size < 0x78)
        return 0;
    int file = fn_801F5F08(path);
    if (file < 0)
        return 0;
    if (obj) {
        fn_8015D36C(obj, file);
        obj->field70 = value;
        obj->vtable = lbl_80466650;
        obj->field74 = other;
        if (!other)
            obj->field74 = obj->field14;
        fn_8015D294(obj, obj->field70, 0);
    }
    return obj;
}
