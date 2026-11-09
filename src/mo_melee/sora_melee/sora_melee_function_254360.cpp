#include <types.h>
#include <mt/mt_prng.h>
#pragma force_active on

static inline int choose3() {
    int r = randi(99);
    int result = 4;
    if (r < 50)
        result = 3;
    return result;
}

static inline int choose14() {
    int r = randi(99);
    int result = 15;
    if (r < 50)
        result = 14;
    return result;
}

extern "C" void fn_27_254360(unsigned char* self, u32 arg1) {
    s32 i;
    s32 m = *(s32*)(self + 0x260) - 1;

    for (i = 0; i < *(s32*)(self + 0x260); i++) {
        s32 r = randi(m);
        s32 t = self[0x268 + i];
        self[0x268 + i] = self[0x268 + r];
        self[0x268 + r] = t;
    }

    if (self[0x268] == arg1) {
        s32 t = self[0x268];
        self[0x268] = self[0x269];
        self[0x269] = t;
    }

    s32 a = 29, b = 31, c = 33;
    for (s32 j = 0; j < *(s32*)(self + 0x260); j++) {
        switch (self[0x268 + j]) {
        case 3:
        case 4:
            self[0x268 + j] = choose3();
            break;
        case 14:
        case 15:
            self[0x268 + j] = choose14();
            break;
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34: {
            s32 r = randi(99);
            if (r < 33)
                self[0x268 + j] = a;
            else if (r < 66)
                self[0x268 + j] = b;
            else
                self[0x268 + j] = c;
            break;
        }
        }
    }

    *(s32*)(self + 0x264) = 0;
}
