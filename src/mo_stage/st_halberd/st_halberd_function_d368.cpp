#include <lib/BrawlHeaders/Brawl/Include/mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_57_rodata_2A8;
extern "C" const float lbl_57_rodata_2AC;

struct Base {
    char pad[0x3c];
};

#define SLOT(n) virtual void vf##n();

class Object : public Base {
public:
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14)
    SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24)
    SLOT(25) SLOT(26)
    virtual void setVisibility(int);  // offset 0x74
    SLOT(28) SLOT(29) SLOT(30) SLOT(31) SLOT(32)
    SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37)
    SLOT(38) SLOT(39) SLOT(40) SLOT(41) SLOT(42)
    SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51) SLOT(52)
    SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57)
    SLOT(58) SLOT(59) SLOT(60) SLOT(61) SLOT(62)
    SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67)
    SLOT(68) SLOT(69) SLOT(70) SLOT(71) SLOT(72)
    SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77)
    SLOT(78) SLOT(79) SLOT(80) SLOT(81) SLOT(82)
    SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87)
    SLOT(88) SLOT(89) SLOT(90) SLOT(91) SLOT(92)
    SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97)
    SLOT(98) SLOT(99) SLOT(100) SLOT(101) SLOT(102)
    SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107)
    SLOT(108) SLOT(109) SLOT(110) SLOT(111) SLOT(112)
    SLOT(113) SLOT(114) SLOT(115)
    virtual void setMotion(int, int, int, float*);  // offset 0x1d8

    char pad40[0x110];
    unsigned char state;      // 0x150
    char pad151[0xb];
    unsigned char* event;     // 0x15c
    Vec2f* position;          // 0x160
    unsigned char motionState; // 0x164
    char pad165[3];
    float timer;              // 0x168
    char sound[8];            // 0x16c
    int soundHandle;          // 0x174
    int danger;               // 0x178
};

#undef SLOT

extern "C" {
extern void* g_aiMgr;
int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
void stopSE__14snd3DGeneratorFll(void*, int, int);
int setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(void*, Vec2f*, Vec2f*, int, bool, bool);
void fn_27_1F299C(void*, int);

void fn_57_D368(Object* self, float delta) {
    if (self->event) {
        self->timer -= delta;
        if (self->timer < lbl_57_rodata_2A8)
            self->timer = lbl_57_rodata_2A8;

        switch (self->state) {
        case 0:
            self->setMotion(4, 0, 1, 0);
            self->setVisibility(0);
            self->state = 2;
            // fallthrough
        case 2:
            if (*self->event == 8) {
                self->setMotion(3, 0, 1, &self->timer);
                self->setVisibility(1);
                self->soundHandle = playSE__14snd3DGeneratorF5SndIDiii(self->sound, 0x1bfe, 0, 0, -1);
                self->state = 6;
            }
            break;

        case 6: {
            Vec2f vec[2] = {
                Vec2f(self->position->m_x - lbl_57_rodata_2AC, lbl_57_rodata_2AC + self->position->m_y),
                Vec2f(lbl_57_rodata_2AC + self->position->m_x, self->position->m_y - lbl_57_rodata_2AC)
            };
            self->danger = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(g_aiMgr, &vec[0], &vec[1], self->danger, false, false);

            if (*self->event == 9) {
                self->setMotion(1, 1, 1, &self->timer);
                if (self->soundHandle != -1)
                    stopSE__14snd3DGeneratorFll(self->sound, self->soundHandle, 0);
                self->soundHandle = playSE__14snd3DGeneratorF5SndIDiii(self->sound, 0x1bff, 0, 0, -1);
                self->state = 7;
            }
            break;
        }

        case 7:
            if (*self->event == 10) {
                self->setMotion(0, 0, 1, &self->timer);
                if (self->soundHandle != -1)
                    stopSE__14snd3DGeneratorFll(self->sound, self->soundHandle, 0);
                self->soundHandle = -1;
                playSE__14snd3DGeneratorF5SndIDiii(self->sound, 0x1c00, 0, 0, -1);
                if (self->danger != -1) {
                    fn_27_1F299C(g_aiMgr, self->danger);
                    self->danger = -1;
                }
                self->state = 8;
            }
            break;

        case 1:
        case 3:
        case 4:
        case 5:
        case 8:
            break;
        }

        if (lbl_57_rodata_2A8 == self->timer) {
            switch (self->motionState) {
            case 3:
                self->setMotion(2, 1, 1, 0);
                break;
            case 0:
                self->state = 0;
                break;
            }
        }
    }
}
}
