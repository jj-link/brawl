#pragma force_active on

struct Container {
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
    virtual void call(void*);
};

struct Self {
    char pad[0x168];
    void* object;
    char pad16C[0x1F6];
    unsigned char flag;
};

extern "C" {
extern Container* lbl_805A033C;

void fn_8010C9D8(Self* self) {
    lbl_805A033C->call(self->object);
    self->flag = 0;
}
}
