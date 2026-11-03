#pragma force_active on
#include <types.h>

struct Elem1Base {
    s32 id;
    u8 unk4;
    char pad5[0x2C - 5];
};

class Elem1 : public Elem1Base {
public:
    virtual void vf2(s32 arg);
};

struct Elem2Base {
    s32 id;
    char pad4[0xC];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 pad13;
};

class Elem2 : public Elem2Base {
public:
    virtual void vf2(s32 arg);
};

template <class T>
class ArrBase {
public:
    virtual bool isNull() const;
    virtual T& at(s32 index);
    virtual const T& at(s32 index) const;
    virtual s32 size() const;
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void erase(s32 index);
};

template <class T, int Size>
class ArrSized : public ArrBase<T> {
    char pad[Size - 4];
};

struct Owner {
    char pad0[0xC8];
    ArrSized<Elem1*, 0x10A8> arr1;
    ArrSized<Elem2*, 0x33C> arr2;
    u8 unk14AC;
};

extern "C" {
s32 fn_27_2B24C4(Elem1* e);
bool fn_27_2B2B4C(Elem2* e);

void fn_27_2ABD04(Owner* self, s32 arg1) {
    s32 i;
    for (i = 0; i < self->arr1.size(); i++) {
        Elem1*& slot = self->arr1.at(i);
        if (slot != 0 && arg1 == slot->id) {
            if (fn_27_2B24C4(slot) != 0) {
                if (slot != 0) {
                    slot->vf2(1);
                }
                self->arr1.erase(i);
                i--;
            } else {
                slot->unk4 = 1;
            }
        }
    }

    s32 j;
    for (j = 0; j < self->arr2.size(); j++) {
        Elem2*& slot2 = self->arr2.at(j);
        Elem2* e = slot2;
        if (e != 0) {
            if (arg1 != e->id) {
                e->unk11 = 0;
                slot2->unk12 = 0;
            } else if (fn_27_2B2B4C(e)) {
                if (slot2 != 0) {
                    slot2->vf2(1);
                }
                self->arr2.erase(j);
                j--;
            } else {
                slot2->unk10 = 1;
            }
        }
    }

    self->unk14AC = 0;
}
}
