#include <mu/mu_msg.h>
#include <stdio.h>
#include <string.h>
#pragma force_active on
extern "C" void* getMsgData__5MuMsgFUlPPv(MuMsg*, unsigned long, void**);
extern "C" void fn_800B92D8(MuMsg*, unsigned long, char*, unsigned long);
extern char lbl_15_data_2A0[];
struct Msg { char pad[0x24c]; MuMsg* buffer; };
inline int minValue(int a, int b) { return a < b ? a : b; }
inline int clampValue(int value) { return minValue(value & ((-value & ~value) >> 31), 999); }
extern "C" void fn_15_25D8(Msg* self, int value) {
    int size0, size1;
    char buf[0x80];
    const char* d0;
    char* tmp = (char*)__alloca(8);
    int len2;
    d0 = (const char*)getMsgData__5MuMsgFUlPPv(self->buffer, 6, (void**)&size0);
    const char* d1 = (const char*)getMsgData__5MuMsgFUlPPv(self->buffer, 7, (void**)&size1);
    memcpy(buf, d0, size0);
    int len0 = size0;
    int len1 = sprintf(tmp, lbl_15_data_2A0, clampValue(value));
    memcpy(buf + len0, tmp, len1);
    len2 = len0 + len1;
    memcpy(buf + len2, d1, size1);
    len2 += size1;
    buf[len2] = 0;
    fn_800B92D8(self->buffer, 7, buf, len2 + 1);
}