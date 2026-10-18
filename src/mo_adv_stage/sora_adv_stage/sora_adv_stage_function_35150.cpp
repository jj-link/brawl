#include <types.h>
#pragma force_active on

extern "C" {
void update__9grGimmickFf(void);
void fn_40_354A0(void*);
void updateCallback__9grGimmickFUl(void*, unsigned long);
extern const float lbl_40_rodata_6B4;
}

struct Gimmick {
    char _pad[0x158];
    unsigned char step;
    char _pad2[3];
    float f;
};

extern "C" void fn_40_35150(Gimmick* self, float deltaFrame) {
    update__9grGimmickFf();
    switch (self->step) {
    case 1:
        fn_40_354A0(self);
        break;
    case 2:
        if (self->f > lbl_40_rodata_6B4) {
            self->step = 0;
        }
        break;
    }
    self->f += deltaFrame;
    updateCallback__9grGimmickFUl(self, 0);
}
