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
    virtual float getLength();
};

struct Resource {
    unsigned char pad[0x0c];
    Listener* listener;
};

struct MuObject {
    unsigned char pad[0x14];
    Resource* resource;
    void setFrameNode(float);
};

struct Menu {
    unsigned char pad0[0x40];
    MuObject* node;
    unsigned char pad44[0x54];
    int state;
    int result;
    unsigned char pada0[0x348];
    int field3e8;
    int field3ec;
};

extern "C" float lbl_16_rodata_180;
extern "C" float lbl_16_rodata_228;

extern "C" int fn_16_48DC(Menu* self) {
    MuObject* node;
    int done = 1;

    if (self->state != 2) {
        node = self->node;
        if (node->resource->listener->getLength() > lbl_16_rodata_180) {
            float frame = lbl_16_rodata_228;
            if (node->resource->listener->getFrame() >= frame) {
                node->setFrameNode(frame);
                node->resource->listener->setFrame(lbl_16_rodata_180);
            } else {
                done = 0;
            }
        }
    }

    if (done) {
        self->field3e8 = 5;
        self->field3ec = 0;
        return 2;
    }
    return self->result;
}
