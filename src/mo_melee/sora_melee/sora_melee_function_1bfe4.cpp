#include <types.h>
#pragma force_active on

extern "C" const f32 lbl_27_rodata_344;

class Item {
public:
    char pad[0x10];
    f32 f32_10;
    char pad2[8];
    s32 id;
};

class List {
public:
    virtual void vf0();
    virtual Item* getAt(s32 idx);
    virtual void vf2();
    virtual s32 getCount();
};

class Obj6C {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(void* arg, s16* sp, f32 val);
};

struct ObjB8_base { char pad[8]; };
class ObjB8 : public ObjB8_base {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual f32 vf13(s16* arg);
};

class ObjD8 {
public:
    char pad[0x6c];
    Obj6C* obj6C;
    char pad2[0x48];
    ObjB8* objB8;
};

class Obj168 {
public:
    char pad[0xd8];
    ObjD8* objD8;
};

class Self {
public:
    char pad[0x8c];
    List* list;
    char pad2[0xd8];
    Obj168* obj168;
};

extern "C" void fn_27_1BFE4(Self* self, s16* arg1, s32 arg2) {
    Obj168* obj168 = self->obj168;
    ObjD8* objD8 = obj168->objD8;
    ObjB8* objB8 = objD8->objB8;
    f32 val = objB8->vf13(arg1);

    s32 count = self->list->getCount();

    for (s32 i = 0; i < count; i++) {
        Item* item = self->list->getAt(i);
        if (item->id == -1) {
            continue;
        }

        f32 f1 = lbl_27_rodata_344;
        if (arg2 == 0) {
            Item* item2 = self->list->getAt(i);
            f1 = val * item2->f32_10;
        }

        s16 sp8 = *arg1;
        Obj6C* obj6C = self->obj168->objD8->obj6C;
        obj6C->vf2(self->obj168, &sp8, f1);
        return;
    }
}