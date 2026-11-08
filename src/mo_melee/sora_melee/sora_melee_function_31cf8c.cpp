#pragma force_active on
#pragma fp_contract off

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13(unsigned int, double);
};

struct Params {
    char pad[0xbc];
    float denom;
    float unk;
    float scale;
};

struct Owner {
    char pad[0x4870];
    Params* params;
};

struct Modules {
    char pad0[0xc];
    Object_vptr_0* posture;
    char pad10[0x54];
    Object_vptr_0* work;
};

struct Access {
    char pad0[8];
    void* owner;
    char padc[0xcc];
    Modules* modules;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_48E80[], lbl_27_data_248[];
extern const float lbl_27_rodata_74F0[];

void fn_27_31CF8C(void*, Access* self) {
    const float* const table = lbl_27_rodata_74F0;
    Params* params = ((Owner*)__dynamic_cast(self->owner, 0x3c, lbl_27_data_48E80, lbl_27_data_248, 1))->params;
    Object_vptr_0* work = self->modules->work;
    float f31 = work->slot12(0x21000001);
    float f30 = work->slot12(0x21000004);
    if (table[0] == f30) f30 = table[7];
    double f29 = table[0];
    float f1 = work->slot12(0x21000008);
    if (f1 > table[0]) {
        f31 += f30 * (table[16] * f1 / params->denom);
        if (f31 > f1) {
            f30 = table[7];
            f31 = f1 - (f31 - f1);
        } else {
            float neg = -f1;
            if (f31 < neg) {
                f30 = table[15];
                f31 = neg - (f31 + f1);
            }
        }
        f29 = params->scale * (f31 / f1);
    }
    work->slot13(0x21000001, f31);
    work->slot13(0x21000003, f29);
    work->slot13(0x21000004, f30);
}
}
