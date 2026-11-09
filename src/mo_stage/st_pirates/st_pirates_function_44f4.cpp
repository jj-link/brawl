#pragma force_active on
extern "C" {
extern const float lbl_52_rodata_D0;
extern const float lbl_52_rodata_D4;

struct Base {
    unsigned char pad[0x3C];
};

struct Object : Base {
    virtual void s2();   virtual void s3();
    virtual void s4();   virtual void s5();   virtual void s6();   virtual void s7();
    virtual void s8();   virtual void s9();   virtual void s10();  virtual void s11();
    virtual void s12();  virtual void s13();  virtual void s14();  virtual void s15();
    virtual void s16();  virtual void s17();  virtual void s18();  virtual void s19();
    virtual void s20();  virtual void s21();  virtual void s22();  virtual void s23();
    virtual void s24();  virtual void s25();  virtual void s26();  virtual void s27();
    virtual void s28();  virtual void s29();  virtual void s30();  virtual void s31();
    virtual void s32();  virtual void s33();  virtual void s34();  virtual void s35();
    virtual void s36();  virtual void s37();  virtual void s38();  virtual void s39();
    virtual void s40();  virtual void s41();  virtual void s42();  virtual void s43();
    virtual void s44();  virtual void s45();  virtual void s46();  virtual void s47();
    virtual void s48();  virtual void s49();  virtual void s50();  virtual void s51();
    virtual void s52();  virtual void s53();  virtual void s54();  virtual void s55();
    virtual void s56();  virtual void s57();  virtual void s58();  virtual void s59();
    virtual void s60();  virtual void s61();  virtual void s62();  virtual void s63();
    virtual void s64();  virtual void s65();  virtual void s66();  virtual void s67();
    virtual void setMotionFrame(float, unsigned long);
    virtual void s69();  virtual void s70();  virtual void s71();
    virtual void s72();  virtual void s73();  virtual void s74();  virtual void s75();
    virtual void s76();  virtual void s77();  virtual void s78();  virtual void s79();
    virtual void s80();  virtual void s81();  virtual void s82();  virtual void s83();
    virtual void s84();  virtual void s85();  virtual void s86();  virtual void s87();
    virtual void s88();  virtual void s89();  virtual void s90();  virtual void s91();
    virtual void s92();  virtual void s93();  virtual void s94();  virtual void s95();
    virtual void s96();  virtual void s97();  virtual void s98();  virtual void s99();
    virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103();
    virtual void s104(); virtual void s105(); virtual void s106(); virtual void s107();
    virtual void s108(); virtual void s109(); virtual void s110(); virtual void s111();
    virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117();
    virtual void action(int, int, int, float*);

    unsigned char pad40[0x150 - 0x40];
    unsigned char state;
    unsigned char pad151[0x158 - 0x151];
    float* motionTimer;
    unsigned char pad15C[0x160 - 0x15C];
    unsigned char phase;
    unsigned char pad161[0x16C - 0x161];
    unsigned char* selector;
    unsigned char selected;
    unsigned char kind;
    unsigned char pad172[0x174 - 0x172];
    float timer;
};

void fn_52_44F4(Object* self, float delta) {
    self->timer -= delta;
    if (self->timer < lbl_52_rodata_D0)
        self->timer = lbl_52_rodata_D0;

    switch ((int)self->state) {
    case 0:
        self->action(0, 1, 1, &self->timer);
        self->state = 1;
        // fall through
    case 1:
        if (self->phase == 1) {
            unsigned int val = 9;
            int flag = 1;
            int kind = self->kind;

            switch (kind) {
            case 3:
            case 8: val = 1; break;
            case 4:
            case 6: val = 2; break;
            case 5:
            case 7: val = 0; break;
            default: break;
            }

            unsigned int current = *self->selector;
            if (current != self->selected) {
                unsigned char old_val = (unsigned char)val;
                switch (current) {
                case 1:
                    switch (kind) {
                    case 1: val = 5; break;
                    case 2: val = 7; break;
                    default: break;
                    }
                    break;
                case 2:
                    switch (kind) {
                    case 0: val = 3; break;
                    case 2: val = 8; break;
                    default: break;
                    }
                    break;
                case 3:
                case 5:
                    switch (kind) {
                    case 0: val = 4; break;
                    case 1: val = 6; break;
                    default: break;
                    }
                    break;
                default: break;
                }
                if (val != (unsigned int)old_val) flag = 0;
                self->selected = (unsigned char)current;
            }

            if (val != 9) {
                self->action((int)val, flag, 1, &self->timer);
                self->setMotionFrame(lbl_52_rodata_D4 - *self->motionTimer, 0);
            }
        }
        break;
    }
}
}
