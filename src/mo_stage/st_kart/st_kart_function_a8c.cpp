#pragma force_active on

extern "C" const float lbl_49_rodata_0[];
extern "C" float fn_8016232C(float);
extern "C" float fn_801622C4(float);

class CameraController {
public:
    static CameraController* getInstance();
};

struct StageBase {
    char pad[0x3c];
};

class Stage : public StageBase {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44();
    virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
    virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54();
    virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
    virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64();
    virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69();
    virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74();
    virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
    virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84();
    virtual void s85(); virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89();
    virtual void s90(); virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94();
    virtual void s95(); virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99();
    virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104();
    virtual void s105(); virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109();
    virtual void s110(); virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114();
    virtual void s115(); virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119();
    virtual void s120(); virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124();
    virtual void s125(); virtual void s126();
    virtual void fn_49_A8C();                                       // 0x204
    virtual void setCameraLimitRange(float, float, float, float);  // 0x208
    virtual void resetCameraLimitRange();                          // 0x20c
    virtual void s131(); virtual void s132(); virtual void s133(); virtual void s134(); virtual void s135();
    virtual void s136(); virtual void s137(); virtual void s138(); virtual void s139(); virtual void s140();
    virtual void s141();
    virtual void fn_49_B98(float);                                 // 0x23c
    virtual void fn_49_BF4(float);                                 // 0x240

    char pad40[0xeb - 0x40];
    unsigned char unkEB;
};

extern "C" {
void fn_49_A8C(Stage* self, float f) {
    const float* c = lbl_49_rodata_0;
    if (self->unkEB == 1) {
        CameraController* cam = CameraController::getInstance();
        float* p = (float*)((char*)cam + 0x84);
        float f4;
        if (p != 0) {
            float t = fn_8016232C(c[0]);
            float u = fn_801622C4(c[0]);
            float r = u / t;
            f4 = -(c[1] * (p[4] * r));
        }
        self->setCameraLimitRange(c[2], c[3], c[3], f4);
    } else {
        self->resetCameraLimitRange();
    }
    self->fn_49_B98(f);
    self->fn_49_BF4(f);
}
}
