#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern const f32 lbl_27_rodata_2320;
extern const f32 lbl_27_rodata_2324;

class ObjA {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual Vec3f v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual f32 v9() = 0;
};

class ObjB {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30(void* p) = 0;
};

class ObjC {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13(u32 id, f32 val) = 0;
};

struct SpParam {
    s32 id;
    f32 a;
    f32 b;
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
};

inline Vec3f get_pos(u8* self) {
    SpParam sElse;
    SpParam sIf;
    if ((*(ObjA**)(*(u8**)(self + 0xd8) + 0xc))->v9() == lbl_27_rodata_2320) {
        sIf.id = 0x186;
        sIf.a = lbl_27_rodata_2324;
        sIf.b = lbl_27_rodata_2320;
        sIf.c0 = 0;
        sIf.c1 = 0;
        sIf.c2 = 0;
        sIf.c3 = 0;
        (*(ObjB**)(*(u8**)(self + 0xd8) + 0x8))->v30(&sIf);
    } else {
        sElse.id = 0x187;
        sElse.a = lbl_27_rodata_2324;
        sElse.b = lbl_27_rodata_2320;
        sElse.c0 = 0;
        sElse.c1 = 0;
        sElse.c2 = 0;
        sElse.c3 = 0;
        (*(ObjB**)(*(u8**)(self + 0xd8) + 0x8))->v30(&sElse);
    }
    return (*(ObjA**)(*(u8**)(self + 0xd8) + 0xc))->v4();
}
extern "C" void fn_27_177CE8(void* unused, u8* self, u8* p) {
    Vec3f pos = get_pos(self);
    (*(ObjC**)(*(u8**)(self + 0xd8) + 0x64))->v13(0x21000006, *(f32*)(p + 0x8));
    (*(ObjC**)(*(u8**)(self + 0xd8) + 0x64))->v13(0x21000007, *(f32*)(p + 0xc));
    (*(ObjC**)(*(u8**)(self + 0xd8) + 0x64))->v13(0x21000008, pos.m_x);
    (*(ObjC**)(*(u8**)(self + 0xd8) + 0x64))->v13(0x21000009, pos.m_y);
}
