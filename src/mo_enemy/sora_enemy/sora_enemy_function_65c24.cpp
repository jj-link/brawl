#pragma force_active on

struct S5 {
    virtual void s00();
    virtual void s01();
    virtual void s02();
};
struct S6 : S5 { virtual void s03(); };
struct S8 : S6 { virtual void s04(); virtual void s05(); };
struct S11 : S8 { virtual void s06(); virtual void s07(); virtual void s08(); };
struct S18 : S11 {
    virtual void s09(); virtual void s10(); virtual void s11(); virtual void s12();
    virtual void s13(); virtual void s14(); virtual void s15();
};
struct S39 : S18 {
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36();
};
struct ModuleA : S8 { virtual int m06(); };
struct ModuleB : S6 { virtual void m04(); };
struct ModuleC : S5 { virtual void m03(int, void*); };
struct StatusModule : S18 { virtual int getStatusKind(); };
struct Work : S11 {
    virtual void m09(int, int);
    virtual void w10(); virtual void w11(); virtual void w12(); virtual void w13();
    virtual void m14(int);
};
struct Pad38 { char p[0x38]; };
struct Object : Pad38, S39 { virtual int m39(); };

struct ModuleSet {
    char pad0[0x30];
    ModuleB* m30;
    char pad1[0x8];
    ModuleA* m3C;
    char pad2[0x30];
    StatusModule* m70;
};

struct EnumStart {
    char pad0[0x3C];
    Work* m3C;
    char pad1[0x30];
    ModuleC* m70;
};

struct Accesser {
    char pad0[0xD8];
    EnumStart* mD8;
};

struct Fighter {
    char pad0[0x60];
    Accesser* m60;
    char pad1[0x1B4 - 0x64];
    ModuleSet* m1B4;
};

struct Event {
    int kind;
    unsigned char unk4;
    char pad0[3];
    int unk8;
    char pad1[0x10];
    unsigned char unk1C;
};

extern "C" void fn_41_B8D4(void*, void*, void*, void*, void*);

extern "C" void fn_41_65C24(Fighter* self, Event* event, void* arg2, Object* object, void* arg4) {
    if (self->m1B4->m70->getStatusKind() == 0x24 || self->m1B4->m70->getStatusKind() == 0x25) {
        switch (event->kind) {
        case 8:
            if (self->m1B4->m3C->m06() == 0 && object->m39() == 0) {
                self->m1B4->m30->m04();
                event->unk4 = 1;
                event->unk1C = 1;
                event->unk8 = 0x8E;
                return;
            }
            break;
        case 14:
            self->m60->mD8->m3C->m14(0);
            self->m60->mD8->m3C->m09(1, 0);
            return;
        case 9:
            self->m60->mD8->m3C->m14(0);
            self->m60->mD8->m3C->m09(1, 0);
            return;
        }
    }
    if (self->m1B4->m70->getStatusKind() == 0x13 || self->m1B4->m70->getStatusKind() == 0x15) {
        switch (event->kind) {
        case 8:
            if (self->m1B4->m3C->m06() == 0 && object->m39() == 0) {
                self->m1B4->m30->m04();
                event->unk4 = 1;
                event->unk1C = 1;
                event->unk8 = 0x8E;
                self->m60->mD8->m70->m03(0x14, self->m60);
                return;
            }
            break;
        case 14:
            self->m60->mD8->m3C->m14(0);
            self->m60->mD8->m3C->m09(1, 0);
            return;
        case 9:
            self->m60->mD8->m3C->m14(0);
            self->m60->mD8->m3C->m09(1, 0);
            return;
        }
    }
    fn_41_B8D4(self, event, arg2, object, arg4);
}
