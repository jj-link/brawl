#include <types.h>
#pragma force_active on
#pragma always_inline on

extern const f32 lbl_27_rodata_5FC0;
extern const f32 lbl_27_rodata_5FC4;
extern const u8 lbl_27_data_7A370[];
extern const u8 lbl_27_data_7A400[];

union Range {
    struct { f32 x, y; } values;
    struct { u32 x, y; } bits;
    Range(f32 a, f32 b) { values.x = a; values.y = b; }
};

class Obj {
public:
    virtual void vf0() = 0; virtual void vf1() = 0; virtual void vf2() = 0;
    virtual void vf3() = 0; virtual void vf4() = 0; virtual void vf5() = 0;
    virtual void vf6() = 0; virtual void vf7() = 0; virtual void vf8() = 0;
    virtual void vf9() = 0; virtual void vf10() = 0; virtual void vf11() = 0;
    virtual void vf12() = 0; virtual void vf13() = 0; virtual void vf14() = 0;
    u8 b4;
    u8 flag : 1;
    u8 rest : 7;
    u8 b6, pad;
    Range pos, a, b, c, d;
    bool b30, b31;
    s32 pad34, i38;

    void init(const Range& p, const Range& a0, const Range& b0,
              const Range& c0, const Range& d0, bool f, bool g) {
        *(const void**)this = lbl_27_data_7A370;
        b4 = 0;
        flag = true;
        b6 = 0;
        pos = p;
        a = a0;
        b = b0;
        c = c0;
        d = d0;
        b30 = f;
        b31 = g;
        pad34 = 0x3f;
    }
};

extern "C" void* fn_27_2BF178(Obj* self) {
    self->init(Range(lbl_27_rodata_5FC4, lbl_27_rodata_5FC4),
               Range(lbl_27_rodata_5FC4, lbl_27_rodata_5FC4),
               Range(lbl_27_rodata_5FC4, lbl_27_rodata_5FC4),
               Range(lbl_27_rodata_5FC4, lbl_27_rodata_5FC4),
               Range(lbl_27_rodata_5FC0, lbl_27_rodata_5FC0),
               false, false);
    *(const void**)self = lbl_27_data_7A400;
    self->i38 = -1;
    self->vf12();
    return self;
}
