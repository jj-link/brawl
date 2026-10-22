#pragma force_active on

struct Resource {
    char pad[0x3C];
    int nameOffset;
};

struct Anim {
    virtual ~Anim();
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
    char pad[0x0C];
    Anim* node;
};

struct MuObject {
    char pad[8];
    Resource* resource;
    char pad0c[8];
    AnimSet* anims;
};

struct Menu {
    char pad[0x40];
    MuObject* object;
};

extern "C" {
extern char lbl_8059E108[7];
extern const float lbl_805A22D4;
extern const float lbl_805A22F4;
void changeNodeAnimN__8MuObjectFPCc(MuObject*, const char*);
void setFrameNode__8MuObjectFf(MuObject*, float);
char* sprintf(char*, const char*, ...);

void fn_800C1808(Menu* menu) {
    char buf[0x3C];
    MuObject* obj = menu->object;
    const char* name = obj->resource->nameOffset ?
        (const char*)(obj->resource) + obj->resource->nameOffset : 0;
    sprintf(buf, lbl_8059E108, name);
    changeNodeAnimN__8MuObjectFPCc(obj, buf);
    setFrameNode__8MuObjectFf(obj, lbl_805A22D4);
    obj->anims->node->setFrame(lbl_805A22F4);
}
}
