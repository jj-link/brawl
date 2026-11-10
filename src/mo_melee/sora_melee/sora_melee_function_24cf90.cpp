#include <types.h>
#include <ft/ft_manager.h>
#include <ip/ip_switch.h>
#pragma force_active on
extern "C" {
extern int g_muWifiInterfaceTask;
extern void* g_aiMgr;
int fn_800CC1BC(void*);
u8 fn_27_24D18C();
int fn_800D904C(void*, int);
void fn_27_10A274(ftManager*, int, int);
void fn_27_10A320(ftManager*, int, u8);
void fn_27_1F1B68(void*, int, u8);
void fn_8004B8BC(void*, u8, u16);
}
struct Flags { u8 a : 5; u8 b : 1; u8 c : 2; };
inline void setInfo(u8* mgr, int value, u8 flag) {
    u8 idx = fn_27_24D18C();
    if (idx == 0xFF) idx = 4;
    u8* e = mgr + idx * 0x218;
    ((Flags*)(e + 0xC6))->b = flag;
    *(int*)(e + 0x78) = value;
}
inline int handleEntry(u8* ent, u8* self, int i) {
    int act;
    ent[0xB5] |= 4;
    if (self[0x225]) {
        act = g_ftManager->getEntryId(i);
        if (act != -1) {
            fn_27_10A274(g_ftManager, act, 1);
            fn_27_10A320(g_ftManager, act, ent[0xB6]);
            fn_27_1F1B68(g_aiMgr, i, ent[0xB7]);
        }
    } else {
        ent[0x99] = 3;
    }
    return 1;
}
extern "C" void fn_27_24CF90(u8* self) {
    u8* ent;
    int off;
    u8* mgr;
    int act;
    int bits;
    int i;
    mgr = (u8*)g_muWifiInterfaceTask;
    if (mgr != 0) {
        if (fn_800CC1BC(mgr) > 0) {
            self[0x224] = 0;
            return;
        }
        setInfo(mgr, self[0xD0] ? *(int*)(self + 0xE0) : -1, self[0x76]);
        if (self[0x226]) {
            act = 0;
            bits = 0;
            i = 0;
            off = 0;
            for (; i < *(int*)(self + 0x104); i++) {
                ent = *(u8**)(self + 0x44) + off;
                if (ent[0x99] || ((ent[0xD6] >> 7) & 1)) {
                    bits |= 1 << i;
                } else if (!((ent[0xB5] >> 2) & 1) && !fn_800D904C(mgr, i)) {
                    act = handleEntry(ent, self, i);
                } else {
                    bits |= 1 << i;
                }
                off += 0x5C;
            }
            if (act && ipSwitch::getInstance() && ipSwitch::getInstance()->m_keyRecorder) {
                int s = self[0x225] ? 1 : 2;
                fn_8004B8BC(ipSwitch::getInstance()->m_keyRecorder, (u8)s, (u16)bits);
            }
        }
    }
}
