#include <ai/ai_mgr.h>
#include <ip/ip_human.h>
#include <types.h>
#pragma force_active on
extern "C" {
void fn_27_1F25C8(void* self, int playerNo, int flag);
void* fn_27_21C8D4(void* table, int index, void* manager);
void fn_27_20B0D0(void* entry, void* data, signed char* id);
void fn_27_207DC0(void* entry, int index, int arg, void* input, int zero);
void fn_27_1F1CD0(void* arg0, const u8* arg1) {
    u8 b = *arg1;
    bool inRange = false;
    if ((s8)b >= 0 && (s8)b < 0xe) {
        inRange = true;
    }
    if (inRange != 0) {
        s32 id;
        if ((s8)b >= 0 && (s8)b < 0xe) {
            id = (s8)b % 7;
        } else {
            id = (s8)b;
        }
        fn_27_1F25C8(arg0, id, 0);
        s8 t0 = (s8)*arg1;
        *(s8*)((u8*)arg0 + t0 + 0x84) = -1;
        IpHuman* ip = *(IpHuman**)((u8*)arg0 + t0 * 4 + 0x4c);
        if (ip != 0) {
            ip->setEnableRumble(false);
        }
        u8 c = *arg1;
        bool normal = false;
        *(void**)((u8*)arg0 + (s8)c * 4 + 0x4c) = (void*)0;
        void* entry;
        if ((s8)c >= 0) {
            if ((s8)c >= 0 && (s8)c < 0xe) {
                normal = true;
            }
            if (normal) {
                entry = *(u8**)((u8*)g_aiMgr + 0xF8) + (s8)c * 0x1C4;
            } else {
                void* data = fn_27_21C8D4(*(void**)((u8*)g_aiMgr + 0x100), (s8)c - 0xe, g_aiMgr);
                entry = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
                if (*(s8*)((u8*)g_aiMgr + 0xA4) != (s8)*arg1 - 0xe && data != 0) {
                    fn_27_20B0D0(entry, data, (signed char*)arg1);
                    *((u8*)g_aiMgr + 0xA4) = (u8)(*arg1 - 0xe);
                }
            }
        } else {
            entry = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
        }
        fn_27_207DC0(entry, *(s8*)arg1, -1, 0, 0);
    }
}
}