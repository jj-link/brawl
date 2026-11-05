#include <mu/mu_object.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" int fn_8006CEEC(void*, int);

struct Self {
    char pad0[4];
    void* text;
    int count;
    char pad1[0x34];
    int index;
    MuObject* obj44;
    char pad2[0x14];
    MuObject* obj5c;
    MuObject* obj60;
    char pad3[0x14];
    MuObject* obj78;
    unsigned char flag;
    char pad4[3];
    int previous;
    int pos;
};

struct Input {
    char pad[0xc];
    int buttons;
    char pad2[4];
    unsigned int repeat;
};

extern "C" void fn_16_BBC(Self* self, const Input* input) {
    int index = self->index;

    if ((input->buttons & 0x1000) != 0) {
        index = 13;
        self->previous = 12;
    }

    if (input->repeat & 8) {
        if (index == 13) {
            index = self->previous;
        } else {
            index -= 3;
            if (index < 0) {
                index = 0;
            }
        }

        if (index == 0 && self->index != 0) {
            self->previous = self->index;
        }
    }

    if (input->repeat & 4) {
        if (index == 0) {
            index = self->previous;
        } else {
            index += 3;
            if (index >= 14) {
                index = 13;
            }
        }

        if (index == 13 && self->index != 13) {
            self->previous = self->index;
        }
    }

    unsigned int buttons = input->repeat;
    if ((buttons & 2) && index != 0 && index != 13 && index % 3 != 0) {
        index++;
    }
    if ((buttons & 1) && index != 0 && index != 13 && index % 3 != 1) {
        index--;
    }

    if (index != self->index) {
        float frame = (float)(index + 1);
        self->obj44->setFrameMatCol(frame);
        if (self->obj78) {
            self->obj78->setFrameMatCol(frame);
        }
        self->obj5c->setFrameNode(frame);
        self->index = index;
        self->flag = 1;

        int pos = fn_8006CEEC(self->text, 0x7fff);
        if (!self->flag) {
            pos--;
            if (pos < 0) {
                pos = 0;
            }
        }

        int max = self->count - 1;
        if (pos > max) {
            pos = max;
        }

        if (self->obj60) {
            self->obj60->setFrameNode((float)(pos + 1));
        }
        self->pos = pos;
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
    }
}
