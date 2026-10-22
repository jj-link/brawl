#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;

extern char lbl_80529CF8[];

void fn_8023BA28(void *arg0) {
    u8 buf[4];
    u8 *p;
    void (*temp_r12)(s8 *);

    temp_r12 = *(void (**)(s8 *))(lbl_80529CF8 + 0x570);
    *(void (**)(s8 *))(lbl_80529CF8 + 0x570) = 0;
    if (temp_r12 != 0) {
        p = (u8 *)arg0;
        buf[0] = 3;
        buf[1] = p[0];
        buf[2] = p[1];
        temp_r12((s8 *)buf);
    }
}
