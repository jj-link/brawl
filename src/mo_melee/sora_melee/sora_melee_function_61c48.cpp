#pragma force_active on
#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#include <types.h>

extern const float lbl_27_rodata_8B0;

struct Item {
    char pad0[0x4];
    float f4;
    char pad8[0x4];
    float fc;
    char pad10[0xC];
    u32 u1c;
    char pad20[0x4C];
    u32 u6c;
    char pad70[0x2C];
    u8 u9c;
};

class ItemList {
public:
    virtual void v0();
    virtual Item* get(int index);
    virtual void v2();
    virtual int size();
};

struct Ret {
    char pad[0x28];
    u32 val;
};

class ObjC {
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
    virtual Ret* f13(int x);
};

struct ObjB {
    char pad[0x54];
    ObjC* c;
};

struct ObjA {
    char pad[0xD8];
    ObjB* b;
};

struct Outer {
    char pad0[0x3C];
    ObjA* a;
    ItemList* list;
};

extern "C" int fn_27_61C48(Outer* self) {
    for (int i = 0; i < self->list->size(); i++) {
        Item* it = self->list->get(i);
        if (it->fc >= lbl_27_rodata_8B0) {
            if ((it->u6c & 0x1F) == 7) {
                return 1;
            }
            if (it->u9c == 1) {
                return 1;
            }
            Ret* r = self->a->b->c->f13(0);
            if (it->u1c != r->val) {
                if (it->f4 >= soValueAccesser::getConstantFloat((soModuleAccesser*)self->a, 0x7F1, 0)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
