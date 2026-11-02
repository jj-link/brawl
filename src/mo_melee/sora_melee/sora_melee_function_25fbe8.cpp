#include <gf/gf_model.h>

#pragma force_active on

struct GameGlobal {
    char pad[0x44];
    void* manager;
};

struct RateMgr {
    char pad[4];
    float f4;
    float f8;
};

class AnimObj {
public:
    virtual void v0();
    virtual void v1(int, int, int);
};

class Ground {
    char pad0[0x3C];

public:
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
    virtual void updateG3dProcCalcWorld();

    int modelCount;
    AnimObj** arrayA;
    gfModelAnimation** arrayB;
    char pad4C[12];
    int count;
    char pad5C[4];
    char pad60[4];
    float rate;
    char pad68[4];
    unsigned char flags1;
    unsigned char flags2;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
extern float lbl_27_data_547E0;
extern const float lbl_27_rodata_42A4;
void fn_801AF9F4(void*);

void processAnim__6GroundFv(Ground* self) {
    if (self->modelCount != 0) {
        float r = lbl_27_data_547E0 * self->rate;
        GameGlobal* game = g_GameGlobal;
        RateMgr* mgr = (RateMgr*)game->manager;
        unsigned int i = 0;
        r *= mgr->f4;
        r *= mgr->f8;
        unsigned int cnt = self->count;

        if ((((unsigned int)self->flags2 >> 4) & 1U) == 1U) {
            r = lbl_27_rodata_42A4;
        }

        while (i != cnt) {
            self->arrayB[i]->setUpdateRate(r);

            if ((((unsigned int)self->flags2 >> 5) & 1U) == 1U) {
                self->arrayA[i]->v1(8, 0, 0);
            } else {
                fn_801AF9F4(self->arrayA[i]);
            }

            ++i;
        }

        self->updateG3dProcCalcWorld();
        self->flags1 = (unsigned char)((self->flags1 >> 2 << 2) | (self->flags1 & 1));
    }
}
}
