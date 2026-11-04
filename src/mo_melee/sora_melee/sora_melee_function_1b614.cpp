#include <types.h>
#pragma force_active on

extern "C" const f32 lbl_27_rodata_344;

class Obj6C {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(void* obj168, s16* sp, f32 val);
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(s16* ptr, void* obj168, s32 a, s32 b, f32 val);
};

class ObjB8_base { char pad[8]; };
class ObjB8 : public ObjB8_base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
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

class Item {
public:
    char pad[0x1c];
    s32 id;
};

class List {
public:
    virtual void vf0();
    virtual Item* getAt(s32 idx);
    virtual void vf2();
    virtual s32 getCount();
};

class Self {
public:
    char pad[0x8c];
    List* list;
    char pad2[0xd8];
    Obj168* obj168;
};

extern "C" void fn_27_1B614(Self* self, s32 unused, s32 mode, u32 flag1, s16* ptr, u32 flag2, f32 val) {
    s16 sp8;
    if (mode == -1) {
        Obj168* obj168 = self->obj168;
        obj168->objD8->obj6C->vf5(ptr, obj168, -1, 0, lbl_27_rodata_344);
        return;
    }
    
    self->obj168->objD8->objB8->m13();
    
    if (flag2 == 1) {
        s32 count = self->list->getCount();
        for (s32 i = 0; i < count; i++) {
            Item* item = self->list->getAt(i);
            if (item->id != -1) {
                ObjB8* b8 = self->obj168->objD8->objB8;
                self->list->getAt(i);
                self->list->getAt(i);
                b8->m13();
                break;
            }
        }
    }
    
    Obj168* obj168 = self->obj168;
    obj168->objD8->obj6C->vf5(ptr, obj168, mode, 0, val);
    
    if (flag1 == 1) {
        sp8 = *ptr;
        self->obj168->objD8->obj6C->vf2(self->obj168, &sp8, lbl_27_rodata_344);
    }
}