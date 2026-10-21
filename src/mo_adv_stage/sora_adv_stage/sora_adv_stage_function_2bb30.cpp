#pragma force_active on

typedef unsigned int u32;

struct Base {
    char pad0[0x3C];
};

struct Object : Base {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void changeAnim(const unsigned short*, unsigned long);

    char pad40[4];
    void** models;
    void** animations;
    char pad4C[0x124];
    int state;
    char pad174[8];
    float timer;
    const unsigned short* anim;
    int index;
};

extern "C" {
extern const unsigned short* lbl_40_data_9558;
extern const unsigned short* lbl_40_data_955C;
extern const float lbl_40_rodata_468[];

void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*, void*);
void changeTexSrtAnim__9grGimmickFUlUl(Object*, unsigned long, unsigned long);
void setFrame__16gfModelAnimationFd(void*, double);
void stopGimmickSE__9grGimmickFUl(Object*, u32);
void stopGimmickEffect__9grGimmickFUl(Object*, u32);
void fn_27_273C30(Object*);
void fn_27_273C98(Object*);

void fn_40_2BB30(Object* self) {
    self->anim = lbl_40_data_9558 + self->index;
    unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(
        *self->animations, *self->models);
    self->anim = lbl_40_data_955C + self->index;
    self->changeAnim(self->anim, 0);
    changeTexSrtAnim__9grGimmickFUlUl(self, 0, 0);
    setFrame__16gfModelAnimationFd(*self->animations, lbl_40_rodata_468[0]);

    for (u32 i = 0; i < 5; i++) {
        stopGimmickSE__9grGimmickFUl(self, i + 3);
    }

    for (u32 i = 0; i < 5; i++) {
        stopGimmickEffect__9grGimmickFUl(self, i + 3);
    }

    fn_27_273C30(self);
    fn_27_273C98(self);
    self->state = 2;
    self->timer = lbl_40_rodata_468[0];
}
}
