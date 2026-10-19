#include <types.h>
#include <gr/ground.h>
#include <gr/collision/gr_collision_status.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_81_data_E90[8];
extern float lbl_81_rodata_BC;
extern bool isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(Ground*, grCollStatus*, int);
}

extern "C" void fn_81_5130(Ground* ths, grCollStatus* collStatus) {
    if (isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(ths, collStatus, (int)(unsigned long)lbl_81_data_E90)) {
        *(float*)((char*)ths + 0x160) = lbl_81_rodata_BC;
        unsigned char* obj = (unsigned char*)*(void**)((char*)ths + 0x164);
        obj[0x31] = 1;
    }
}
