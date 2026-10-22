#include <types.h>
#pragma force_active on

struct Stage;
struct StageHead { char bytes[0x3c]; };
struct StageDispatch : StageHead {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
    virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31();
    virtual void f32(); virtual void f33(); virtual void f34(); virtual void init();
};
struct StageVTable { void* unused[0x94 / 4]; void (*init)(Stage*); };

struct Stage {
    char pad0[0x3c];
    StageVTable* vtable;
    char pad40[4];
    int kind;
    char pad48[6];
    u8 m4e, m4f, m50;
    char pad51[3];
    u32 m54;
    char pad58[0x34];
    u32 m8c;
    char pad90[4];
    u32 m94;
    char pad98[0xc];
    u32 ma4, ma8;
    u8 mac;
    char padad[3];
    float mb0, mb4;
    u32 mb8;
    char padbc[0x2d];
    u8 me9, mea, meb;
    char padec[0xc];
    char mf8[0xc];
    char m104[0x90];
    u32 m194;
    u8 m198, m199, m19a, m19b, m19c, m19d, m19e, m19f;
};

extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_27_227ED8(void*);
void* __ct__9gfArchiveFv(void*);
extern StageVTable lbl_27_data_4A1E8;
extern const float lbl_27_rodata_33D0;
extern const float lbl_27_rodata_33D4;
extern Stage* lbl_27_bss_5668;
}

extern "C" Stage* __ct__5StageFPCcQ26Stages11srStageKind(Stage* self, const char* name, int kind) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, name, 0x21, 1, 2, true);
    self->vtable = &lbl_27_data_4A1E8;
    self->kind = kind;
    self->m4e = 0;
    self->m4f = 0;
    self->m50 = 0;
    self->m54 = 0;
    self->m8c = 0;
    self->m94 = 0;
    self->ma4 = 0;
    self->ma8 = 0;
    self->mac = 0;
    self->mb0 = lbl_27_rodata_33D0;
    self->mb4 = lbl_27_rodata_33D4;
    self->mb8 = 0;
    self->me9 = 1;
    self->mea = 1;
    self->meb = 0;
    fn_27_227ED8(self->mf8);
    __ct__9gfArchiveFv(self->m104);
    self->m194 = 0;
    self->m199 = 0;
    self->m19a = 0;
    self->m19b = 0;
    self->m19c = 0;
    self->m19d = 0;
    self->m19e = 0;
    self->m19f = 0;
    lbl_27_bss_5668 = self;
    ((StageDispatch*)self)->init();
    return self;
}
