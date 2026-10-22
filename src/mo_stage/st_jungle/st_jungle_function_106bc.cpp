#pragma force_active on
extern "C" void fn_27_26399C(void*);
extern "C" int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);

struct StagePrefix { unsigned char pad[0x3c]; };

class Stage : public StagePrefix {
public:
    virtual void slot_8() = 0;
    virtual void slot_c() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1c() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2c() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3c() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4c() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void slot_5c() = 0;
    virtual void slot_60() = 0;
    virtual void slot_64() = 0;
    virtual void slot_68() = 0;
    virtual void slot_6c() = 0;
    virtual void slot_70() = 0;
    virtual void slot_74() = 0;
    virtual void slot_78() = 0;
    virtual void slot_7c() = 0;
    virtual void slot_80() = 0;
    virtual void slot_84() = 0;
    virtual void slot_88() = 0;
    virtual void slot_8c() = 0;
    virtual void slot_90() = 0;
    virtual void slot_94() = 0;
    virtual void slot_98() = 0;
    virtual void slot_9c() = 0;
    virtual void slot_a0() = 0;
    virtual void slot_a4() = 0;
    virtual void slot_a8() = 0;
    virtual void slot_ac() = 0;
    virtual void slot_b0() = 0;
    virtual void slot_b4() = 0;
    virtual void slot_b8() = 0;
    virtual void slot_bc() = 0;
    virtual void slot_c0() = 0;
    virtual void slot_c4() = 0;
    virtual void slot_c8() = 0;
    virtual void slot_cc() = 0;
    virtual void slot_d0() = 0;
    virtual void slot_d4() = 0;
    virtual void slot_d8() = 0;
    virtual void slot_dc() = 0;
    virtual void slot_e0() = 0;
    virtual void slot_e4() = 0;
    virtual void slot_e8() = 0;
    virtual void slot_ec() = 0;
    virtual void slot_f0() = 0;
    virtual void slot_f4() = 0;
    virtual void slot_f8() = 0;
    virtual void slot_fc() = 0;
    virtual void slot_100() = 0;
    virtual void slot_104() = 0;
    virtual void slot_108() = 0;
    virtual void slot_10c() = 0;
    virtual void slot_110() = 0;
    virtual void slot_114() = 0;
    virtual void slot_118() = 0;
    virtual void slot_11c() = 0;
    virtual void slot_120() = 0;
    virtual void slot_124() = 0;
    virtual void slot_128() = 0;
    virtual void slot_12c() = 0;
    virtual void slot_130() = 0;
    virtual void slot_134() = 0;
    virtual void slot_138() = 0;
    virtual void slot_13c() = 0;
    virtual void slot_140() = 0;
    virtual void slot_144() = 0;
    virtual void slot_148() = 0;
    virtual void slot_14c() = 0;
    virtual void slot_150() = 0;
    virtual void slot_154() = 0;
    virtual void slot_158() = 0;
    virtual void slot_15c() = 0;
    virtual void slot_160() = 0;
    virtual void slot_164() = 0;
    virtual void slot_168() = 0;
    virtual void slot_16c() = 0;
    virtual void slot_170() = 0;
    virtual void slot_174() = 0;
    virtual void slot_178() = 0;
    virtual void slot_17c() = 0;
    virtual void slot_180() = 0;
    virtual void slot_184() = 0;
    virtual void slot_188() = 0;
public:
    virtual void notify(int, int) = 0;
};

extern "C" void fn_51_106BC(char* self) {
    if (*(void**)(self + 0x194)) {
        fn_27_26399C(*(void**)(self + 0x14c));
        *(char*)*(void**)(self + 0x194) = 1;
        ((Stage*)self)->notify(0, 0);
        playSE__14snd3DGeneratorF5SndIDiii(self + 0x1c4, 0x1b8c, 0, 0, -1);
        playSE__14snd3DGeneratorF5SndIDiii(self + 0x1c4, 0x1b8d, 0, 0, -1);
    }
}
