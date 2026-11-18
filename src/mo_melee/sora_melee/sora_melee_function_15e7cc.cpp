#pragma force_active on
#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct Vec2 {
    f32 x;
    f32 y;
};

union VectorResult {
    u64 bits;
    Vec2 value;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual VectorResult slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();

    int unk4;
    Vec2 pos;
    Vec2 v10;
    Vec2 v18;
    Vec2 v20;
    Vec2 v28;
    int pad30;
    int state;
    u8 f38;
    u8 f39;
};

extern "C" {
extern const float lbl_27_rodata_1FA0[];
u64 fn_27_89A90(Vec2* p, soModuleAccesser* acc);
float rsqrtf__Ff(float x);
}

extern "C" void fn_27_15E7CC(Object_vptr_0* self, u32 kind, const Vec2* src, u32 unused, soModuleAccesser* acc) {
    const float* c = lbl_27_rodata_1FA0;
    VectorResult results[7];
    f32 len2;
    f32 m;
    self->slot6();
    self->state = -1;
    Vec2 i0 = {c[1], c[1]};
    self->v10 = i0;
    Vec2 i1 = {c[1], c[1]};
    self->v18 = i1;
    Vec2 i2 = {c[1], c[1]};
    self->v20 = i2;
    Vec2 i3 = {((const Vec2*)(c + 1))[-1].y, ((const Vec2*)(c + 1))[-1].y};
    self->v28 = i3;
    self->pos = *src;
    self->state = (int)kind;

    switch (kind) {
    case 0:
    case 13:
    case 14:
    case 15: {
        VectorResult q;
        VectorResult t = self->slot2();
        q.bits = fn_27_89A90(&t.value, acc);
        results[6] = q;
        self->pos = results[6].value;
        f32 s = soValueAccesser::getConstantFloat(acc, 0xbbc, 0);
        if ((int)kind == 13) {
            s *= soValueAccesser::getConstantFloat(acc, 0xcc4, 0);
        } else if ((int)kind == 14) {
            s *= soValueAccesser::getConstantFloat(acc, 0xd76, 0);
        } else if ((int)kind == 15) {
            s *= soValueAccesser::getConstantFloat(acc, 0xd74, 0);
        }
        len2 = results[6].value.x * results[6].value.x + results[6].value.y * results[6].value.y;
        if ((f32)(f64)nw4r::math::FAbs(len2) <= c[2]) {
            m = c[1];
        } else {
            m = len2 * rsqrtf__Ff(len2);
        }
        if (m > soValueAccesser::getConstantFloat(acc, 0xbbb, 0)) {
            s *= soValueAccesser::getConstantFloat(acc, 0xc2f, 0);
        }
        Vec2 a = {s, c[1]};
        self->v20 = a;
        Vec2 b = {soValueAccesser::getConstantFloat(acc, 0xbc2, 0), c[1]};
        self->v28 = b;
        break;
    }
    case 17: {
        VectorResult q;
        VectorResult t = self->slot2();
        q.bits = fn_27_89A90(&t.value, acc);
        results[5] = q;
        self->pos = results[5].value;
        Vec2 b = {soValueAccesser::getConstantFloat(acc, 0xbc2, 0), c[1]};
        self->v28 = b;
        break;
    }
    case 18: {
        VectorResult q;
        VectorResult t = self->slot2();
        q.bits = fn_27_89A90(&t.value, acc);
        results[4] = q;
        self->pos = results[4].value;
        Vec2 a = {soValueAccesser::getConstantFloat(acc, 0xbbc, 0) * (soValueAccesser::getConstantFloat(acc, 0xc38, 0)), c[1]};
        self->v20 = a;
        Vec2 b = {soValueAccesser::getConstantFloat(acc, 0xbc2, 0), c[1]};
        self->v28 = b;
        break;
    }
    case 1:
    case 11:
    case 23: {
        if ((int)kind != 23) {
            VectorResult q;
            VectorResult t = self->slot2();
            q.bits = fn_27_89A90(&t.value, acc);
            results[3] = q;
            self->pos = results[3].value;
        }
        Vec2 a = {soValueAccesser::getConstantFloat(acc, 0xbbc, 0) * soValueAccesser::getConstantFloat(acc, 0xcdd, 0), c[1]};
        self->v20 = a;
        Vec2 b = {soValueAccesser::getConstantFloat(acc, 0x7db, 0), c[1]};
        self->v28 = b;
        break;
    }
    case 21: {
        VectorResult q;
        VectorResult t = self->slot2();
        q.bits = fn_27_89A90(&t.value, acc);
        results[2] = q;
        self->pos = results[2].value;
        Vec2 a = {soValueAccesser::getConstantFloat(acc, 0xbbc, 0) * soValueAccesser::getConstantFloat(acc, 0xcb7, 0), c[1]};
        self->v20 = a;
        Vec2 b = {soValueAccesser::getConstantFloat(acc, 0x7db, 0), c[1]};
        self->v28 = b;
        break;
    }
    case 8: {
        Vec2 b = {soValueAccesser::getConstantFloat(acc, 0xbd8, 0), c[1]};
        self->v28 = b;
        Vec2 a = {soValueAccesser::getConstantFloat(acc, 0xc4e, 0), c[1]};
        self->v20 = a;
        break;
    }
    case 6:
    case 7: {
        Vec2 b = {soValueAccesser::getConstantFloat(acc, 0xbd8, 0), c[1]};
        self->v28 = b;
        Vec2 a = {soValueAccesser::getConstantFloat(acc, 0xbd6, 0), c[1]};
        self->v20 = a;
        break;
    }
    case 19: {
        Vec2 b = {soValueAccesser::getConstantFloat(acc, 0xbd8, 0), c[1]};
        self->v28 = b;
        Vec2 a = {soValueAccesser::getConstantFloat(acc, 0xbd6, 0), c[1]};
        self->v20 = a;
        c = (const float*)soValueAccesser::getConstantIndefinite(acc, 0xa80b, 0);
        VectorResult p = self->slot2();
        results[1] = p;
        f32 y = results[1].value.y;
        Vec2 r = {results[1].value.x * c[4], y};
        self->pos = r;
        break;
    }
    case 16: {
        Vec2 b = {soValueAccesser::getConstantFloat(acc, 0xc14, 0), c[1]};
        self->v28 = b;
        Vec2 a = {soValueAccesser::getConstantFloat(acc, 0xc15, 0), c[1]};
        self->v20 = a;
        break;
    }
    case 20: {
        VectorResult q;
        VectorResult t = self->slot2();
        q.bits = fn_27_89A90(&t.value, acc);
        results[0] = q;
        self->pos = results[0].value;
        Vec2 a = {soValueAccesser::getConstantFloat(acc, 0xbbc, 0) * soValueAccesser::getConstantFloat(acc, 0xcba, 0), c[1]};
        self->v20 = a;
        Vec2 b = {soValueAccesser::getConstantFloat(acc, 0xbc2, 0), c[1]};
        self->v28 = b;
        break;
    }
    case 2:
    case 3:
    case 4:
    case 5:
    case 9:
    case 10:
    case 12:
    case 22:
        break;
    default:
        return;
    }

    self->f38 = 0;
    self->f39 = 0;
}
