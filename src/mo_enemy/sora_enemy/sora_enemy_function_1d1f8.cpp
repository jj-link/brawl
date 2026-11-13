#include <types.h>
#include <math.h>
#include <mt/mt_vector.h>
#include <mt/mt_matrix.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <gr/gr_gimmick_motion_path.h>
#pragma force_active on

struct V2 {
    float x;
    float y;
};

struct I2 {
    int x;
    int y;
};

struct W2 {
    float x;
    float y;
    W2(float a, float b) : x(a), y(b) {}
};

struct S {
    char p0[8];
    int state;
    char p0c[8];
    float f14;
    char p18[4];
    float f1C;
    char p20[4];
    float f24;
    char p28[0x1C];
    float f44;
    char p48[4];
    float f4C;
    char p50[0xC];
    float f5C;
    char p60[0xC];
    float f6C;
    char p70[4];
    int i74;
    float f78;
    float f7C;
    char p80[0xC];
    int i8C;
    void* p90;
    char f94[12];
    char fA0[12];
    char pAC[4];
    unsigned char b0;
    char pB1[3];
    V2 b4;
    char bc[12];
};

struct VM {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual Vec3f v5();
    virtual void v6(Vec3f*);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual float v14();
    virtual Vec3f v15(int);
    virtual void v16(Vec3f*, int);
    virtual void v17();
    virtual void* v18(u32);
    virtual float v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual int v56(u32, u32);
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual int v70();
    virtual Vec3f v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual Vec3f v76();
};

struct VM2 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(u32);
};

struct Pad8 {
    int a;
    int b;
};

struct VMB : Pad8 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual float v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual u32 v56(u32, u32);
};

