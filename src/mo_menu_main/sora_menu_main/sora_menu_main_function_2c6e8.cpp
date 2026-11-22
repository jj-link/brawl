#include <snd/snd_system.h>
#include <mu/mu_msg.h>
#pragma force_active on

extern "C" {
extern char lbl_2_data_385C[];

void fn_18_1754(void* self, unsigned int id);
void fn_18_17B0(void* self, int id, int mode, float value);
void fn_2_2CA88(void* self);
void fn_2_2CC28(void* self);
void fn_800B330C(void* a, void* b, int c);
}

struct Obj {
    unsigned char pad0[0x42];
    unsigned short unk42;
    unsigned char pad1[0x64C - 0x44];
    void** unk64C;
    unsigned char pad2[0x66C - 0x650];
    MuMsg* msg;
    unsigned int ids[8];
};

extern "C" int fn_2_2C6E8(Obj* self, int flags) {
    float seed0 = 0.0625f;
    float seed1 = 0.0f;
    float seed2 = 3.0f;
    float seed3 = 4.0f;
    float seed4 = 1.0f;
    float seed5 = 9.0f;
    double seed6 = 4503599627370496.0;
    unsigned int var = 0;
    unsigned short t;
    unsigned int n;
    unsigned int idx;

    if (flags & 1) {
        int v = self->unk42;
        if (v == 0) {
            self->unk42 = 8;
        } else {
            v = v - 1;
            self->unk42 = v;
            if ((unsigned short)v == 0) {
                fn_18_1754(self, 8);
            }
        }
        var = 1;
    } else if (flags & 2) {
        unsigned short u = self->unk42;
        if (u == 8) {
            self->unk42 = 0;
        } else {
            int v = u + 1;
            self->unk42 = v;
            if ((unsigned short)v == 8) {
                fn_18_1754(self, 4);
            }
        }
        var = 1;
    } else if (flags & 4) {
        t = self->unk42;
        if (t < 8) {
            char* p = (char*)self + t * 4;
            n = *(unsigned int*)(p + 0x670);
            if (n != 0) {
                *(unsigned int*)(p + 0x670) = n - 1;
                var = 2;
            }
        }
    } else if (flags & 8) {
        t = self->unk42;
        if (t < 8) {
            char* p = (char*)self + t * 4;
            n = *(unsigned int*)(p + 0x670);
            if (n < 2) {
                *(unsigned int*)(p + 0x670) = n + 1;
                var = 2;
            }
        }
    } else if (flags & 0x200) {
        t = self->unk42;
        if (t < 8) {
            char* p = (char*)self + t * 4;
            n = *(unsigned int*)(p + 0x670);
            if (n == 2) {
                *(unsigned int*)(p + 0x670) = 0;
            } else {
                *(unsigned int*)(p + 0x670) = n + 1;
            }
            var = 2;
        }
    }

    if (var == 1) {
        unsigned int off;
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        t = self->unk42;
        if (t == 8) {
            self->msg->printIndex(1, 0x3A, 0);
        } else {
            off = (t * 4) & 0x3FFFC;
            self->msg->printIndex(1, (t * 3 + 0x22) + self->ids[t], 0);
        }
        if (self->unk42 == 8) {
            fn_18_17B0(self, 0xB4, 0x10, 1.0f);
            fn_18_17B0(self, 0xB5, 2, 3.0f);
        } else {
            fn_18_17B0(self, 0xB4, 0x10, 0.0f);
            fn_18_17B0(self, 0xB5, 2, (float)self->ids[self->unk42]);
        }
        fn_18_17B0(self, 0xB5, 1, (float)self->unk42);
        return 1;
    }

    if (var == 2) {
        unsigned int off;
        g_sndSystem->playSE((SndID)0x23, -1, 0, 0, -1);
        fn_2_2CC28(self);
        t = self->unk42;
        if (t == 8) {
            self->msg->printIndex(1, 0x3A, 0);
        } else {
            off = (t * 4) & 0x3FFFC;
            self->msg->printIndex(1, (t * 3 + 0x22) + self->ids[t], 0);
        }
        fn_18_17B0(self, 0xB5, 2, (float)self->ids[self->unk42]);
        idx = self->unk42;
        fn_800B330C(self->unk64C[idx + 0xB6],
                     lbl_2_data_385C + (self->ids[idx] + 2) * 0x14, 0);
        fn_2_2CA88(self);
        return 1;
    }

    return 0;
}
