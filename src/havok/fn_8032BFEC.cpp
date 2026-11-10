#include <types.h>
#pragma force_active on

namespace {
class Obj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual s32 slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual u32 slot18();
};

struct Node {
    u8 pad0[0xc];
    Obj* obj;
    u32 f10;
    u32 f14;
    u32 f18;
};

struct Ref {
    u8 pad0[0x10];
    s32 off;
    u8 pad1[4];
    s8 kind;
};

struct Owner {
    u8 pad0[0x1c];
    Obj* obj;
};
} // namespace

extern "C" {
s32 fn_802E1E40(void* p);
Node* fn_802E1E50(void* p, s32 idx);

s32 fn_8032BFEC(Owner* self, Ref* a, Ref* b) {
    s32 var_r30;
    s32 temp_r30;
    Node* var_r29;
    Node* var_r28;
    Node* var_r31;
    s32 var_r27;
    Obj* obj;

    if (a->kind == 1) {
        var_r28 = (Node*)((u8*)a + a->off);
    } else {
        var_r28 = 0;
    }
    if (b->kind == 1) {
        var_r31 = (Node*)((u8*)b + b->off);
    } else {
        var_r31 = 0;
    }
    var_r30 = 0;
    obj = self->obj;
    if (obj != 0) {
        if ((s8)(obj->slot18() >> 24) == 0) {
            var_r30 = 1;
        }
    }
    if (var_r30 != 0) {
        return 0;
    }
    if (var_r28 == 0 || var_r31 == 0) {
        return 0x01000000;
    }
    temp_r30 = fn_802E1E40(var_r31);
    if (fn_802E1E40(var_r28) > temp_r30) {
        var_r29 = var_r31;
    } else {
        var_r29 = var_r28;
        var_r28 = var_r31;
    }
    temp_r30 = fn_802E1E40(var_r29);
    for (var_r27 = 0; var_r27 < temp_r30; var_r27++) {
        Node* cur = fn_802E1E50(var_r29, var_r27);
        if (cur != 0) {
            if (cur->obj->slot3() != 0xb) {
                if (cur->f14 == (u32)var_r28 || cur->f18 == (u32)var_r28) {
                    return 0;
                }
            }
        }
    }
    return 0x01000000;
}
}
