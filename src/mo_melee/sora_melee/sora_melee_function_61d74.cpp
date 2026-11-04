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
    char pad70[0x4];
    u32 pad74high : 22;
    u32 flag74 : 1;
    u32 pad74low : 9;
    char pad78[0x24];
    u8 u9c;
};

class ItemList {
public:
    virtual void isNull();
    virtual Item* fn_27_614C4(int index);
    virtual void fn_27_6151C();
    virtual int fn_27_6052C();
    virtual void fn_27_60524();
    virtual void fn_27_5CE30();
    virtual void fn_27_5CE38();
    virtual void fn_27_5CEEC();
    virtual void fn_27_5CFB8();
    virtual void fn_27_5EC64();
    virtual void fn_27_5D2CC();
    virtual void fn_27_5EF98();
};

struct Ret {
    char pad[0x28];
    u32 val;
};

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual Ret* fn_27_14AD8(int);
};

struct ObjB {
    char pad[0x54];
    Class_1250* c;
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

extern "C" int fn_27_61D74(Outer* self, u8* arg1) {
    *arg1 = 0;
    for (int i = 0; i < self->list->fn_27_6052C(); i++) {
        Item* it = self->list->fn_27_614C4(i);
        if (it->fc >= lbl_27_rodata_8B0) {
            if ((it->u6c & 0x1F) == 7) {
                return 1;
            }
            if (it->u9c == 1) {
                *arg1 = 1;
                return 1;
            }
            Ret* r = self->a->b->c->fn_27_14AD8(0);
            if (it->u1c != r->val) {
                if (it->f4 >= soValueAccesser::getConstantFloat((soModuleAccesser*)self->a, 0x7F1, 0)) {
                    return 1;
                }
            } else if (!it->flag74) {
                *arg1 = 1;
                return 1;
            }
        }
    }
    return 0;
}
