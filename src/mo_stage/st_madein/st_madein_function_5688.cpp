#include <types.h>
#pragma force_active on

enum SndID { SndID_Dummy = 0 };

class grMadein {
public:
    u32 isEndEntity();
};

class stMelee {
public:
    void playSeBasic(SndID id, float vol);
};

class Stage : public stMelee {
public:
    grMadein* getGround(int id);
};

class grTenganEvent {
public:
    u32 getPhase() const;
    void setPhase(s32 phase);
    void end();
};

extern "C" {
extern const float lbl_65_rodata_0[];
u32 fn_27_2793BC(void* ground, float f);
void fn_27_279228(void* ground, s32 arg);

u32 fn_65_5688(Stage* self) {
    const float* rd = lbl_65_rodata_0;
    u8* b = (u8*)self;

    s32 phase = ((grTenganEvent*)(b + 0x284))->getPhase();

    switch (phase) {
    case 0:
        b[0x957] = 1;
        b[0x956] = 1;
        b[0x955] = 1;
        b[0x954] = 1;
        fn_27_279228(self->getGround(0x43), 0);
        ((grTenganEvent*)(b + 0x284))->setPhase(1);
        b[0x9e6] = 0;
        b[0x9e5] = 0;
        b[0x9e4] = 0;
        b[0x9e3] = 0;
        b[0x9f4] = 0;
        break;
    case 1:
        if (b[0x9e0] == 2) {
            if (fn_27_2793BC(self->getGround(0x43), rd[0xd4 / 4]) == 1) {
                b[0x9f4] = 1;
                b[0x954] = b[0x9e3];
                b[0x955] = b[0x9e4];
                b[0x956] = b[0x9e5];
                b[0x957] = b[0x9e6];
                if (fn_27_2793BC(self->getGround(0x43), rd[0x78 / 4]) == 1) {
                    self->playSeBasic((SndID)0x1cae, rd[0]);
                    ((grTenganEvent*)(b + 0x284))->setPhase(2);
                }
            }
        } else {
            if (fn_27_2793BC(self->getGround(0x43), rd[0xd8 / 4]) == 1) {
                b[0x9f4] = 1;
                b[0x954] = b[0x9e3];
                b[0x955] = b[0x9e4];
                b[0x956] = b[0x9e5];
                b[0x957] = b[0x9e6];
                if (fn_27_2793BC(self->getGround(0x43), rd[0x13c / 4]) == 1) {
                    self->playSeBasic((SndID)0x1cae, rd[0]);
                    ((grTenganEvent*)(b + 0x284))->setPhase(2);
                }
            }
        }
        break;
    case 2:
        if (self->getGround(0x43)->isEndEntity() == 1) {
            b[0x9f4] = 0;
            b[0x9e6] = 0;
            b[0x9e5] = 0;
            b[0x9e4] = 0;
            b[0x9e3] = 0;
            ((grTenganEvent*)(b + 0x284))->end();
        }
        break;
    default:
        break;
    }
    return 0;
}
}
