#include <types.h>
#pragma force_active on

extern "C" int __cntlzw(unsigned int);
extern "C" void* fn_802F37D8(unsigned int arg0, void* arg1, void* arg2);
extern "C" void fn_802FF118(void* a, void* b, void* c);

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
};

struct Thing {
    char pad[0x70];
    void* p70;
};

struct Sub {
    char pad0[0x18];
    Thing* t18;
    char pad1[0x26 - 0x1C];
    u8 flag : 2;
    u8 rest : 6;
};

struct Obj {
    char pad0[0x58];
    Sub* sub;
    char pad1[0xA8 - 0x5C];
    u8 state;
};

struct Node {
    char pad0[0x10];
    int off;
};

struct Self {
    char pad0[0x10];
    Object_vptr_0* v10;
    Node* n14;
    Node* n18;
};

extern "C" void fn_802F3670(Self* self) {
    Node* na = self->n14;
    Node* nb = self->n18;
    Obj* oa = (Obj*)((char*)na + na->off);
    Obj* ob = (Obj*)((char*)nb + nb->off);
    Sub* cur = oa->sub;
    Sub* sb = ob->sub;
    if (cur == sb) {
        cur->flag = 1;
    } else {
        s8 eq7a = (s8)((u32)__cntlzw((u32)(oa->state - 7)) >> 5);
        if (eq7a != 0) {
            cur = sb;
        } else {
            s8 eq7b = (s8)((u32)__cntlzw((u32)(ob->state - 7)) >> 5);
            if (eq7b != 0) {
                cur = oa->sub;
            } else {
                cur = (Sub*)fn_802F37D8((unsigned int)self, oa->sub, ob->sub);
                oa->sub->flag = 1;
                ob->sub->flag = 1;
            }
        }
    }
done:
    Object_vptr_0* v = self->v10;
    fn_802FF118((char*)cur + 0x48, self, cur->t18->p70);
    v->slot6();
}
