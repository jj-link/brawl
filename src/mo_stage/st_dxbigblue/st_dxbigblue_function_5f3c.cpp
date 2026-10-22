#pragma force_active on
struct State {
    unsigned char mode;
    char pad[3];
    float value4;
    float value8;
};

struct Ret {
    float f0;
    char pad[0xc8];
    float fcc;
};

struct GroundBase {
    char pad0[0x3c];
};

struct Ground : GroundBase {
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual void u7();
    virtual void u8();
    virtual void u9();
    virtual void u10();
    virtual void u11();
    virtual void u12();
    virtual void u13();
    virtual void u14();
    virtual void u15();
    virtual void u16();
    virtual void u17();
    virtual void u18();
    virtual void u19();
    virtual void u20();
    virtual void u21();
    virtual void u22();
    virtual void u23();
    virtual void u24();
    virtual void u25();
    virtual void u26();
    virtual void enable(bool);
    virtual void u28();
    virtual void u29();
    virtual void u30();
    virtual void u31();
    virtual void u32();
    virtual void u33();
    virtual void u34();
    virtual void u35();
    virtual void u36();
    virtual void u37();
    virtual void u38();
    virtual void u39();
    virtual Ret* getData();
    virtual void u41();
    virtual void u42();
    virtual void u43();
    virtual void u44();
    virtual void u45();
    virtual void u46();
    virtual void u47();
    virtual void u48();
    virtual void u49();
    virtual void u50();
    virtual void u51();
    virtual void u52();
    virtual void u53();
    virtual void u54();
    virtual void u55();
    virtual void u56();
    virtual void u57();
    virtual void u58();
    virtual void u59();
    virtual void u60();
    virtual void u61();
    virtual void u62();
    virtual void u63();
    virtual void u64();
    virtual void u65();
    virtual void u66();
    virtual void u67();
    virtual void u68();
    virtual void u69();
    virtual void u70();
    virtual void u71();
    virtual void u72();
    virtual void u73();
    virtual void u74();
    virtual void u75();
    virtual void u76();
    virtual void u77();
    virtual void u78();
    virtual void u79();
    virtual void u80();
    virtual void u81();
    virtual void u82();
    virtual void u83();
    virtual void u84();
    virtual void u85();
    virtual void u86();
    virtual void u87();
    virtual void u88();
    virtual void u89();
    virtual void u90();
    virtual void u91();
    virtual void u92();
    virtual void u93();
    virtual void u94();
    virtual void u95();
    virtual void u96();
    virtual void u97();
    virtual void u98();
    virtual void u99();
    virtual void u100();
    virtual void u101();
    virtual void u102();
    virtual void u103();
    virtual void u104();
    virtual void u105();
    virtual void u106();
    virtual void u107();
    virtual void u108();
    virtual void u109();
    virtual void u110();
    virtual void u111();
    virtual void u112();
    virtual void u113();
    virtual void u114();
    virtual void u115();
    virtual void update(float);

    char pad1[0x2c];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    char pad2[0xe3];
    unsigned char phase;
    char pad3[3];
    float timer;
    char pad4[4];
    float* params;
    char pad5[4];
    State* state;
    unsigned char choice;
};

extern "C" void setEnableCollisionStatus__6GroundFb(Ground*, bool);
extern "C" const float lbl_81_rodata_D0;
extern "C" const float lbl_81_rodata_D4;

extern "C" void fn_81_5F3C(Ground* self, float delta) {
    Ret* r = self->getData();
    if (r) {
        self->timer -= delta;
        if (self->timer < lbl_81_rodata_D0)
            self->timer = lbl_81_rodata_D0;

        switch (self->phase) {
        case 0:
            self->state->value8 = r->f0 + r->fcc;
            self->phase = 1;
            break;
        case 1:
            if (self->state->mode != 10) {
                if (self->choice == 1) {
                    self->state->value4 = lbl_81_rodata_D0;
                    self->choice = 0;
                } else {
                    self->state->value4 = *self->params - lbl_81_rodata_D4;
                }
                self->phase = 2;
            }
            break;
        case 2:
            if (self->state->mode == 10) {
                self->enable(false);
                setEnableCollisionStatus__6GroundFb(self, false);
                self->phase = 0;
                break;
            }
            if (!self->enabled) {
                self->enable(true);
                setEnableCollisionStatus__6GroundFb(self, true);
            }
            self->update(delta);
            break;
        }
    }
}
