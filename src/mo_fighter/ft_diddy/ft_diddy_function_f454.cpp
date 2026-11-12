#pragma force_active on
#include <types.h>
#include <ft/ft_common_data_accesser.h>
#include <nw4r/math/math_arithmetic.h>

struct DiddyParams {
    char pad0[0x64];
    float f64, f68, f6c, f70;
    char rest[0x2E4 - 0x74];
};

class ObjA {
public:
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual int m4();
    virtual void p5();
    virtual unsigned int m6();
};

class ObjB {
public:
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual int m5(unsigned long);
    virtual void m6(int, unsigned long);
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual float m13(unsigned long);
    virtual void m14(float, unsigned long);
};

class ObjC {
public:
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual float m17();
};

class ObjD {
public:
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual float m10();
};

class ObjE {
public:
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void* m7(int);
};

class ObjR {
public:
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual float m13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual float m23();
    virtual float m24();
    virtual void m25();
    virtual void m26(float);
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void m34(int, int, float, float);
    virtual void m35();
    virtual void p36();
    virtual void p37();
    virtual int m38();
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
void fn_115_F0A8(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getParam__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern const float lbl_115_rodata_60[];
extern const char lbl_115_data_7524[], lbl_115_data_2760[];
}

static inline char* getModules(void* self) {
    return *(char**)((char*)self + 0xd8);
}

static inline ObjA* getA(void* self) {
    return *(ObjA**)(getModules(self) + 0x14);
}

static inline ObjB* getB(void* self) {
    return *(ObjB**)(getModules(self) + 0x64);
}

static inline ObjC* getC(void* self) {
    return *(ObjC**)(getModules(self) + 0x5c);
}

static inline ObjD* getD(void* self) {
    return *(ObjD**)(getModules(self) + 0x0c);
}

static inline ObjE* getE(void* self) {
    return *(ObjE**)(getModules(self) + 0x7c);
}

static inline ObjR* getR(void* self) {
    return *(ObjR**)(getModules(self) + 0x08);
}

extern "C" void fn_115_F454(void* unused, void* self) {
    const float* rod = lbl_115_rodata_60;

    if (getA(self)->m6() == 1) {
        if (getA(self)->m4() != 0)
            fn_115_F0A8(self);
    } else if (getA(self)->m4() != 0) {
        DiddyParams params =
            *(DiddyParams*)getParam__20ftCommonDataAccesserCF6ftKind(
                &g_ftCommonDataAccesser, 0x1b);
        void* p = __dynamic_cast(
            getE(self)->m7(1), 0, lbl_115_data_7524,
            lbl_115_data_2760, 1);
        *(float*)((char*)p + 0x10) = -params.f64;
        *(float*)((char*)p + 0x14) = params.f68;
        *(float*)((char*)p + 0x18) = params.f6c;
        *(float*)((char*)p + 0x1c) = params.f70;
    }

    ObjR* const r30 = getR(self);
    float f30 = getB(self)->m13(0x21000004);
    float f29 = getC(self)->m17() - f30;
    float f31 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        self, 0xFAD, 0);
    f29 = (f29 *
           getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
               self, 0xFAC, 0)) / f31;
    f29 = f30 + f29;
    float absV = (float)(double)nw4r::math::FAbs(f29);
    getB(self)->m14(f29, 0x21000004);

    if (absV < getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                   self, 0xC4B, 0)) {
        r30->m35();
        r30->m26((rod[1] - absV) - r30->m24());
        getB(self)->m6(-1, 0x20000001);
    } else {
        int r27, r26;
        if (getA(self)->m4() == 0) {
            r27 = 0x1e8;
            r26 = 0x1ea;
        } else {
            r27 = 0x1e9;
            r26 = 0x1eb;
        }

        int r28 = getB(self)->m5(0x20000001);
        float t = f29 * getD(self)->m10();
        r27 = (t > rod[0]) ? r27 : r26;

        if (r28 != r27 || r30->m38() == -1) {
            r30->m35();
            float frame = r30->m13();
            r30->m34(r27, 0, frame, rod[1]);
            if (getA(self)->m6() != 0) {
                getB(self)->m13(0x2100000C);
                r30->m25();
            }
            getB(self)->m6(r27, 0x20000001);
        }

        if (getA(self)->m6() == 0)
            r30->m26((rod[1] - absV) - r30->m24());
    }

    float f31b = r30->m23();
    float f30b = (rod[1] - f31b) *
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            self, 0xFAD, 0);
    if (getD(self)->m10() * f29 > rod[0])
        f30b = rod[2] - f30b;
    else
        f30b = rod[2] + f30b;
    getB(self)->m14(f30b, 0x21000005);
}
