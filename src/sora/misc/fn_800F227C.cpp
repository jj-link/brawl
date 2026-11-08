#include <mu/mu_msg.h>
#include <gm/gm_global.h>
#include <cstring>
#include <cstdio>
#pragma force_active on

extern "C" const char* getMsgData__5MuMsgFUlPPv(MuMsg*, unsigned long, void**);
extern "C" int getLanguage__10GameGlobalFv(GameGlobal*);
extern char lbl_8059E3C0[3];

extern "C" int fn_800F227C(void* self, char* out, int value, int flag) {
    void* size;
    MuMsg* msg = *(MuMsg**)((char*)self + 0x8c);
    int total = 0;
    if (flag) {
        memcpy(out, getMsgData__5MuMsgFUlPPv(msg, 0x4b, &size), (unsigned long)size);
        total = (int)size;
        out += total;
    } else if (getLanguage__10GameGlobalFv(g_GameGlobal) != 0) {
        memcpy(out, getMsgData__5MuMsgFUlPPv(msg, 0x4a, &size), (unsigned long)size);
        total = (int)size;
        out += total;
    }
    int length = sprintf(out, lbl_8059E3C0, value);
    out += length;
    total += length;
    if (getLanguage__10GameGlobalFv(g_GameGlobal) == 0) {
        memcpy(out, getMsgData__5MuMsgFUlPPv(msg, 0x4a, &size), (unsigned long)size);
        total += (int)size;
    }
    return total;
}