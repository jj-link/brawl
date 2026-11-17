#include <types.h>
#pragma force_active on

extern "C" void* g_sndSystem;
extern "C" const float lbl_73_rodata_88;
extern "C" void playSE__9sndSystemF5SndIDiiii(void* self, int id, int a, int b, int c, int d);
extern "C" void setEnableCollisionStatus__6GroundFb(void* self, bool enable);

struct GrObj {
    char pad[0x54];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void m08();
    virtual void m0C();
    virtual void m10();
    virtual void m14();
    virtual void m18();
    virtual void m1C();
    virtual void m20();
    virtual void m24();
    virtual void m28();
    virtual void m2C();
    virtual void m30();
    virtual void m34();
    virtual void m38();
    virtual void m3C();
    virtual void m40();
    virtual void m44();
    virtual void m48();
    virtual void m4C();
    virtual void m50();
    virtual void m54();
    virtual void m58();
    virtual void m5C();
    virtual void m60();
    virtual void m64();
    virtual void m68();
    virtual void m6C();
    virtual void m70();
    virtual void m74();
    virtual void m78();
    virtual void m7C();
    virtual void m80();
    virtual void m84();
    virtual void m88();
    virtual void m8C();
    virtual void m90();
    virtual void m94();
    virtual void m98();
    virtual void m9C();
    virtual void mA0();
    virtual void mA4();
    virtual void mA8();
    virtual void mAC();
    virtual void mB0();
    virtual void mB4();
    virtual void mB8();
    virtual void mBC();
    virtual void mC0();
    virtual void mC4();
    virtual void mC8();
    virtual void mCC();
    virtual void mD0();
    virtual void mD4();
    virtual void mD8();
    virtual void mDC();
    virtual void mE0();
    virtual void mE4();
    virtual void mE8();
    virtual void mEC();
    virtual void mF0();
    virtual void mF4();
    virtual void mF8();
    virtual void mFC();
    virtual void m100();
    virtual void m104();
    virtual void m108();
    virtual void m10C();
    virtual void m110();
    virtual float getMotionFrame(unsigned int frame);
    virtual void m118();
    virtual void m11C();
    virtual void m120();
    virtual void m124();
    virtual void m128();
    virtual void m12C();
    virtual void m130();
    virtual void m134();
    virtual void m138();
    virtual void m13C();
    virtual void m140();
    virtual void m144();
    virtual void m148();
    virtual void m14C();
    virtual void m150();
    virtual void m154();
    virtual void m158();
    virtual void m15C();
    virtual void m160();
    virtual void m164();
    virtual void m168();
    virtual void m16C();
    virtual void m170();
    virtual void m174();
    virtual void m178();
    virtual void m17C();
    virtual void m180();
    virtual void m184();
    virtual void m188();
    virtual void m18C();
    virtual void m190();
    virtual void m194();
    virtual void m198();
    virtual void m19C();
    virtual void m1A0();
    virtual void m1A4();
    virtual void m1A8();
    virtual void m1AC();
    virtual void m1B0();
    virtual void m1B4();
    virtual void m1B8();
    virtual void m1BC();
    virtual void m1C0();
    virtual void m1C4();
    virtual void m1C8();
    virtual void m1CC();
    virtual void m1D0();
    virtual void m1D4();
    virtual void m1D8();
    virtual void m1DC();
    virtual void m1E0();
    virtual void slot1E4(float frame);
    virtual void m1E8();
    virtual void m1EC();
    virtual void m1F0();
    virtual void m1F4();
    virtual void m1F8();
    virtual void m1FC();
    virtual void slot200();
    virtual void slot204(int a, int b, int c, float* pos);

    // data members, starting at object offset 0x40
    unsigned char pad40[0x150 - 0x40];
    unsigned char unk150;
    unsigned char pad151[0x15C - 0x151];
    unsigned char* unk15C;
    char pad160[4];
    unsigned char* unk164;
    char pad168[0x174 - 0x168];
    GrObj** unk174;
    unsigned char unk178;
    char pad179[0x28C - 0x179];
    float unk28C;
    float unk290;
};

extern "C" void fn_73_3C30(Ground* self, float farg0) {
    if (*self->unk15C == 0x1d) {
        if (lbl_73_rodata_88 != self->unk290) {
            float f = self->getMotionFrame(0);
            if (!(f < self->unk28C)) {
                self->unk28C = self->getMotionFrame(0);
                return;
            }
        }
        self->slot204(2, 0, 1, &self->unk290);
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1D1F, 0, 0, 0, -1);
        self->slot200();
        setEnableCollisionStatus__6GroundFb(self, false);
        if (self->unk174 != 0) {
            u32 n = self->unk178;
            for (u32 i = 0; i != n;) {
                GrObj* o = self->unk174[i];
                i++;
                o->b0 = 0;
                o->b3 = o->b0;
                o->b1 = o->b3;
            }
        }
        unsigned char* p2 = self->unk164;
        *p2 -= 1;
        self->unk150 = 4;
    } else {
        self->unk28C = self->getMotionFrame(0);
    }
    self->slot1E4(farg0);
}
