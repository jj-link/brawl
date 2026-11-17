#include <types.h>
#include <stdio.h>
#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

extern "C" {
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern char lbl_2_data_2B98[];
extern const u8 lbl_2_rodata_97C[];
extern const float lbl_2_rodata_998;
}

class Group {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void remove(int);
    char pad[0xe0];
    int count;
};

class Rate {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void setRate(float);
};

inline s32 minValue(s32 a, s32 b) { if (a > b) a = b; return a; }

extern "C" void fn_2_2262C(void* arg0, s32 arg1) {
    char* self = (char*)arg0;
    Group* group;
    s32 off = arg1 * 6;
    s32 n = minValue(*(u8*)(self + 0x678) - *(u8*)(self + 0x679) * 6, 6);
    group = *(Group**)(*(char**)(self + 0x650) + 0x2c);
    while (group->count != 0) {
        if (group->count != 0) group->remove(group->count - 1);
    }
    s32 i;
    s32* p = *(s32**)(self + 0x674) + off;
    s32 j = 0;
    i = 0;
    while (i < n) {
        void* model;
        u32 index;
        u16 num;
        if (*p != 0x79) {
            s32 idx = j + 0x7e;
            ((MuObject**)*(char**)(self + 0x64c))[idx]->setFrameTex((float)(*p + 1));
            Rate* rt = *(Rate**)(*(char**)((char*)((MuObject**)*(char**)(self + 0x64c))[idx] + 0x14) + 0x10);
            rt->setRate(lbl_2_rodata_998);
            index = j++;
            model = ((MuObject**)*(char**)(self + 0x64c))[idx]->m_sceneModel;
            num = *(u16*)(lbl_2_rodata_97C + *p * 4);
        } else {
            index = 6;
            num = 5;
            model = ((MuObject**)*(char**)(self + 0x64c))[0x84]->m_sceneModel;
        }
        char name[8];
        sprintf(name, lbl_2_data_2B98, i);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(*(void**)(*(char**)(self + 0x650) + 0x2c), model, name);
        (*(MuMsg**)(self + 0x67c))->printIndex(index, num, 0);
        i++;
        p++;
    }
    ((MuObject**)*(char**)(self + 0x64c))[0x7d]->setFrameNode((float)n);
    Rate* nr = *(Rate**)(*(char**)((char*)((MuObject**)*(char**)(self + 0x64c))[0x7d] + 0x14) + 0xc);
    nr->setRate(lbl_2_rodata_998);
    s32 flags = 0;
    if (arg1 != 0) flags |= 1;
    if (arg1 < (*(u8*)(self + 0x678) + 5) / 6 - 1) flags |= 2;
    ((MuObject**)*(char**)(self + 0x64c))[0x7d]->setFrameVisible((float)flags);
    Rate* vr = *(Rate**)(*(char**)((char*)((MuObject**)*(char**)(self + 0x64c))[0x7d] + 0x14) + 0x8);
    vr->setRate(lbl_2_rodata_998);
}