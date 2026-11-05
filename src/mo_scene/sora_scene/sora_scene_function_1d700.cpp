#include <gf/gf_task.h>
#include <mu/mu_object.h>
#include <types.h>

#pragma force_active on

struct SceneParam {
    s32 p0;
    s32 p1;
    s32 p2;
    s32 p3;
    s32 p4;
    s32 p5;
    s32 p6;
};

extern "C" {
extern SceneParam lbl_1_rodata_920;
extern char lbl_1_data_6278[];
extern f32 lbl_1_rodata_91C;
gfTask* fn_40_3DDEC(void* param, s32 a, s32 b);
}

extern "C" s32 fn_1_1D700(void* arg0, s32 arg1, s32 arg2) {
    s32 var_r31 = *(s32*)((char*)arg0 + 0x1C);
    s32 var_r30 = 0;
    if (*(void**)((char*)arg0 + 0x14) == NULL) {
        SceneParam param = lbl_1_rodata_920;
        param.p0 = arg1;
        param.p1 = arg2;
        param.p3 = *(s32*)(*(char**)((char*)arg0 + 0x8) + 0x5C);
        param.p4 = *(s32*)(*(char**)((char*)arg0 + 0x8) + 0x60);
        param.p6 = *(s32*)((char*)arg0 + 0x24);
        if (*(u8*)(*(char**)((char*)arg0 + 0x8) + 0x5A) == 0) {
            param.p4 = -1;
        }
        *(gfTask**)((char*)arg0 + 0x14) = fn_40_3DDEC(&param, 0x2A, 0x2B);
    }
    s32 state = *(s32*)(*(char**)((char*)arg0 + 0x14) + 0xC24);
    switch (state) {
    case 0:
    case 1:
        break;
    case 2: {
        char* obj = *(char**)((char*)arg0 + 0x8);
        s32 t = *(s32*)(obj + 0x40);
        s32 flag;
        if (t == 2 || t == 3 || t == 4 || t == 8 || t == 9 || (u32)(t - 5) <= 1) {
            flag = 1;
        } else {
            flag = 0;
        }
        if (flag != 0) {
            *(s32*)(obj + 0x40) = 0;
            *(s32*)(obj + 0x1BC) = 0xA;
        }
        var_r31 = 0xD;
        var_r30 = 1;
        *(s32*)(*(char**)((char*)arg0 + 0x8) + 0x4A4) = 3;
        break;
    }
    case 3:
        if (var_r31 == 4 || var_r31 == 6) {
            char* obj = *(char**)((char*)arg0 + 0x8);
            s32 t = *(s32*)(obj + 0x40);
            s32 flag;
            if (t == 2 || t == 3 || t == 4 || t == 8 || t == 9 || (u32)(t - 5) <= 1) {
                flag = 1;
            } else {
                flag = 0;
            }
            if (flag != 0) {
                *(s32*)(obj + 0x40) = 0;
                *(s32*)(obj + 0x1BC) = 0xA;
            }
            MuObject* mo = *(MuObject**)(*(char**)((char*)arg0 + 0x8) + 0x1C8);
            mo->changeAnimN(lbl_1_data_6278);
            mo->setFrameNode(lbl_1_rodata_91C);
            mo->setFrameMatCol(lbl_1_rodata_91C);
            var_r31 = 1;
        } else {
            var_r31 = 2;
        }
        var_r30 = 1;
        break;
    }
    if (var_r30 != 0) {
        gfTask* child = *(gfTask**)((char*)arg0 + 0x14);
        child->exit();
        *(gfTask**)((char*)arg0 + 0x14) = NULL;
    }
    return var_r31;
}
