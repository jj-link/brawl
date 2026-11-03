#include <mu/mu_msg.h>
#pragma force_active on

extern "C" int sprintf(char* s, const char* fmt, ...);
extern char* lbl_8045B674[19];
extern char lbl_8059E280;
extern char lbl_8059E284;

extern "C" {
void fn_800E636C(u8* arg0, u32 arg1, u32 arg2, s32 arg3) {
    char buf[32];
    u32 n = arg2;

    if (n > 0x1869F) {
        n = 0x1869F;
    }
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 0;
    buf[5] = 0;
    buf[6] = 0;
    buf[7] = 0;
    buf[8] = 0;
    buf[9] = 0;
    buf[10] = 0;
    buf[11] = 0;
    buf[12] = 0;
    buf[13] = 0;
    buf[14] = 0;
    buf[15] = 0;
    buf[16] = 0;
    buf[17] = 0;
    buf[18] = 0;
    buf[19] = 0;
    buf[20] = 0;
    buf[21] = 0;
    buf[22] = 0;
    buf[23] = 0;
    buf[24] = 0;
    buf[25] = 0;
    buf[26] = 0;
    buf[27] = 0;
    buf[28] = 0;
    buf[29] = 0;
    buf[30] = 0;
    buf[31] = 0;

    if (n != 0) {
        if (arg3 != 0) {
            sprintf(buf, &lbl_8059E280, lbl_8045B674[10]);
        } else {
            sprintf(buf, &lbl_8059E280, lbl_8045B674[11]);
        }
    }
    if (n >= 10000) {
        sprintf(buf, &lbl_8059E284, buf, lbl_8045B674[n / 10000]);
    }
    if (n >= 1000) {
        sprintf(buf, &lbl_8059E284, buf, lbl_8045B674[(n % 10000) / 1000]);
    }
    if (n >= 100) {
        sprintf(buf, &lbl_8059E284, buf, lbl_8045B674[(n % 1000) / 100]);
    }
    if (n >= 10) {
        sprintf(buf, &lbl_8059E284, buf, lbl_8045B674[(n % 100) / 10]);
    }
    sprintf(buf, &lbl_8059E284, buf, lbl_8045B674[n % 10]);
    ((MuMsg*)*(void**)(arg0 + 0x650))->printf(arg1, buf);
}
}
