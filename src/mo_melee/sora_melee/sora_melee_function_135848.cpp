#include <types.h>
#pragma force_active on
#pragma fp_contract off

extern "C" {
extern const float lbl_27_rodata_1048;
extern const double lbl_27_rodata_1068;
}

struct VT {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int v4(int);
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(int, float);
    virtual void v14(); virtual void v15();
    virtual int v16();
    virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(int, float);
    virtual void v39(); virtual void v40(); virtual void v41();
    virtual void* v42(int, int);
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(int);
};

struct Motion {
    char pad[8];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual float v13(float, void*, void*, int, int, float);
};

struct Modules {
    char p0[0x38];
    Motion* b38;
    char p1[0x28];
    VT* b64;
    char p2[8];
    VT* b70;
    char p3[0x14];
    VT* b88;
};

struct Obj {
    char p0[0xd8];
    Modules* mod;
};

struct Self {
    char p0[0x60];
    Obj* o;
    char p1[0xb8];
    float f11c;
    float f120;
    float f124;
};

struct Arg2 {
    char p0[0x24];
    unsigned char b24;
    char p1[2];
    unsigned char b27;
};

struct Ret {
    char p0[0x2c];
    float f2c;
    char p1[4];
    int i34;
};

union Conv {
    double value;
    unsigned int words[2];
};

extern "C" void fn_27_135848(Self* self, VT* arg1, Arg2* arg2, void* unused, Obj* arg4, float farg0, float farg1, float farg2) {
    arg4->mod->b88->v49(0x20);
    int st = arg4->mod->b70->v16();
    switch (st) {
    case 26:
    case 27:
    case 29:
        break;
    default:
        return;
    }
    {
        unsigned char b24 = arg2->b24;
        Ret* r = (Ret*)arg1->v42(b24, arg2->b27);
        if (farg0 > self->f120) {
            self->f120 = farg0;
            Motion* mo = self->o->mod->b38;
            self->f124 = mo->v13(farg1, arg1, r, b24, arg2->b27, farg2);
            arg4->mod->b64->v13(0x21000006, r->f2c);
        }
        if (arg4->mod->b64->v4(0x20000001) > 0) {
            arg4->mod->b88->v49(0x7f);
            arg4->mod->b88->v38(0x1b, lbl_27_rodata_1048);
        } else {
            Conv conversion;
            conversion.words[0] = 0x43300000;
            int v = (int)(((unsigned)r->i34 << 13) & 0xFFC00000) >> 23;
            conversion.words[1] = v ^ 0x80000000;
            self->f11c = self->f11c + (farg0 + (float)v);
        }
    }
}
