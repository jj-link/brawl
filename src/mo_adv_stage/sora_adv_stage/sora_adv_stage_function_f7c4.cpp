#pragma force_active on

#include <types.h>

extern "C" void* getInstance__9itManagerFv();
extern "C" void* fn_27_2A8A00(void* mgr, int idx);
extern "C" void fn_40_6240(void* self, int a, void* pos);

extern void* lbl_40_bss_15C;
extern const float lbl_40_rodata_14C;

struct Counter {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int getCount();
};

struct Vec3f {
    float x;
    float y;
    float z;
};

struct Pos {
    float x;
    float y;
    int id;
};

struct Work {
    char pad0[0xC];
    /* 0x0C */ int state;
    /* 0x10 */ Pos* pos;
    /* 0x14 */ int unk14;
};

extern "C" void fn_40_F7C4(Work* work) {
    u32 count;
    int found = 0;
    int i;
    if ((u32)(work->state - 1) <= 1u) {
        count = ((Counter*)((char*)getInstance__9itManagerFv() + 0x6D8))->getCount();
        for (i = 0; i < count; i++) {
            void* item = fn_27_2A8A00(getInstance__9itManagerFv(), i);
            if (item != NULL) {
                if (*(u32*)&work->pos->id == *(u32*)((char*)item + 0x3D28)) {
                    found = 1;
                    break;
                }
            }
        }
    }
    if (work->state == 1 && found == 0) {
        float y = work->pos->y;
        Vec3f pos = {(work->pos->x), y, lbl_40_rodata_14C};
        fn_40_6240(lbl_40_bss_15C, work->pos->id, &pos);
        if (work->unk14 == 0) {
            work->state = 2;
        } else {
            work->state = 0;
        }
    }
}
