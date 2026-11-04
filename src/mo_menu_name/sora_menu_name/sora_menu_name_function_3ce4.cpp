#pragma force_active on

struct Listener {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual float getFrame();
    virtual void f7();
    virtual void setFrame(float);
};

struct Resource {
    unsigned char pad[0x0C];
    Listener* listener;
};

struct MuObject {
    unsigned char pad[0x14];
    Resource* resource;
};

struct Menu {
    unsigned char pad[0x40];
    MuObject* object;
    unsigned char pad2[0x9C - 0x44];
    int field9C;
    unsigned char pad3[0x3E8 - 0xA0];
    int field3E8;
    int field3EC;
};

extern "C" void setFrameNode__8MuObjectFf(MuObject*, float);
extern "C" float lbl_16_rodata_210;
extern "C" float lbl_16_rodata_180;

extern "C" int fn_16_3CE4(Menu* self) {
    MuObject* object = self->object;
    Listener* listener = object->resource->listener;

    if (listener->getFrame() >= lbl_16_rodata_210) {
        setFrameNode__8MuObjectFf(object, lbl_16_rodata_210);
        object->resource->listener->setFrame(lbl_16_rodata_180);
        self->field3E8 = 4;
        self->field3EC = 0;
        return 0;
    }
    return self->field9C;
}
