#include <types.h>
#pragma force_active on

extern "C" {
u8 fn_27_24D18C();
void fn_27_254E80(int, ...);
void fn_800D0A58(s32, s32, s32);
u8* getInstance__17ipNetworkProducerFv();
}

extern s32 g_muWifiInterfaceTask;
extern s32 lbl_27_data_52B78;
extern char lbl_27_data_52E10[];

extern "C" void fn_27_254DDC(u8* self) {
    *(s32*)(self + 0x6C) = lbl_27_data_52B78;
    *(s32*)(self + 0x70) = 0;
    if (self[0x49] != 0) {
        s32 task = g_muWifiInterfaceTask;
        u8 idx = fn_27_24D18C();
        if (idx == 0xFF) {
            idx = 4;
        }
        u8* e = (u8*)(task + idx * 0x218);
        e[0xC6] |= 0x40;
        fn_27_254E80((int)lbl_27_data_52E10, e);
        fn_800D0A58(task, 0, 0xFE);
        u8* p = getInstance__17ipNetworkProducerFv();
        p[0] = 0;
    }
}
