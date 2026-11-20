#include <types.h>
#include <nw4r/ut/ut_algorithm.h>
#include <mt/mt_common.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern const f32 lbl_27_rodata_5FC0[];

struct Vec2 { f32 x, y; };
struct Raw { u32 a, b; };

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
};
struct Mods {
    char pad[0x14];
    Object_vptr_0* p14;
};
struct Acc {
    char pad[0xd8];
    Mods* mods;
};
class Obj {
public:
    virtual void isNull();
    virtual void fn_27_2BF344();
    virtual Vec2 fn_27_2B52C0();
    virtual void fn_27_7FCF8();

    u32 pad4;
    Vec2 pos, a, b, c, d;
    u32 pad30, pad34;
    s32 i38;
};
extern "C" void fn_27_2BDFE4(Obj*, Acc*);

extern "C" void fn_27_2BF344(Obj* self, Acc* acc) {
    const f32* k = lbl_27_rodata_5FC0;
    Vec2 r2, lim, s2;
    Vec2 in = self->fn_27_2B52C0();
    f32 sum = in.x * in.x + in.y * in.y;
    f32 len;
    if ((f32)(double)nw4r::ut::Abs(sum) <= k[2]) {
        len = k[1];
    } else {
        len = sum * rsqrtf(sum);
    }
    if (len <= k[3]) {
        Vec2 z0;
        z0.x = k[1];
        z0.y = k[1];
        self->a = z0;
    } else if (len > k[3]) {
        f32 dead;
        if (acc->mods->p14->slot3() == 0) {
            dead = soValueAccesser::getConstantFloat((soModuleAccesser*)acc, 0xd6c, 0);
            Vec2 t;
            t.x = dead;
            t.y = self->c.y;
            self->c = t;
        } else {
            dead = soValueAccesser::getConstantFloat((soModuleAccesser*)acc, 0xd6b, 0);
            Vec2 t;
            t.x = dead;
            t.y = self->c.y;
            self->c = t;
        }
        f32 rem = len - dead;
        if (rem < k[1]) {
            if (self->i38 == 10) {
                Vec2 r = self->fn_27_2B52C0();
                *(Raw*)&r2 = *(Raw*)&r;
                *(Raw*)&lim = *(Raw*)&self->b;
                r2.x = r2.x * k[0];
                r2.y = r2.y * k[0];
                if (r2.x > k[1]) r2.x -= lim.x;
                if (r2.x < k[1]) r2.x += lim.x;
                if (r2.y > k[1]) r2.y -= lim.y;
                if (r2.y < k[1]) r2.y += lim.y;
                self->a = r2;
            } else {
                Vec2 z;
                z.x = k[1];
                z.y = k[1];
                self->a = z;
            }
        } else {
            Vec2 s3;
            Vec2 v = self->fn_27_2B52C0();
            f32 m = rem / len - k[4];
            Vec2 s;
            s.x = v.x * m;
            s.y = v.y * m;
            *(Raw*)&s3 = *(Raw*)&s;
            *(Raw*)&s2 = *(Raw*)&s;
            self->a = s2;
        }
    }
    fn_27_2BDFE4(self, acc);
}