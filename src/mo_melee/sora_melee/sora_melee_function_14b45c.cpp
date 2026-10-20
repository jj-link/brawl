#include <types.h>
#pragma force_active on

class Accesser {
public:
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual s32 get(s32, s32);
};

struct Modules {
    u8 pad[0xC4];
    Accesser* accesser;
};

struct Object {
    u8 pad[0xD8];
    Modules* modules;
};

extern "C" {
extern s32 lbl_27_bss_1B18;
extern u8 g_ftCommonDataAccesser[];

s32 fn_27_8C078(void*, Object*, s32, s32);
s32 fn_27_1455BC(void*, s32, s32);

s32 fn_27_14B45C(void* self, Object* object, s32 id, s32 arg3) {
    if (id <= 0xA7F7)
        return fn_27_8C078(self, object, id, arg3);

    if (id < 0xA811)
        return object->modules->accesser->get(lbl_27_bss_1B18, id);

    return fn_27_1455BC(g_ftCommonDataAccesser, lbl_27_bss_1B18, id);
}
}
