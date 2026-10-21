#include <types.h>
#pragma force_active on

extern "C" {
    int isLoadFinish__20tyFigListDataManagerFv(void* mgr);
    void* getFigDataId__20tyFigListDataManagerFUl(void* mgr, u32 id);
}

extern const float lbl_27_rodata_6000;

struct Vec2 {
    f32 x;
    f32 y;
};

extern "C" int fn_27_2C1C80(u8* self, u32 id, Vec2* a, Vec2* b) {
    const f32 z = lbl_27_rodata_6000;
    a->y = z;
    a->x = z;
    b->y = z;
    b->x = z;
    if (isLoadFinish__20tyFigListDataManagerFv(*(void**)(self + 4)) == 0) {
        return 0;
    }
    u8* data = (u8*)getFigDataId__20tyFigListDataManagerFUl(*(void**)(self + 4), id);
    if (data == 0) {
        return 0;
    }
    a->x = *(f32*)(data + 0x50);
    a->y = *(f32*)(data + 0x54);
    b->x = *(f32*)(data + 0x58);
    b->y = *(f32*)(data + 0x5C);
    return 1;
}
