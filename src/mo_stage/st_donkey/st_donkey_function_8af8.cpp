#pragma force_active on
struct Vec3f {
    float x, y, z;
};

struct GroundBase {
    char pad[0x3C];
};

struct grGimmick : GroundBase {
    virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5();
    virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49();
    virtual void getNodePosition(Vec3f* pos, unsigned int idx, unsigned int node);
    virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58();
    virtual void m59(); virtual void m60(); virtual void m61(); virtual void m62();
    virtual void m63(); virtual void m64(); virtual void m65(); virtual void m66();
    virtual void m67(); virtual void m68(); virtual void m69(); virtual void m70();
    virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78();
    virtual void m79(); virtual void m80(); virtual void m81(); virtual void m82();
    virtual void m83(); virtual void m84(); virtual void m85(); virtual void m86();
    virtual void m87(); virtual void m88(); virtual void m89(); virtual void m90();
    virtual void m91(); virtual void m92(); virtual void m93(); virtual void m94();
    virtual void m95(); virtual void m96(); virtual void m97(); virtual void m98();
    virtual void m99();
    virtual void disableAttack(unsigned int unk);
    virtual void m101(); virtual void m102(); virtual void m103(); virtual void m104();
    virtual void m105(); virtual void m106(); virtual void m107(); virtual void m108();
    virtual void m109(); virtual void m110(); virtual void m111(); virtual void m112();
    virtual void m113(); virtual void m114(); virtual void m115(); virtual void m116();
    virtual void m117();
    virtual void fn_50_8F5C();
    virtual void fn_50_92F8();

    char pad40[0xC4 - 0x40];
    int unkC4;
    char padC8[0x14C - 0xC8];
    int unk14C;
    signed char unk150;
    char pad151[0x178 - 0x151];
    unsigned char unk178;
    unsigned char unk179;
    char pad17A[0x190 - 0x17A];
    char generator[1];
};

extern "C" void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, Vec3f*);

extern "C" void fn_50_8AF8(grGimmick* self) {
    if (self->unk178 == 1) {
        switch (self->unk150) {
        case 7: {
            Vec3f pos;
            self->getNodePosition(&pos, 0, self->unkC4);
            setPos__9grGimmickFP5Vec3f(self, &pos);
            setPos__14snd3DGeneratorFP5Vec3f(self->generator, &pos);
            self->fn_50_92F8();
            break;
        }
        default:
            if (self->unk179 == 1) {
                self->disableAttack(0);
                self->unk179 = 0;
            }
            break;
        }
    } else {
        self->fn_50_8F5C();
        if (self->unk14C != 0) {
            self->unk178 = 1;
        }
    }
}
