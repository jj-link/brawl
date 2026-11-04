#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6();
    virtual void slot7();
    virtual int slot8();
};

struct Entry {
    soNullable* value;
};

class ArrayBase {
public:
    virtual void slot0();
    virtual Entry* get(int index);
    virtual void slot2();
    virtual int size();
};

class PosA {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual int slot10();
};

class PosB {
public:
    virtual void slot0();
    virtual int slot1(void* a, soNullable* e);
};

class Ob38 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual int slot12(void* a, soNullable* e);
};

class Module {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
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
    virtual void slot14(int v);
    char pad4[0x24];
    void* unk28;
    ArrayBase* arr;
    PosA* unk30;
    void* unk34;
    Ob38* unk38;
};

extern "C" void fn_27_93860(Module* self, int kind, int arg2, unsigned int arg3)
{
    switch (arg2) {
    case 1: {
        int i;
        int limit;
        int v;
        soNullable* e;
        for (i = self->arr->size() - 1; i >= 0; i--) {
            if (self->arr->get(i)->value != 0) {
                if (kind == self->arr->get(i)->value->slot6()) {
                    limit = self->unk30->slot10();
                    e = self->arr->get(i)->value;
                    if (e->slot6() < limit) {
                        v = ((PosB*)((char*)self->unk30 + 4))->slot1(self->unk28, e);
                    } else {
                        if (self->unk38 == 0) {
                            v = 0;
                        } else {
                            v = self->unk38->slot12(self->unk28, e);
                        }
                    }
                    if (arg3 == 1 || v == 0) {
                        self->slot14(e->slot8());
                    }
                    return;
                }
            }
        }
        break;
    }
    case 0:
    case 2: {
        soNullable* e;
        int limit;
        int v;
        int i;
        for (i = self->arr->size() - 1; i >= 0; i--) {
            if (self->arr->get(i)->value != 0) {
                if (kind == self->arr->get(i)->value->slot6()) {
                    limit = self->unk30->slot10();
                    e = self->arr->get(i)->value;
                    if (e->slot6() < limit) {
                        v = ((PosB*)((char*)self->unk30 + 4))->slot1(self->unk28, e);
                    } else {
                        if (self->unk38 == 0) {
                            v = 0;
                        } else {
                            v = self->unk38->slot12(self->unk28, e);
                        }
                    }
                    if (arg3 == 1 || v == 0) {
                        self->slot14(e->slot8());
                    }
                    if (arg2 == 2) {
                        return;
                    }
                }
            }
        }
        break;
    }
    }
}
