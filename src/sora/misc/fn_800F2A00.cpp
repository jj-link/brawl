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
    void* l1;
    void* l1b;
    Listener* l2;
};

struct MuObject {
    unsigned char pad[0x14];
    Resource* resource;
};

struct Menu {
    unsigned char pad[0x44];
    MuObject* object;
    unsigned char pad2[0x18];
    int result;
};

extern "C" void setFrameNode__8MuObjectFf(MuObject*, float);
extern "C" void setFrameMatCol__8MuObjectFf(MuObject*, float);
extern "C" float lbl_805A25F8;
extern "C" float lbl_805A25C0;

extern "C" int fn_800F2A00(Menu* self) {
    MuObject* object = self->object;
    if (object->resource->listener->getFrame() < lbl_805A25F8) {
        return self->result;
    }
    setFrameNode__8MuObjectFf(object, lbl_805A25F8);
    setFrameMatCol__8MuObjectFf(object, lbl_805A25F8);
    object->resource->listener->setFrame(lbl_805A25C0);
    object->resource->l2->setFrame(lbl_805A25C0);
    return 2;
}
