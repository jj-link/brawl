#include <gr/gr_gimmick.h>
#include <cm/cm_camera_controller.h>
#include <gf/gf_camera.h>
#include <types.h>

#pragma force_active on

extern "C" {
void update__9grGimmickFf(void*, float);
void updateCallback__9grGimmickFUl(void*, unsigned long);
CameraController* getInstance__16CameraControllerFv();
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_40_1FF8(char*, void*);
extern const float lbl_40_rodata_380;
extern const float lbl_40_rodata_3B0;
extern const char lbl_40_data_1590[];
extern const char lbl_40_data_15D8[];
extern void* lbl_40_bss_15C;
}

struct StageGimmick {
    char pad0[0x150];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[4];
    float limit;
    void* camera;
    void* argument;
};

struct StageGimmickBase {
    char pad0[0x3c];
};

class StageGimmickVCall : public StageGimmickBase {
public:
#define SLOT(n) virtual void slot##n();
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69)
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
#undef SLOT
    virtual void method();
};

extern "C" void fn_40_25270(StageGimmick* self, float deltaFrame) {
    float vals[2];
    float cur;
    update__9grGimmickFf(self, deltaFrame);

    switch (self->state) {
    case 0:
        self->timer = lbl_40_rodata_380;
        break;

    case 1:
        if (self->timer > self->limit)
            self->state = 2;

        if (*(unsigned char*)((char*)self->camera + 0x44) != 5) {
            CameraController* camera = getInstance__16CameraControllerFv();
            void* object = __dynamic_cast(
                *(void**)((char*)camera + 0x48),
                4,
                lbl_40_data_1590,
                lbl_40_data_15D8,
                0);
            if (object != 0 &&
                (((int)((*(unsigned int*)((char*)object + 8) << 8) &
                        0xFF800000)) >> 24) == 0) {
                vals[0] = lbl_40_rodata_380;
                vals[1] = lbl_40_rodata_380;
                *(float*)((char*)object + 0xE8) = vals[0];
                *(float*)((char*)object + 0xEC) = vals[1];
                cur = *(float*)((char*)object + 0xDC);
                *(float*)((char*)object + 0xDC) = cur - lbl_40_rodata_3B0;
            }
        }
        self->timer += deltaFrame;
        break;

    case 2:
        fn_40_1FF8((char*)lbl_40_bss_15C, self->argument);
        ((StageGimmickVCall*)self)->method();
        self->state = 0;
        break;
    }

    updateCallback__9grGimmickFUl(self, 0);
}
