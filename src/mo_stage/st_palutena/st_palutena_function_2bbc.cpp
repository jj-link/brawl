#include <types.h>
#pragma force_active on

struct Param {
    float f0;
    char pad[0x24];
    float f28;
};

class Object_vptr_3c_base { public: char pad[0x3c]; };

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual Param* slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48(float* out, u32 a, u32 b);
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual unsigned char slot118();

    unsigned char pad40[0x110];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[4];
    float* outPtr;
    char pad160[0x68];
    char gen[8];
    unsigned char flag1d0;
};

extern "C" {
int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
void fn_8005F800(int, int, void*);
extern int g_ecMgr;
extern const float lbl_67_rodata_10;
extern const float lbl_67_rodata_30;

void fn_67_2BBC(Object_vptr_3c* self, float delta) {
    Param* p = self->slot40();
    if (p != 0) {
        switch (self->state) {
        case 0:
            *self->outPtr = p->f0;
            self->timer = lbl_67_rodata_10;
            self->state = 1;
            /* fallthrough */
        case 1:
            if (self->slot118() == 4) {
                float tmp[3];
                playSE__14snd3DGeneratorF5SndIDiii(self->gen, 0x1cdf, 0, 0, -1);
                self->slot48(tmp, 0, 1);
                tmp[1] = tmp[1] - lbl_67_rodata_30;
                fn_8005F800(g_ecMgr, 0x4f0002, tmp);
                self->state = 2;
            }
            break;
        case 2:
            if (self->flag1d0 != 1) {
                self->timer = self->timer + delta;
                if (self->timer > p->f28) {
                    self->timer = p->f28;
                }
                if (self->timer >= p->f28) {
                    self->state = 0;
                }
            }
            break;
        }
    }
}
}
