#include <types.h>
#include <ft/ft_common_data_accesser.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/model/so_model_module_simple.h>
#pragma force_active on

extern "C" {
extern const float lbl_95_rodata_98[];
extern const char lbl_95_data_7A88[], lbl_95_data_2C38[], lbl_95_data_81D8[], lbl_95_data_810C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_95_A8B4(float);
void fn_95_10374(void*);
void fn_95_10570(void*, int);
void fn_95_10704(void*);
void fn_95_11ABC(void*, int, float, float, unsigned char, unsigned char, unsigned char, unsigned char);
void fn_95_11ADC(void*, void*);
}

struct Vec2Words { float x, y; static void copy(Vec2Words& dst, const Vec2Words& src) { __memcpy(&dst, &src, sizeof(Vec2Words)); } };
struct Motion { int a; float x, y; unsigned char b, c, d, e; };

struct Fighter { char pad[0xD8]; void* modules; };

struct Obj30 {
    virtual void d0(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual int m5(int); virtual void m6(int, int); virtual void m7(); virtual void m8(int);
    virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual float m13(int);
    virtual void m14(float, int);
};
struct Obj1C {
    virtual void d0(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5();
};
struct Obj29 {
    virtual void d0(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8();
    virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13();
    virtual void m14(); virtual void m15(); virtual void m16(); virtual float m17();
};
struct Obj28 {
    virtual void d0(); virtual void m2(); virtual void m3();
    virtual int m4(); virtual void m5(); virtual int m6(); virtual void m7(int, bool);
};
struct Obj27 {
    virtual void d0(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void* m7(int); virtual void m8();
    virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13();
    virtual Vec2Words m14(const unsigned short&); virtual void m15(); virtual void m16(); virtual void m17();
    virtual void m18(); virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(int, void*);
};
struct Obj26 {
    virtual void d0(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8();
    virtual void m9(); virtual float m10(); virtual void m11(float); virtual void m12(); virtual void m13();
    virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18();
    virtual void m19(); virtual void m20();
};
struct Obj24 {
    virtual void d0(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8();
    virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual float m13();
    virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18();
    virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28();
    virtual void m29(); virtual void m30(); virtual void m31(void*);
};
struct Obj25 {
    virtual void d0(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8();
    virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13();
    virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18();
    virtual void m19(); virtual void m20(int, int); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28();
    virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33();
    virtual void m34(); virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38();
    virtual void m39(); virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48();
    virtual void m49(); virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53();
    virtual void m54(); virtual void m55(); virtual int m56(int, int);
};
struct Obj23 {
    virtual void d0(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8();
    virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13();
    virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18();
    virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(int, float);
};

extern "C" void fn_95_11344(void* unused, Fighter* self) {
    const float* c = lbl_95_rodata_98;
    Obj30* r30 = *(Obj30**)((char*)self->modules + 0x64);
    Obj29* r29 = *(Obj29**)((char*)self->modules + 0x5c);
    Obj28* r28 = *(Obj28**)((char*)self->modules + 0x14);
    Obj27* r27 = *(Obj27**)((char*)self->modules + 0x7c);
    Obj26* r26 = *(Obj26**)((char*)self->modules + 0x0c);
    soGroundModule* r25 = *(soGroundModule**)((char*)self->modules + 0x10);
    Obj24* r24 = *(Obj24**)((char*)self->modules + 0x08);
    soModelModule* r23 = *(soModelModule**)((char*)self->modules + 0x04);
    char* r22 = *(char**)((char*)g_ftCommonDataAccesser.getData((ftKind)4) + 0x7c);
    int r19;
    int r21;
    float f29, f30, f31;
    u16 sp8 = 1;
    Vec2Words b;
    Vec2Words a = r27->m14(sp8);
    Vec2Words::copy(b, a);
    float f28 = r26->m10();
    f30 = r30->m13(0x21000006);
    f31 = r30->m13(0x21000005);
    r21 = r28->m4() == 0;
    float unusedX;
    if (r21 != 0) {
        r19 = r30->m5(0x20000006);
        f29 = r29->m17();
        if (r19 != 0 && c[0] != b.x && fn_95_A8B4(f29) > *(float*)(r22 + 0x54)) {
            if (f29 > c[0]) {
                f29 = c[2];
            } else {
                f29 = c[3];
            }
            if (f28 != f29) {
                Obj1C* o = *(Obj1C**)((char*)self->modules + 0x1c);
                o->m5();
                r30->m14(f29, 0x21000008);
                r30->m14(b.x, 0x21000004);
                r30->m14(c[4] * b.x, 0x21000007);
                r30->m6(0, 0x20000004);
                r30->m6(0x11B, 0x20000008);
                fn_95_10704(self);
            }
        }
    }
    if (c[2] == f28) {
        r19 = r25->isTouch(static_cast<grCollStatus::TouchMask>(4), 0);
        if (r19 != 0) {
            fn_95_10570(self, 4);
        }
    } else {
        r19 = r25->isTouch(static_cast<grCollStatus::TouchMask>(2), 0);
        if (r19 != 0) {
            fn_95_10570(self, 2);
        }
    }
    if (r19 != 0) {
        r30->m6(0x11A, 0x20000008);
        b.x = b.x * -*(float*)(r22 + 0x64);
        b.y = *(float*)(r22 + 0x68);
        r21 = 0;
    } else if (r28->m6() != 0) {
        if (r21 != 0) {
            b.y = fn_95_A8B4(b.y * *(float*)(r22 + 0x6c));
            if (b.y < *(float*)(r22 + 0x70)) {
                Motion motion;
                fn_95_11ABC(&motion, 0x1D5, r24->m13(), c[0], 0, 1, 0, 0);
                r24->m31(&motion);
                fn_95_10374(self);
                if (fn_95_A8B4(f30) < c[5]) {
                    f30 = c[5];
                }
                b.x = f30 * f28;
                b.y = c[0];
                r30->m14(f31 + c[1] * (*(float*)(r22 + 0x90) * fn_95_A8B4(f30)), 0x21000005);
                fn_95_10704(self);
            } else {
                r21 = 0;
                f29 = r29->m17();
                if (fn_95_A8B4(f29) > *(float*)(r22 + 0x54)) {
                    if (f29 > c[0]) {
                        f28 = c[2];
                    } else {
                        f28 = c[3];
                    }
                    f30 = *(float*)(r22 + 0x74) * fn_95_A8B4(f29);
                    b.x = f30 * f28;
                    r26->m11(f28);
                    r26->m20();
                    r23->setNodeRotateY(3, c[0]);
                }
                fn_95_10704(self);
            }
            r30->m6(0, 0x20000002);
        } else {
            Motion motion;
            fn_95_11ABC(&motion, 0x1D8, r24->m13(), c[0], 0, 1, 0, 0);
            r24->m31(&motion);
            fn_95_10704(self);
        }
    }
    r30->m14(fn_95_A8B4(b.x), 0x21000006);
    if (r21 != 0) {
        r28->m7(0, false);
        r25->setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(1), 0);
        r27->m22(0x64, self);
        void* energy = __dynamic_cast(r27->m7(3), 0, lbl_95_data_7A88, lbl_95_data_2C38, 1);
        Vec2Words cc;
        cc.x = b.x;
        cc.y = c[0];
        fn_95_11ADC(energy, &cc);
        r30->m8(0x20000006);
        return;
    }
    r28->m7(2, false);
    r25->setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(5), 0);
    r27->m22(0x65, self);
    void* dyn1 = __dynamic_cast(r27->m7(2), 0, lbl_95_data_81D8, lbl_95_data_2C38, 1);
    void* dyn2 = __dynamic_cast(r27->m7(1), 0, lbl_95_data_810C, lbl_95_data_2C38, 1);
    Vec2Words d;
    d.x = b.x;
    d.y = c[0];
    fn_95_11ADC(dyn1, &d);
    *(float*)((char*)dyn2 + 0xc) = b.y;
    r30->m6(0, 0x20000006);
}
