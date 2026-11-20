#include <mu/mu_msg.h>
#include <gf/gf_scene.h>
#pragma force_active on
#pragma opt_propagation off

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_800B61C0(void*);
extern char lbl_12_data_24[];
extern char lbl_12_data_60[];
extern char lbl_12_data_90[];

int fn_12_CE8(char* self) {
    int f60 = 0;
    int f58 = 0;
    int delta = *(int*)(self + 0x11C);
    *(int*)(self + 0x60) += delta;
    *(int*)(self + 0x64) += delta;
    if (delta > 0) {
        if (*(int*)(self + 0x60) >= *(int*)(self + 0x118)) {
            *(int*)(self + 0x60) = *(int*)(self + 0x118);
            f60 = 1;
            *(int*)(self + 0x64) = 0;
        }
    } else {
        if (*(int*)(self + 0x60) <= *(int*)(self + 0x118)) {
            *(int*)(self + 0x60) = *(int*)(self + 0x118);
            f60 = 1;
            *(int*)(self + 0x64) = 0;
        }
    }
    int v1 = *(int*)(self + 0x60);
    int p1 = 1;
    p1 *= 10000;
    int a1 = (v1 > -9999) ? v1 : -9999;
    (*(MuMsg**)(self + 0x50))->printf(1, lbl_12_data_24, (a1 < p1 - 1) ? a1 : p1 - 1);

    int v2 = -*(int*)(self + 0x64);
    int p2 = 1;
    p2 *= 1000;
    int a2 = (v2 > -999) ? v2 : -999;
    (*(MuMsg**)(self + 0x50))->printf(2, lbl_12_data_24, (a2 < p2 - 1) ? a2 : p2 - 1);

    *(int*)(self + 0x58) += *(int*)(self + 0x120);
    if (*(int*)(self + 0x120) > 0) {
        if (*(int*)(self + 0x58) >= *(int*)(self + 0x5C)) {
            *(int*)(self + 0x58) = *(int*)(self + 0x5C);
            f58 = 1;
        }
    } else {
        if (*(int*)(self + 0x58) <= *(int*)(self + 0x5C)) {
            *(int*)(self + 0x58) = *(int*)(self + 0x5C);
            f58 = 1;
        }
    }

    int v3 = *(int*)(self + 0x58);
    int p3 = 1;
    p3 *= 100000000;
    int a3 = (v3 > -99999999) ? v3 : -99999999;
    (*(MuMsg**)(self + 0x50))->printf(0, lbl_12_data_24, (a3 < p3 - 1) ? a3 : p3 - 1);

    if (f60 != 0 && f58 != 0 && fn_800B61C0(*(void**)(self + 0x40)) != 0) {
        int n = *(int*)(self + 0x128) + 1;
        *(int*)(self + 0x128) = n;
        if (n >= 2) {
            __dynamic_cast(gfSceneManager::getInstance()->m_currentScene, 4, lbl_12_data_60, lbl_12_data_90, 0);
            gfSceneManager* mgr = gfSceneManager::getInstance();
            mgr->unk1 = 0;
            mgr->processStep = 2;
        }
    }
    return *(int*)(self + 0x44);
}
}
