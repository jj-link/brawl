#include <types.h>
#include <gr/ground.h>
#include <gr/collision/gr_collision_status.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_66_data_BCC[4];
extern float lbl_66_rodata_E0;
extern bool isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(Ground*, grCollStatus*, int);
}

extern "C" void fn_66_5490(Ground* ths, grCollStatus* collStatus) {
    if (isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(ths, collStatus, (int)(unsigned long)lbl_66_data_BCC) == 1) {
        *(float*)((char*)ths + 0x188) = lbl_66_rodata_E0;
    }
}
