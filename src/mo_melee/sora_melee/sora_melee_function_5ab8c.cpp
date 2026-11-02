#pragma force_active on
#include <so/controller/so_controller_impl.h>

extern const float lbl_27_rodata_7B8;

struct Clatter {
    float a;
    float b;
    float c;
    char d;
    char e;
    char f;
    unsigned char g;
};

extern "C" void fn_27_5AB8C(Clatter* clatter, soController* ctrl, unsigned int flag, float threshold) {
    char dirX = clatter->d;
    char dirY = clatter->e;

    if (ctrl->getStickX() < -threshold) {
        dirX = -1;
    } else if (ctrl->getStickX() > threshold) {
        dirX = 1;
    }
    if (ctrl->getStickY() < -threshold) {
        dirY = -1;
    } else if (ctrl->getStickY() > threshold) {
        dirY = 1;
    }
    if (dirX != clatter->d || dirY != clatter->e) {
        clatter->d = dirX;
        clatter->e = dirY;
        clatter->a = clatter->a - clatter->c;
        if (clatter->g != 0) {
            clatter->f++;
        }
    }
    if (flag == 1) {
        clatter->a = clatter->a - clatter->c;
    }
    clatter->a = clatter->a - clatter->b;
    if (clatter->a < lbl_27_rodata_7B8) {
        clatter->a = lbl_27_rodata_7B8;
    }
}
