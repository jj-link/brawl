#include <mu/mu_object.h>
#include <snd/snd_system.h>
#pragma force_active on

struct Obj {
    char pad0[0x78];
    MuObject* object;
    void* other;
    char pad1[0x504 - 0x80];
    int state;
    char pad2[0x6e8 - 0x508];
    unsigned short values[100];
    unsigned short length;
    unsigned short ring[200];
    char pad3[2];
    int write;
    int read;
    int count;
    char pad4[0xd48 - 0x950];
    int timer;
    char pad5[0xd58 - 0xd4c];
    unsigned char flag;
};
extern "C" void fn_15_2490(Obj*, int);
extern "C" int fn_800B61C0(void*);
inline void push(Obj* self, unsigned short value) {
    if (self->count < 200) {
        self->ring[self->write] = value;
        if (++self->write >= 200) self->write = 0;
        ++self->count;
    }
}

extern "C" int fn_15_464C(Obj* self) {
    if (!self->flag && self->timer > 0) {
        fn_15_2490(self, --self->timer);
        int frame = self->timer;
        self->object->setFrameVisible((float)frame);
        self->object->setFrameNode((float)frame);
        if (self->timer % 10 == 0) {
            g_sndSystem->playSE((SndID)0x1ef9, -1, 0, 0, -1);
        }
    }
    if (fn_800B61C0(self->other)) {
        if (!self->flag) {
            if (self->timer <= 0) {
                for (int i = 0; i < self->length; ++i) {
                    push(self, self->values[i]);
                }
                return 8;
            }
        } else {
            return 7;
        }
    }
    return self->state;
}