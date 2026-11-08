#include <stdio.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

class Object_vptr_0 {
public:
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
    virtual void slot13(void*);
};

struct Model {
    char pad[16];
    void* scene;
};

struct Self {
    char pad[0x10c];
    Model* models[6];
    char pad124[0x3c];
    Object_vptr_0* scene;
    char pad164[0xd4];
    void* texture;
};

struct ModelBuffer {
    Model* models[6];
    char padding[16];
};

extern "C" {
extern char lbl_8045D348[15];
extern char lbl_8059E670[8];

void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
int exchangeGmCharacterKind2MuStockchkind__6muMenuFi(int);
int exchangeGmCharacterKind2Something__6muMenuFi(int);
void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
void fn_800B7224(void*, void*, const char*, void*);
}

extern "C" void fn_8010CA94(Self* self, int count, unsigned char* data) {
    char buf[6] = {};
    ModelBuffer buffer;
    char name[24];
    char* strings = lbl_8045D348;
    const char* special;
    Model** src;
    Model** dst;
    int i;
    int idx = 0x43;
    Object_vptr_0* scene = self->scene;

    if (count > 6)
        count = 6;
    if (count < 0)
        count = 0;

    src = self->models;
    dst = buffer.models;
    special = strings + 0xfc;

    for (i = 0; i < count; ++i) {
        *dst = *src;
        sprintf(buf, lbl_8059E670, i);
        scene->slot13((*dst)->scene);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(scene, (*dst)->scene, buf);

        int kind = exchangeGmCharacterKind2MuStockchkind__6muMenuFi(data[i + 1]);
        float frame = (float)(exchangeGmCharacterKind2Something__6muMenuFi(kind) * 10 + 1);
        int value = (int)frame;

        if (value == 621) {
            Model* model = *dst;
            void* texture = self->texture;
            void* material = GetResMat__Q34nw4r3g3d6ResMdlCFPCc(
                (char*)model + 8, strings + 0x108);
            fn_800B7224(model, *(void**)((char*)material + 12),
                        special, texture);
        } else {
            sprintf(name, strings + 0x118, value);
            Model* model = *dst;
            void* texture = self->texture;
            void* material = GetResMat__Q34nw4r3g3d6ResMdlCFPCc(
                (char*)model + 8, strings + 0x108);
            fn_800B7224(model, *(void**)((char*)material + 12), name, texture);
        }

        ++src;
        ++idx;
        ++dst;
    }

    Model** remaining = buffer.models + i;
    for (; i < 6; ++i) {
        *remaining = ((Model**)self)[idx];
        scene->slot13((*remaining)->scene);
        ++remaining;
    }
}
