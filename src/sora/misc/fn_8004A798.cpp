#include <ip/ip_switch.h>
#include <ip/ip_padconfig.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_8004A670(void*);
s32 fn_8004A5C8(ipPadConfig* cfg, s32 index);
void fn_8004A468(ipPadConfig* cfg, s32 index, gfPadStatus* status, u16* dst);
extern u8 lbl_804977D0[16];
extern void* lbl_805A0390;
extern int lbl_805A00D4;
}

extern "C" void fn_8004A798(void** arg0, s32* arg1) {
    gfPadStatus status;
    u8* ports;
    u32 count;
    u16* dst;
    u8* sw;
    gfPadSystem* pads;
    u32 i;
    s32 mapped;

    if (g_ipSwitch == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x28, 1);
        if (p != 0) {
            p = fn_8004A670(p);
        }
        g_ipSwitch = (ipSwitch*)p;
    }
    sw = (u8*)g_ipSwitch;
    if (sw == 0) {
        *arg0 = 0;
        *arg1 = 0;
        return;
    }
    if (sw[0x27] == 0) {
        sw[0x27] = 1;
        lbl_805A00D4 = 0;
    }
    pads = g_gfPadSystem;
    if (pads->getGamePadQueueCount() != 0) {
        dst = (u16*)lbl_804977D0;
        count = ((u8*)lbl_805A0390)[0x199];
        ports = (u8*)lbl_805A0390 + 0x19D;
        for (i = 0; i < count; dst += 2, i++) {
            u8 port = ports[i];
            if (port == 0xFF) {
                port = 0;
            }
            pads->getGamePadStatus(port, &status);
            mapped = fn_8004A5C8(ipPadConfig::getInstance(), port);
            if (mapped < 0 || mapped == sw[0x25] || (sw[0x24] >> 3) & 1) {
                dst[0] = 0;
                ((u8*)dst)[3] = 0;
                ((u8*)dst)[2] = 0;
            } else {
                fn_8004A468(ipPadConfig::getInstance(), mapped, &status, dst);
            }
        }
        *arg0 = lbl_804977D0;
        *arg1 = count * 4;
        pads->updateGame();
        return;
    }
    *arg0 = 0;
    *arg1 = 0;
}
