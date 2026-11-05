#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_3_rodata_812C;
extern const float lbl_3_rodata_8120;
void setFrameMatCol__8MuObjectFf(void* obj, float frame);
void fn_801AAFF0(void* obj, int arg);
void fn_801AB014(void* obj, int arg);
}

struct TourObj {
    char pad0[0xC];
    void* unkC;
};

struct TourSelf {
    u32 pad0;
    TourObj* elems[94];
    char pad1[0x17C];
    u32 unk2F8;
};

extern "C" void fn_3_1240(TourSelf* self, int mode) {
    switch (mode) {
    case 0: {
        TourObj* obj;
        int v;
        TourObj** p;
        unsigned int i;
        p = (TourObj**)self;
        for (i = 0; i < 0x5E; i++, p++) {
            setFrameMatCol__8MuObjectFf(p[1], lbl_3_rodata_812C);
            obj = p[1];
            v = self->unk2F8;
            fn_801AAFF0(obj->unkC, v);
            fn_801AB014(obj->unkC, v);
        }
        return;
    }
    case 1: {
        unsigned int j;
        TourObj** q;
        TourObj* o;
        int w;
        q = (TourObj**)self;
        for (j = 0; j < 0x5E; j++, q++) {
            setFrameMatCol__8MuObjectFf(q[1], lbl_3_rodata_8120);
            o = q[1];
            w = self->unk2F8;
            fn_801AAFF0(o->unkC, w);
            fn_801AB014(o->unkC, w);
        }
        return;
    }
    }
}
