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

extern "C" void setFrameNode__8MuObjectFf(MuObject*, float);
extern "C" float lbl_16_rodata_208;
extern "C" float lbl_16_rodata_180;

extern "C" void fn_16_36D0(MuObject* node) {
    node = *(MuObject**)((char*)node + 0x40);
    setFrameNode__8MuObjectFf(node, lbl_16_rodata_208);
    node->resource->listener->setFrame(lbl_16_rodata_180);
}
