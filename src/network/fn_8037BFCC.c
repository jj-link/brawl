#include <types.h>
#pragma force_active on

typedef struct Conn {
    char pad0[0x3C];
    s32 unk3C;
    char pad40[0xC];
    s32 socket;
    s32 unk50;
    char pad54[0x120 - 0x54];
    s32 unk120;
    char pad124[0x154 - 0x124];
    s32 unk154;
    s32 unk158;
    s32 unk15C;
} Conn;

extern s32 fn_8035C658(s32);
extern u32 fn_8035D728(void);
extern s32 recv(s32, void *, s32, s32);
extern s32 lbl_8059FA50;
extern s32 lbl_8059FA54;

s32 fn_8037BFCC(Conn *self, u8 *buf, s32 *outLen) {
    s32 len;
    s32 n;
    s32 err;
    s32 tmp;
    u32 now;

    len = *outLen - 1;
    if (self->unk158 != 0) {
        now = fn_8035D728();
        if (now < (u32)(self->unk15C + lbl_8059FA54)) {
            return 1;
        }
        self->unk15C = now;
        tmp = lbl_8059FA50;
        if (len < tmp) {
            tmp = len;
        }
        len = tmp;
    }
    n = recv(self->socket, buf, len, 0);
    if (n == -1) {
        err = fn_8035C658(self->socket);
        if (err == -0x38) {
            self->unk154 = 1;
            return 2;
        }
        if (err == -6 || err == -0x1A || err == -0x4C) {
            return 1;
        }
        self->unk50 = err;
        self->unk120 = 1;
        self->unk3C = 5;
        self->unk154 = 1;
        return 3;
    }
    if (n == 0) {
        self->unk154 = 1;
        return 2;
    }
    buf[n] = 0;
    *outLen = n;
    return 0;
}
