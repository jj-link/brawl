#pragma force_active on
#include <types.h>
#include <so/anim/so_anim_chr.h>

union MotionFlags {
    u8 value;
    struct {
        u8 high : 5;
        u8 selected : 1;
        u8 low : 2;
    } bits;
};

struct PostureEntry {
    char pad[0x1c];
    int nodeId;
    char pad2[0x20];
    int resourceId;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual PostureEntry* slot1(int);
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(int, nw4r::g3d::AnmObjChrRes*);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(void*, int, int);
};

struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void* fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0();
    virtual void* fn_27_7ABD8();
};

struct ModelPath { char pad[4]; Class_90D8* model; };
struct ModelHub { char pad[0xd8]; ModelPath* path; };

struct Arg2 {
    char pad[0x40];
    int field40;
};

struct Character {
    char pad0[0x6c];
    soAnimChr anim;
    int animationIndex;
    Object_vptr_0* posture;
    char pad90[4];
    Object_vptr_0* manager;
    float value98, value9C, valueA0, valueA4, valueA8, valueAC;
    float valueB0, valueB4, valueB8, valueBC, valueC0, valueC4;
    char padC8[0x9c];
    unsigned char flags164;
    char pad165[3];
    ModelHub* model;
};

extern "C" void setAnimObj__9soAnimChrFffPQ34nw4r3g3d12AnmObjChrResUcUc(soAnimChr*, float, float, nw4r::g3d::AnmObjChrRes*, int, int);
extern "C" char* fn_27_20FE4(void*, int, int);
extern "C" nw4r::g3d::AnmObjChrRes* fn_27_151A4(void*, int, int, int, int, int);

extern "C" void fn_27_16AE0(void* owner, Arg2* arg2, int loop, float frame, float rate) {
    unsigned char animFlags;
    nw4r::g3d::AnmObjChrRes* resource;
    int i;
    Character* self = (Character*)owner;
    char* animData = fn_27_20FE4((char*)self + 0x34, (int)arg2, 1);
    animFlags = (unsigned char)animData[1];
    if (loop == 0)
        loop = (animFlags >> 1) & 1;
    resource = fn_27_151A4(self, (int)arg2, -1, 1, 0, 1);
    setAnimObj__9soAnimChrFffPQ34nw4r3g3d12AnmObjChrResUcUc(&self->anim, frame, rate, resource, loop, 0);
    self->manager->slot13(1, resource);
    self->animationIndex = (int)arg2;
    self->model->path->model->fn_27_7AEDC();
    MotionFlags flags;
    flags.value = self->flags164;
    flags.bits.selected = (animFlags >> 2) & 1;
    float f0, f1, f2, f3, f4, f5;
    f5 = self->valueA4;
    f4 = self->valueA8;
    f3 = self->valueAC;
    f2 = self->value98;
    f1 = self->value9C;
    f0 = self->valueA0;
    self->flags164 = flags.value;
    self->valueBC = f5;
    self->valueC0 = f4;
    self->valueC4 = f3;
    self->valueB0 = f2;
    self->valueB4 = f1;
    self->valueB8 = f0;
    int count = self->posture->slot3();
    for (i = 0; i < count; ++i) {
        PostureEntry* entry = self->posture->slot1(i);
        if (entry->nodeId != -1) {
            void* nodeData = self->model->path->model->fn_27_7ABD8();
            int nodeResource = *(int*)((char*)nodeData + 0xe8);
            ((Object_vptr_0*)resource)->slot19(&nodeResource, entry->resourceId, 1);
        }
    }
}
