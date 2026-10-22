#include <types.h>
#pragma force_active on

struct Scene {
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
    virtual void remove(s32);
    char pad[0xE0];
    s32 count;
};

struct Entry {
    Scene* head;
    char pad[6];
    u16 flag;
    char pad2[0x18 - 0x0C];
};

struct Self {
    char pad[0x390];
    Entry entries[1];
};

extern "C" s32 fn_8000D24C(Self* self, s32 index) {
    s32 var_r0 = 0;
    Scene* scene = self->entries[index].head;
    if (scene != 0) {
        while (scene->count != 0) {
            if (scene->count != 0) {
                scene->remove(scene->count - 1);
            }
        }
        self->entries[index].flag = 0;
        var_r0 = 1;
    }
    return var_r0;
}
