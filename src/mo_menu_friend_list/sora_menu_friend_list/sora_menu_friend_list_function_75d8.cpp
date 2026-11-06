#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <snd/snd_system.h>
#include <string.h>
#pragma force_active on

extern "C" {
void fn_800BA364(void*, u32);
void fn_14_3A7C(void*, int);
void fn_14_3B3C(void*, int);
void fn_14_3C50(void*);
void* fn_14_3EC();
int fn_800D1F04(void*, unsigned long long, unsigned char*, unsigned char*);
}

struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(const Vec2& v) { x = v.x; y = v.y; }
};
struct PadStatus {
    u32 words[6];
    Vec2 vectors[3];
    unsigned char bytes[9];
    int last;
};
struct Input {
    PadStatus status;
    Input(const PadStatus& v) : status(v) {}
};
static inline gfPadStatus getSysPad() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    return status;
}
extern "C" int fn_14_75D8(char* self) {
    int flags = *(int*)(self + 0x218);
    Input input(*(PadStatus*)&getSysPad());
    int digit = *(int*)(self + 0x24FC);
    int state = *(int*)(self + 0x24F8);
    switch (state) {
    case 0:
        if (flags & 2) {
            if (++digit >= 10) digit = 0;
            if (digit == 9) fn_800BA364(self + 0x208, 2);
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            fn_14_3A7C(self, digit);
        }
        if (flags & 1) {
            if (--digit < 0) digit = 9;
            if (digit == 0) fn_800BA364(self + 0x208, 1);
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            fn_14_3A7C(self, digit);
        }
        if ((flags & 4) && state != 1) {
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            state = 1;
            fn_14_3B3C(self, 1);
        }
        if ((input.status.words[3] & 0x100) || (input.status.words[3] & 0x1000)) {
            g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
            u32 pos = strlen(self + 0x2500);
            pos = pos < 11 ? pos : 11;
            self[0x2500 + pos] = digit + '0';
            self[0x2501 + pos] = 0;
            fn_14_3C50(self);
            if (pos >= 11) {
                state = 2;
                fn_14_3B3C(self, 2);
            }
        }
        break;
    case 1:
        if ((flags & 8) && state != 0) {
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            state = 0;
            fn_14_3B3C(self, 0);
        }
        if ((flags & 4) && strlen(self + 0x2500) >= 12) {
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            state = 2;
            fn_14_3B3C(self, 2);
        }
        break;
    case 2:
        if (flags & 8) {
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            state = 1;
            fn_14_3B3C(self, 1);
        }
        if ((input.status.words[3] & 0x100) || (input.status.words[3] & 0x1000)) {
            unsigned char a, b;
            int result;
            if (*(unsigned char*)(self + 0x40) == 0) {
                unsigned long long number = 0;
                for (int i = 0; i < 12 && (signed char)self[0x2500 + i] != 0; i++)
                    number = number * 10 + ((signed char)self[0x2500 + i] - '0');
                result = fn_800D1F04(fn_14_3EC(), number, &a, &b);
            } else {
                result = 1;
                a = 0;
                b = 0;
            }
            if (result == 0 || a != 0 || b != 0) {
                if (result == 0) *(int*)(self + 0x2AC4) = 0;
                else if (a != 0) *(int*)(self + 0x2AC4) = 1;
                else *(int*)(self + 0x2AC4) = 2;
                g_sndSystem->playSE((SndID)3, -1, 0, 0, -1);
                return 0x13;
            }
            g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
            return 0x15;
        }
        break;
    }
    int erase = 0;
    if (((input.status.words[5] & 0x100) || (input.status.words[5] & 0x1000)) && state == 1)
        erase = 1;
    if (input.status.words[5] & 0x200) erase = 1;
    if (erase) {
        g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
        int len = strlen(self + 0x2500);
        if (len == 0) return 0x14;
        (self + len)[0x24FF] = 0;
        fn_14_3C50(self);
        if (state == 2) state = 1;
        fn_14_3B3C(self, state);
    }
    return *(int*)(self + 0x24C4);
}
