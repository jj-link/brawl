#pragma force_active on
struct Anim {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setFrame(float);
};

struct AnimSet {
    char pad[0x0c];
    Anim* node;
    char pad10[8];
    Anim* texSrt;
};

struct Resource {
    char pad[0x3c];
    int nameOffset;

    const char* name() const {
        return nameOffset ? (const char*)this + nameOffset : 0;
    }
};

struct MuObject {
    char pad[8];
    Resource* resource;
    char pad0c[8];
    AnimSet* animations;
};

struct Sub {
    char pad[0x104];
    MuObject* objects[24];
};

struct Viewer {
    char pad[0x1ac];
    Sub* sub;
};

extern "C" {
extern const float lbl_6_rodata_590;
void changeNodeAnimN__8MuObjectFPCc(MuObject*, const char*);
void changeTexSrtAnimN__8MuObjectFPCc(MuObject*, const char*);
void setFrameNode__8MuObjectFf(MuObject*, float);
}

inline void resetObject(MuObject* obj) {
    obj->animations->node->setFrame(lbl_6_rodata_590);
    changeNodeAnimN__8MuObjectFPCc(obj, obj->resource->name());
    changeTexSrtAnimN__8MuObjectFPCc(obj, obj->resource->name());
}

extern "C" void fn_6_1D58(Viewer* self) {
    self->sub->objects[3]->animations->texSrt->setFrame(lbl_6_rodata_590);
    self->sub->objects[4]->animations->texSrt->setFrame(lbl_6_rodata_590);

    for (int i = 12; i < 19; ++i) {
        self->sub->objects[i]->animations->node->setFrame(lbl_6_rodata_590);
    }

    resetObject(self->sub->objects[22]);
    self->sub->objects[23]->animations->texSrt->setFrame(lbl_6_rodata_590);
    setFrameNode__8MuObjectFf(self->sub->objects[20], lbl_6_rodata_590);
}
