#include <stdio.h>
#include <types.h>
#pragma force_active on

struct Resource {
    char pad[0x3c];
    int nameOffset;

    const char* name() const {
        return nameOffset ? (const char*)this + nameOffset : 0;
    }
};

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
};

struct MuObject {
    char pad[8];
    Resource* resource;
    char pad0c[8];
    AnimSet* animations;
};

extern "C" {
extern char lbl_8059E0E8[6];
extern const float lbl_805A22B0;
extern const float lbl_805A22BC;
void changeNodeAnimN__8MuObjectFPCc(void* obj, const char* name);
void setFrameNode__8MuObjectFf(void* obj, float frame);

void fn_800BFF34(void* arg) {
    MuObject* obj = *(MuObject**)((char*)arg + 0x40);
    char buf[0x40];
    sprintf(buf, lbl_8059E0E8, obj->resource->name());
    changeNodeAnimN__8MuObjectFPCc(obj, buf);
    setFrameNode__8MuObjectFf(obj, lbl_805A22B0);
    obj->animations->node->setFrame(lbl_805A22BC);
}
}
