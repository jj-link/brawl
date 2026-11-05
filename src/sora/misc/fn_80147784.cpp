#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern "C" {
extern OSMutex lbl_8049EC30;
s32 fn_801475A4(void* self, s32 a, u64 id, s32 b);
int fn_801483A4(u64 id);
void fn_80147C9C(void* self, s32 idx);
void** getInstance__12ntFriendInfoFv(void);
void* memset(void* p, int c, unsigned int n);
}

struct FriendSelf {
    u8 pad0[0x3410];
    u8 unk3410;
    u8 pad3411;
    u8 unk3412;
    u8 pad3413[0x3418 - 0x3413];
    u32 unk3418;
    u32 unk341C;
    s8 unk3420;
};

extern "C" s32 fn_80147784(FriendSelf* self, u64 id, s32 flag) {
    s8 idx;
    s32 t;
    s32 res;
    u8 r;
    unsigned char* base;
    unsigned char* p;
    unsigned char* q;

    if (flag != 0) {
        OSLockMutex(&lbl_8049EC30);
        res = fn_801475A4(self, -1, id, 1);
        OSUnlockMutex(&lbl_8049EC30);
        return res;
    }

    OSLockMutex(&lbl_8049EC30);
    r = fn_801483A4(id);
    self->unk3420 = r;
    idx = (s8)r;
    if (idx >= 0) {
        self->unk341C = (u32)id;
        self->unk3418 = (u32)(id >> 32);
        self->unk3410 = 1;
        q = (unsigned char*)*getInstance__12ntFriendInfoFv() + (idx * 4);
        q[0x350] = 0;
        q[0x351] = 0;
        q[0x352] = 0;
        q[0x353] = 0;
        t = self->unk3420;
        base = (unsigned char*)*getInstance__12ntFriendInfoFv() + t * 0x89;
        p = base + 0x581;
        memset(p, 0, 10);
        memset(p + 10, 0, 10);
        memset(p + 0x3B, 0, 0x4C);
        memset(p + 0x32, 0, 8);
        p[0x3A] = 0;
        p[0x87] = 0;
        p[0x88] = 0;
        fn_80147C9C(self, self->unk3420);
        self->unk3412 = 1;
    }
    OSUnlockMutex(&lbl_8049EC30);
    return self->unk3420;
}
