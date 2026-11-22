#include <types.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" float lbl_27_rodata_78F0;
extern "C" float lbl_27_rodata_78F4;

struct Acc;

class Post {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual int s22();
};

class Ctrl {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4(u32 id);
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10(s32 value, u32 id);
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual int s17(u32 id);
    virtual void s18(u32 id, void* mod);
    virtual void s19(u32 id, float v);
};

struct QBase { char pad0[8]; };
class QObj : public QBase {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual u32 test(u32, u32);
    virtual void s56();
    virtual unsigned long long vec(u32, u32);
    virtual void s58();
};

struct Mod {
    char pad0[0x10];
    QObj* q;
    char pad1[0x64 - 0x14];
    Ctrl* ctrl;
    char pad2[0x7c - 0x68];
    Post* post;
};

struct Acc {
    char pad[0xD8];
    Mod* mod;
};

union VecBits {
    unsigned long long bits;
    struct {
        float x;
        float y;
    } v;
};

struct Vector2 {
    float x;
    float y;
};

class Self {
public:
    virtual void v0();
    virtual void v1(Acc* acc);
    virtual unsigned long long v2();

    void setVector(const Vector2& v) {
        y = v.y;
        x = v.x;
    }

    float unk4;
    float x;
    float y;
    float vx;
    float vy;
};



inline float direction(float x) {
    return x < lbl_27_rodata_78F4 ? -1 : 1;
}
inline void scaleVector(Vector2& v, float scale) {
    v.x *= scale;
}

extern "C" void fn_27_34D3FC(Self* self, Acc* acc) {
    Vector2 sp;
    Vector2 r;
    Vector2 tmp;
    VecBits b;
    VecBits a;
    VecBits t;
    VecBits t2;
    VecBits t3;
    Vector2 tmp2;
    VecBits b2;
    VecBits a2;
    VecBits qr;
    VecBits s;
    if (acc->mod->post->s22() == 0x22 || acc->mod->post->s22() == 0x21) {
        if (acc->mod->ctrl->s17(0x12000004)) {
            a.bits = self->v2();
            float y1 = a.v.y;
            b.bits = self->v2();
            float k = lbl_27_rodata_78F0;
            tmp.x = k * b.v.x;
            tmp.y = y1;
            self->setVector(tmp);
            acc->mod->ctrl->s19(0x12000004, k);
        } else {
            s32 r28 = 1;
            bool f1 = false;
            t.bits = self->v2();
            if (t.v.x >= lbl_27_rodata_78F4) {
                if (acc->mod->q->test(4, 0) != 0) {
                    f1 = true;
                }
            }
            if (!f1) {
                bool f2 = false;
                t2.bits = self->v2();
                if (t2.v.x <= lbl_27_rodata_78F4) {
                    if (acc->mod->q->test(2, 0) != 0) {
                        f2 = true;
                    }
                }
                if (!f2) {
                    r28 = 0;
                }
            }
            if (r28 != 0) {
                t3.bits = self->v2();
                float c = soValueAccesser::getConstantFloat((soModuleAccesser*)acc, 0xFAA, 0);
                if (t3.v.x >= c) {
                    acc->mod->ctrl->s18(0x12000003, acc->mod);
                } else {
                    a2.bits = self->v2();
                    float y2 = a2.v.y;
                    b2.bits = self->v2();
                    float k2 = lbl_27_rodata_78F0;
                    tmp2.x = k2 * b2.v.x;
                    tmp2.y = y2;
                    self->setVector(tmp2);
                    Ctrl* c64 = acc->mod->ctrl;
                    s32 val = soValueAccesser::getConstantInt((soModuleAccesser*)acc, 0x5dc5, 0);
                    c64->s10(val, 0x10000005);
                    Ctrl* c65 = acc->mod->ctrl;
                    s32 lim = soValueAccesser::getConstantInt((soModuleAccesser*)acc, 0x5dc6, 0);
                    if (c65->s4(0x10000005) <= lim) {
                        acc->mod->ctrl->s18(0x12000003, acc->mod);
                    }
                }
            }
        }
    }

    if (acc->mod->post->s22() == 0x22) {
        sp.x = lbl_27_rodata_78F4;
        sp.y = lbl_27_rodata_78F4;
        QObj* q = acc->mod->q;
        if (q->test(8, 0) == 1) {
            qr.bits = acc->mod->q->vec(8, 0);
            ((u32*)&r)[0] = ((u32*)&qr)[0];
            ((u32*)&r)[1] = ((u32*)&qr)[1];
            sp.x = r.x * soValueAccesser::getConstantFloat((soModuleAccesser*)acc, 0xFA7, 0);
            s.bits = self->v2();
            float s1 = direction(s.v.x);
            float s2 = (float)((r.x < lbl_27_rodata_78F4) ? -1 : 1);
            if (s1 != s2) {
                scaleVector(sp, soValueAccesser::getConstantFloat((soModuleAccesser*)acc, 0xFA8, 0));
            } else {
                scaleVector(sp, soValueAccesser::getConstantFloat((soModuleAccesser*)acc, 0xFA9, 0));
            }
        }
        self->vx = sp.x;
        self->vy = sp.y;
    }
    self->v1(acc);
}
