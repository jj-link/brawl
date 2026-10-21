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

struct Entry {
    char pad[0x10];
    void* value;
};

struct Self {
    char pad0[0x30];
    void* object;
    Entry* entries[50];
    char padFC[0x60];
    Container* container;
    char pad160[0x1A8];
    int count;
};

extern "C" {
extern Container* lbl_805A033C;
extern char lbl_8059E678[6];
extern char lbl_8059E670[8];
extern float lbl_805A2870;

void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void setFrameNode__8MuObjectFf(void*, float);
int sprintf(char*, const char*, ...);

void fn_8010C3D4(Self* self) {
    char buf[6] = {};
    Container* container = self->container;

    lbl_805A033C->call(container);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
        lbl_805A033C, container, lbl_8059E678);

    int i;
    for (i = 0; i < 50; ++i) {
        container->call(self->entries[i]->value);
    }

    for (i = 0; i < self->count; ++i) {
        sprintf(buf, lbl_8059E670, i);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            container, self->entries[i]->value, buf);
    }

    setFrameNode__8MuObjectFf(self->object, lbl_805A2870);
}
}
