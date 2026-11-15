#pragma force_active on
#pragma fp_contract off
#include <types.h>
#include <math.h>
#include <mt/mt_vector.h>

#define P10(x) virtual void x##0(); virtual void x##1(); virtual void x##2(); virtual void x##3(); virtual void x##4(); virtual void x##5(); virtual void x##6(); virtual void x##7(); virtual void x##8(); virtual void x##9()
#define P7(x) virtual void x##0(); virtual void x##1(); virtual void x##2(); virtual void x##3(); virtual void x##4(); virtual void x##5(); virtual void x##6()
#define P6(x) virtual void x##0(); virtual void x##1(); virtual void x##2(); virtual void x##3(); virtual void x##4(); virtual void x##5()
#define P5(x) virtual void x##0(); virtual void x##1(); virtual void x##2(); virtual void x##3(); virtual void x##4()
#define P3(x) virtual void x##0(); virtual void x##1(); virtual void x##2()
#define P9(x) virtual void x##0(); virtual void x##1(); virtual void x##2(); virtual void x##3(); virtual void x##4(); virtual void x##5(); virtual void x##6(); virtual void x##7(); virtual void x##8()

class VStatus {
public:
    P10(a);
    P6(b);
    virtual s32 get();
};

class VRate {
public:
    P9(a);
    virtual f32 get();
};

class VRead {
public:
    P10(a);
    P3(b);
    virtual Vec2f get(u16*);
};

struct Pad8 {
    char pad[8];
};

class VAnim : public Pad8 {
public:
    P10(a);
    P10(b);
    P10(c);
    P10(d);
    P10(e);
    P10(f);
    P10(g);
    P10(h);
    P10(i);
    P10(j);
    P5(k);
    virtual void set(s32, s32, s32);
};

class VMove {
public:
    P6(a);
    virtual void set(s32, f32*, f32*, s32, s32, f32);
};

class VController {
public:
    P10(a);
    P10(b);
    P6(c);
    virtual void set(s32, f32*);
};

class VFinal {
public:
    P10(a);
    P10(b);
    P10(c);
    P10(d);
    P10(e);
    P5(f);
    virtual void set(s32, s32, s32, s32);
};

class VParam {
public:
    P10(a);
    P10(b);
    P10(c);
    virtual void set(void*);
};

class VWork {
public:
    P5(a);
    virtual void set(s32, s32);
    P7(b);
    virtual void set2(s32);
};

class VHigh {
public:
    P10(a);
    P10(b);
    P7(c);
    virtual s32 get(s32, s32);
};

struct Modules {
    char p0[8];
    VParam* m8;
    VRate* mc;
    VAnim* m10;
    char p14[0xc];
    VHigh* m20;
    char p24[0x38];
    VFinal* m5c;
    VController* m60;
    VWork* m64;
    char p68[8];
    VStatus* m70;
    char p74[8];
    VRead* m7c;
    char p80[8];
    VMove* m88;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

struct MotionParam {
    s32 kind;
    f32 first, second;
    s8 a, b, c, d;
};

struct Vec3 {
    f32 x, y, z;
};

extern "C" const f32 lbl_27_rodata_21F0[];
extern "C" void fn_27_16AD28(void*, Object*);
extern "C" void fn_27_19397C(Object*, s32, f32, f32, f32);
extern "C" s32 fn_27_195528(Object*, f32*, f32*);
extern "C" f32 getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Object*, u32, u32);
extern "C" s32 getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(Object*, u32, u32);

extern "C" void fn_27_16E5A0(void* self, Object* obj) {
    const f32* c = lbl_27_rodata_21F0;
    s32 status = obj->modules->m70->get();
    fn_27_16AD28(self, obj);

    switch (status) {
    case 0x55:
        goto body;
    default:
        goto done;
    }

body:
    u32 facing;
    {
        u16 type = 2;
        Vec2f value;
        Vec2f::copy(value, obj->modules->m7c->get(&type));
        facing = value.m_x < c[0];
    }

    f32 rate = obj->modules->mc->get();
    f32 scale = facing == 1 ? c[1] : c[2];

    if (rate * scale > c[0]) {
        MotionParam p;
        p.kind = 0xd0;
        p.first = c[0];
        p.second = c[2];
        p.a = 0;
        p.b = 0;
        p.c = 0;
        p.d = 0;
        obj->modules->m8->set(&p);
        fn_27_19397C(obj, 0, scale, scale, c[2]);
    } else {
        obj->modules->m10->set(6, 1, 0);
        MotionParam p;
        p.kind = 0xa5;
        p.first = c[0];
        p.second = c[2];
        p.a = 0;
        p.b = 0;
        p.c = 0;
        p.d = 0;
        obj->modules->m8->set(&p);
    }

    (void)getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(obj, 0xcd6, 0);
    obj->modules->m64->set2(0x21000008);

    VWork* work = obj->modules->m64;
    s32 direction = 2;
    if (facing == 1)
        direction--;
    work->set(direction, 0x20000001);

    s32 count = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(obj, 0x5a34, 0);
    obj->modules->m20->get(count, 0);

    {
        f32 a[2], b[2];
        if (fn_27_195528(obj, a, b)) {
            double angleDouble = atan2(-b[0], b[1]);
            Vec3 pos;
            Vec3 rot;
            f32 x, y;
            y = a[1];
            x = a[0];
            f32 angle = (f32)angleDouble;
            rot.x = c[0];
            rot.y = c[0];
            rot.z = angle;
            pos.x = x;
            pos.y = y;
            pos.z = c[0];
            obj->modules->m88->set(9, (f32*)&pos, (f32*)&rot, 0, -1, c[2]);
            Vec3 v = {a[0], a[1], c[0]};
            obj->modules->m60->set(0, (f32*)&v);
        }
    }

    obj->modules->m5c->set(8, 0, 1, -1);

done:
    ;
}
