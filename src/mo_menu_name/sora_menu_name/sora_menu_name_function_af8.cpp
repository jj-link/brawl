#pragma force_active on
struct ResObj {
    char pad[0x10];
    void* data;
};

struct Renderer {
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
    virtual void remove(void*);
};

struct Data {
    int flag;
    char pad0[0x40];
    ResObj* res1;
    char pad1[0x14];
    ResObj* res2;
    ResObj* res3;
    char pad2[0x8];
    Renderer* renderer;
    char pad3[0x8];
    ResObj* res4;
};

extern "C" void fn_16_AF8(Data* self) {
    if (self->flag != 0) {
        self->renderer->remove(self->res1->data);
        if (self->res4) {
            self->renderer->remove(self->res4->data);
            self->res4 = 0;
        }
        self->renderer->remove(self->res2->data);
        if (self->res3) {
            self->renderer->remove(self->res3->data);
        }
        self->flag = 0;
    }
}
