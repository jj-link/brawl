#include <types.h>
#pragma force_active on

struct Vec2f {
    float x;
    float y;
};

struct Vec3f {
    float x;
    float y;
    float z;
};

class soModuleAccesser;

class fnObjBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual u8* v6(s32);
};

extern const float lbl_27_rodata_1FC0;

extern "C" {
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);

void fn_27_1627E0(int unused0, int unused1, Vec2f* vec, soModuleAccesser* accesser) {
    Vec3f zero = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    fn_27_89D08(0, accesser, 3, vec, &zero);

    u8* mod = *(u8**)((u8*)accesser + 0xd8);
    fnObjBase* obj = *(fnObjBase**)(mod + 0x7c);
    u8* ret = obj->v6(4);
    ret[5] |= 0x80;
}
}
