#pragma force_active on

struct IfBase {
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
    virtual void slot13(int);
    virtual void slot14();
    virtual void slot15();
};

struct IfMngr {
    unsigned char padding0[0x14];
    IfBase* sub;
};

extern IfMngr* g_IfMngr;

struct Obj {
    unsigned char padding0[0x90];
    int unk90;
    unsigned char padding1[0x5];
    unsigned char unk99;
};

extern "C" void fn_800F5C60(Obj* self) {
    int v = self->unk90;
    if (v != 0) {
        IfBase* p = g_IfMngr->sub;
        if (p != 0) {
            p->slot13(v);
        }
        self->unk99 = 1;
    }
}