extern "C" {
extern const float lbl_41_rodata_C90[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern char lbl_41_data_644[];
extern char lbl_41_data_6A8[];
void* __dynamic_cast(const void*, int, const void*, const void*, short);
float fn_41_1E60C(float, float);
float fn_41_1E658(void*, float, float);
float fn_41_1EC18(void*, soModuleAccesser*, float, int);
V2 fn_41_1E5B0(float, float, float);
void fn_41_1BEA8(void*, const void*);
void fn_41_1BEBC(const void*, const void*, void*);
void fn_41_1CFC8(void*, soModuleAccesser*, void*, void*, float, float);
void fn_41_1DC24(void*);
int fn_41_1DC40(void*, const void*);
void fn_41_534C(void*, const void*);
void* fn_41_5AC4(void*, float, float, float);
void fn_41_4D14(void*, const void*, const void*);
void fn_41_6270(void*, void*, void*);
void fn_41_6354(void*, float);
void fn_8003DC64(void*, float, void*);
void fn_8003E3BC(void*, void*, void*);
void fn_8003ECA0(void*, float, float, float);
void* fn_41_2354(void*, float, float);
void fn_41_1E768(void*, soModuleAccesser*, int, float, int, int);
I2 fn_41_15A90(soModuleAccesser*, void*, int);
I2 fn_41_15C3C(soModuleAccesser*, void*, int);
float fn_41_15A00(float, const void*);
void fn_41_16094(void*, int, float);
float fn_41_161B4(void*, int);
int fn_41_1AE30(int);
void fn_41_1EF60(void*, float);
float fn_41_10830(void*);
void setFrame__19grGimmickMotionPathFf(void*, float);
void getTRS__19grGimmickMotionPathFP5Vec3fP5Vec3fP5Vec3f(void*, Vec3f*, Vec3f*, Vec3f*);
}

inline VM* modAt(soModuleAccesser* a, int off) {
    return *reinterpret_cast<VM* const*>(reinterpret_cast<const char*>(a->m_enumerationStart) + off);
}

inline VMB* modB(soModuleAccesser* a, int off) {
    return *reinterpret_cast<VMB* const*>(reinterpret_cast<const char*>(a->m_enumerationStart) + off);
}

extern "C" void fn_41_1D1F8(S* self, soModuleAccesser* accesser, u32 arg2) {
    const float* c = lbl_41_rodata_C90;
    VM* const r30 = modAt(accesser, 0xC);
    Vec3f v158, v14C, v140, v134, v128, v11C, v110, v104;
    V2 v6C;
    I2 b, b2;
    float v8;

    if (arg2 == 1) {
        self->f4C = self->f4C + self->f14;
        float a = fn_41_1E60C(self->f4C, self->f24);
        self->f4C = a;
        self->f4C = fn_41_1E658(self, (float)(double)a, self->f1C);
    }

    u32 sw = self->state;
    switch (sw) {
    case 0:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13: {
        V2 t = fn_41_1E5B0(self->f4C,
                           fn_41_1EC18(self, accesser, self->f6C, self->i8C),
                           self->f7C);
        fn_41_1BEA8(&self->b4, &t);
        break;
    }
    case 21:
    case 22: {
        setFrame__19grGimmickMotionPathFf(self->p90, self->f78);
        getTRS__19grGimmickMotionPathFP5Vec3fP5Vec3fP5Vec3f(self->p90, &v158, &v14C, (Vec3f*)&v8);
        float f31 = soValueAccesser::getValueFloat(accesser, 0xBEF, 0);
        float f1 = soValueAccesser::getValueFloat(accesser, 0xBEE, 0);
        fn_41_5AC4(&v140, f1, f31, c[3]);
        fn_41_1BEBC(&v158, &v140, &v104);
        Vec3f vF8 = r30->v5();
        fn_41_4D14(&v134, &v104, &vF8);
        W2 w(v134.m_x, v134.m_y);
        fn_41_1BEA8(&self->b4, &w);
        if (arg2 == 1) {
            if (self->state == 0x16) {
                fn_41_4D14(&v128, &v158, self->fA0);
                float f1b = self->f44 * (float)fabs(self->f4C);
                Vec3f vEC = v128;
                fn_41_1CFC8(self, accesser, r30, &vEC, f1b, c[3]);
            }
            fn_41_534C(self->f94, &v14C);
            fn_41_534C(self->fA0, &v158);
        }
        break;
    }
    case 1:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 23:
    case 24: {
        void* r26 = modAt(accesser, 0x8);
        if (static_cast<VM*>(r26)->v70() != 0) {
            static_cast<VM*>(r26)->v69();
            fn_41_5AC4(&v11C, c[3], c[3], c[3]);
            if (self->state == 0x18) {
                static_cast<VM*>(r26)->v73();
                Vec3f vE0 = static_cast<VM*>(r26)->v76();
                fn_41_534C(&v11C, &vE0);
            } else {
                Vec3f vD4 = static_cast<VM*>(r26)->v71();
                fn_41_534C(&v11C, &vD4);
            }
            v6C.x = c[3];
            v6C.y = c[3];
            if (self->state == 0x17) {
                if (arg2 == 1) {
                    void* r25 = __dynamic_cast(accesser->m_stageObject, 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
                    r26 = modAt(accesser, 0x64)->v18(0x12000003);
                    r30->v19();
                    fn_41_6270(&v110, r25, r26);
                    Matrix m164;
                    Vec3f vC8;
                    fn_41_534C(&vC8, &v110);
                    fn_41_6354(&vC8, c[19]);
                    fn_8003ECA0(&m164, vC8.m_x, vC8.m_y, vC8.m_z);
                    fn_8003E3BC(&m164, &v11C, &v11C);
                    modB(accesser, 0xB8)->v14();
                    fn_41_1DC24(&v11C);
                    Vec3f vBC = r30->v5();
                    fn_41_1BEBC(&v11C, &vBC, &v11C);
                    r30->v6(&v11C);
                    V2 v44;
                    v44.x = c[3];
                    v44.y = c[3];
                    fn_41_1BEA8(&self->b4, &v44);
                }
            } else {
                void* p = modAt(accesser, 0x64)->v18(0x12000003);
                if (p == 0) {
                    v11C.m_x = v11C.m_z * self->f7C;
                } else {
                    float ax = self->f7C * (float)fabs(v11C.m_x);
                    v11C.m_x = ax;
                }
                float f31 = fn_41_1EC18(self, accesser, self->f6C, self->i8C);
                V2 v3C;
                void* t3c = fn_41_2354(&v3C, v11C.m_x, v11C.m_y);
                fn_8003DC64(t3c, c[20] * (f31 * self->f7C), &v6C);
                fn_41_1BEA8(&self->b4, &v6C);
            }
        }
        break;
    }
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7: {
        Vec3f vB0;
        fn_41_1E768(&vB0, accesser, sw, self->f4C, self->i8C, 1);
        fn_41_534C(self->bc, &vB0);
        if (arg2 == 1) {
            modB(accesser, 0xB8)->v14();
            fn_41_1DC24(self->bc);
            Vec3f vA4 = r30->v15(self->i8C);
            fn_41_1BEBC(self->bc, &vA4, self->bc);
            r30->v16(reinterpret_cast<Vec3f*>(self->bc), self->i8C);
            Vec3f v98;
            void* p = fn_41_5AC4(&v98, c[3], c[3], c[3]);
            fn_41_534C(self->bc, p);
        }
        break;
    }
    case 20: {
        if (arg2 == 1) {
            void* r25 = __dynamic_cast(modAt(accesser, 0x7C), 0, lbl_41_data_644, lbl_41_data_6A8, 1);
            float f31 = fn_41_161B4(r25, self->i74);
            float f1 = modB(accesser, 0xB8)->v14();
            f31 = f31 + self->f4C * f1;
            while (f31 > c[1]) {
                f31 -= c[1];
            }
            while (f31 < c[3]) {
                f31 = c[1] + f31;
            }
            if (c[1] == f31) {
                f31 = c[3];
            }
            fn_41_16094(r25, self->i74, f31);
            fn_41_1EF60(self, f31);
        }
        break;
    }
    default:
        break;
    }

    if (fn_41_1AE30(self->state) == 0) {
        float f1 = fn_41_10830(&self->b4);
        if (c[3] != f1 && arg2 == 1) {
            VM2* o64 = reinterpret_cast<VM2*>(modAt(accesser, 0x64));
            if (o64->v5(0x10000004) == 0) {
                if (modAt(accesser, 0x14)->v4() == 0) {
                    I2 a = fn_41_15A90(accesser, &self->b4, 8);
                    b = a;
                    if (fn_41_1DC40(&self->b4, &b) != 0) {
                        fn_41_1BEA8(&self->b4, &b);
                        V2 v2c = self->b4;
                        self->f5C = fn_41_15A00(self->f7C, &v2c);
                    }
                } else {
                    float f31 = fn_41_1EC18(self, accesser, self->f5C, self->i8C);
                    float f1b = fn_41_10830(&self->b4);
                    V2 v24 = fn_41_1E5B0(f1b, f31, self->f7C);
                    fn_41_1BEA8(&self->b4, &v24);
                    self->f6C = self->f5C;
                }
            }
        }
    }

    if (self->b0 == 1) {
        float f1 = fn_41_10830(&self->b4);
        if (c[3] != f1 && arg2 == 1) {
            if (modB(accesser, 0x10)->v56(0xff, 0) == 1) {
                I2 a2 = fn_41_15C3C(accesser, &self->b4, 0xff);
                b2 = a2;
                if (fn_41_1DC40(&self->b4, &b2) != 0) {
                    fn_41_1BEA8(&self->b4, &b2);
                    V2 v14 = self->b4;
                    self->f5C = fn_41_15A00(self->f7C, &v14);
                }
            } else {
                float f31 = fn_41_1EC18(self, accesser, self->f5C, self->i8C);
                float f1b = fn_41_10830(&self->b4);
                V2 v0C = fn_41_1E5B0(f1b, f31, self->f7C);
                fn_41_1BEA8(&self->b4, &v0C);
                self->f6C = self->f5C;
            }
        }
    }

    {
        if (self->state != 0 && self->state != 1 && self->state != 0x17 && self->state != 0x18 && self->state != 0x15 && self->state != 0x16) {
            if (fn_41_1AE30(self->state) == 0 && self->f44 > c[3] && self->i8C >= 0) {
                float f31 = c[21] * (c[16] * self->f44);
                f31 = c[1] * (self->f4C / f31);
                u32 r25;
                switch (self->state - 8) {
                case 0:
                case 6:
                    r25 = 2;
                    break;
                case 1:
                case 7:
                    r25 = 3;
                    break;
                case 2:
                case 8:
                    r25 = 4;
                    break;
                case 3:
                case 9:
                    r25 = 5;
                    break;
                case 4:
                case 10:
                    r25 = 6;
                    break;
                case 5:
                case 11:
                    r25 = 7;
                    break;
                default:
                    return;
                }
                if (r25 - 2 <= 2) {
                    VM* m19 = modAt(accesser, 0xC);
                    float f30 = c[12];
                    if (c[14] != m19->v19()) {
                        f30 = c[0];
                    }
                    if (self->f7C != f30) {
                        f31 = c[0] * f31;
                    }
                }
                Vec3f v8C;
                fn_41_1E768(&v8C, accesser, r25, f31, self->i8C, 1);
                fn_41_534C(self->bc, &v8C);
                if (arg2 == 1) {
                    Vec3f v80 = r30->v15(self->i8C);
                    fn_41_1BEBC(self->bc, &v80, self->bc);
                    r30->v16(reinterpret_cast<Vec3f*>(self->bc), self->i8C);
                    Vec3f v74;
                    void* p = fn_41_5AC4(&v74, c[3], c[3], c[3]);
                    fn_41_534C(self->bc, p);
                }
            }
        }
    }
}
