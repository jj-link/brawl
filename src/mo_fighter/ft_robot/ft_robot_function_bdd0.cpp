#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_120_rodata_8;
extern "C" const float lbl_120_rodata_10;

struct FtRobotObj {
    u8 pad0[0x8];
    Vec2f v8;
    Vec2f v10;
    Vec2f v18;
    Vec2f v20;
    Vec2f v28;
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" Vec2f* fn_120_BDBC(Vec2f* dst, const Vec2f* src);

extern "C" void fn_120_BDD0(FtRobotObj* self) {
    Vec2f a(lbl_120_rodata_8, lbl_120_rodata_8);
    Vec2f* r = fn_120_BDBC(&self->v20, &a);
    r = fn_120_BDBC(&self->v10, r);
    fn_120_BDBC(&self->v8, r);
    Vec2f b(lbl_120_rodata_10, lbl_120_rodata_10);
    r = fn_120_BDBC(&self->v28, &b);
    fn_120_BDBC(&self->v18, r);
    self->flag31 = 0;
    self->flag30 = 0;
    self->flag32 = 1;
}
