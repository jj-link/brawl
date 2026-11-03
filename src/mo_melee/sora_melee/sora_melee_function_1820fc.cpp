#pragma force_active on

#include "mt/mt_vector.h"

extern int lbl_27_data_30820;
extern float lbl_27_rodata_2440;

class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual Vec3f v14(int);
    virtual void v15(Vec3f*, int);
    virtual int v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(int, int);
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(int, int, int);
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
};

struct Holder {
    char pad0[0x8];
    VObj* m8;
    VObj* mC;
    char pad1[0x54];
    VObj* m64;
    char pad2[0x8];
    VObj* m70;
    char pad3[0x14];
    VObj* m88;
    char pad4[0x4];
    VObj* m90;
};

struct Obj {
    char pad[0xD8];
    Holder* d8;
};

extern "C" void fn_27_1820FC(void*, Obj* self, int arg) {
    switch (self->d8->m70->v16()) {
    case 0xB3:
        break;
    case 0xB4:
        self->d8->m8->v34();
        break;
    case 0xBB: {
        Vec3f tmp = self->d8->mC->v14(0);
        tmp.m_y = lbl_27_rodata_2440;
        self->d8->mC->v15(&tmp, 0);
        break;
    }
    case 0xBC:
        self->d8->m88->v24(4, 1, 1);
        break;
    }
    if (arg >= 0xBD || arg < 0xB3) {
        self->d8->m90->v19(3, 3);
        switch (arg) {
        case 0x0:
        case 0xB:
            self->d8->m64->v5(lbl_27_data_30820, 0x10000027);
            break;
        }
    }
}
