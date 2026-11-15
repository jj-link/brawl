#include <types.h>
#pragma force_active on

#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

struct SubBits {
    u8 pad[0xf];
    u8 a : 5;
    u8 flag : 1;
    u8 b : 2;
};
struct DataBits {
    u8 pad[5];
    u8 top : 1;
    u8 rest : 7;
};

extern "C" {
void fn_27_24CA7C(void* self, int flag);

void fn_27_24C6FC(void* self, u8* data) {
    s32 v = 1;
    s32 t;

    P(self, 0x1dc) = data;
    B(self, 0xd4) = 1;

    switch (B(data, 4)) {
    case 0: {
        if ((s32)B(data, 0) >= 1) v = B(data, 0);
        W(self, 0x1b8) = v;
        W(self, 0x1c4) = 0;
        W(self, 0x1c8) = B(P(self, 0x1dc), 3);
        W(self, 0x1cc) = 0;
        W(self, 0x1d0) = ((s32)B(P(self, 0x1dc), 2) >= 1) ? (s32)B(P(self, 0x1dc), 2) : 1;
        W(self, 0x1d4) = 0;
        W(self, 0x1d8) = B(P(self, 0x1dc), 1);
        B(self, 0x1e0) = 1;
        break;
    }
    case 1: {
        if ((s32)B(data, 0) >= 1) v = B(data, 0);
        W(self, 0x1b8) = v;
        W(self, 0x1c4) = 0;
        W(self, 0x1c8) = B(P(self, 0x1dc), 3);
        W(self, 0x1cc) = 0;
        W(self, 0x1d0) = ((s32)B(P(self, 0x1dc), 2) >= 1) ? (s32)B(P(self, 0x1dc), 2) : 1;
        u8* d = (u8*)P(self, 0x1dc);
        t = B(d, 0x1c);
        W(self, 0x1d4) = t;
        W(self, 0x1d8) = t + B(d, 3);
        *(bool*)((u8*)self + 0x1e0) = !((SubBits*)P(self, 0x44))->flag;
        break;
    }
    case 2: {
        if ((s32)B(data, 0) >= 1) v = B(data, 0);
        W(self, 0x1b8) = v;
        W(self, 0x1c4) = 0;
        W(self, 0x1c8) = B(P(self, 0x1dc), 3);
        W(self, 0x1cc) = 0;
        W(self, 0x1d0) = ((s32)B(P(self, 0x1dc), 2) >= 1) ? (s32)B(P(self, 0x1dc), 2) : 1;
        W(self, 0x1d4) = 0;
        W(self, 0x1d8) = B(P(self, 0x1dc), 1);
        B(self, 0x1e0) = 1;
        break;
    }
    }

    {
        s32 sum = W(self, 0x1b8) + W(self, 0x1d0);
        s32 r = 7;
        if (sum <= 7) r = sum;
        W(self, 0x1bc) = r;
        if (B(P(self, 0x1dc), 4) == 2) {
            W(self, 0x1c0) = W(self, 0x1b8) + 1;
        } else {
            s32 q = 4;
            if (r <= 4) q = r;
            W(self, 0x1c0) = q;
        }
    }

    W(self, 0x1ec) = 0x270f;
    W(self, 0x208) = -1;
    W(self, 0x1f0) = 0x270f;
    W(self, 0x20c) = -1;
    W(self, 0x1f4) = 0x270f;
    W(self, 0x210) = -1;
    W(self, 0x1f8) = 0x270f;
    W(self, 0x214) = -1;
    W(self, 0x1fc) = 0x270f;
    W(self, 0x218) = -1;
    W(self, 0x200) = 0x270f;
    W(self, 0x21c) = -1;
    W(self, 0x204) = 0x270f;
    W(self, 0x220) = -1;

    if (((DataBits*)P(self, 0x1dc))->top) fn_27_24CA7C(self, 1);
}
}
