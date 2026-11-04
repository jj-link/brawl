#pragma force_active on

#include <mu/mu_object.h>
#include <snd/snd_system.h>

struct Animation {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void setRate(float);
};

struct AnimationTracks {
    char padding[0x0C];
    Animation* node;
    Animation* tex;
};

struct MenuObject {
    char padding[0x14];
    AnimationTracks* tracks;
};

struct MenuObjects {
    char padding[0x218];
    MenuObject* tex;
    MenuObject* node;
};

struct Menu {
    char padding[0x64C];
    MenuObjects* objects;
    char padding650[0x24];
    int* entries;
    unsigned char count;
    unsigned char row;
    unsigned char scroll;
};

extern "C" {
extern float lbl_2_rodata_A98;
extern double lbl_2_rodata_AA0;
extern double lbl_2_rodata_AA8;
extern sndSystem* g_sndSystem;

void setFrameNode__8MuObjectFf(void*, float);
void setFrameTex__8MuObjectFf(void*, float);
void playSE__9sndSystemF5SndIDiiii(sndSystem*, int, int, int, int, int);
void fn_2_234F8(Menu*, unsigned int);

int fn_2_235F4(Menu* self, unsigned int buttons) {
    union {
        double value;
        unsigned int words[2];
    } conversion;

    unsigned int oldRow = self->row;
    unsigned char oldScroll = self->scroll;

    if (buttons & 1) {
        if (oldRow != 0) {
            self->row = oldRow - 1;
        } else if (oldScroll != 0) {
            self->scroll = oldScroll - 1;
        }
    }

    if (buttons & 2) {
        int row = self->row;
        if (row < 8u && row < self->count - 1) {
            self->row = row + 1;
        } else {
            int scroll = self->scroll;
            if (scroll < self->count - 9) {
                self->scroll = scroll + 1;
            }
        }
    }

    if (oldRow != self->row || oldScroll != self->scroll) {
        if (oldRow != self->row) {
            setFrameNode__8MuObjectFf(
                self->objects->node,
                (float)self->row
            );
            self->objects->node->tracks->node->setRate(lbl_2_rodata_A98);
        }

        if (oldScroll != self->scroll) {
            fn_2_234F8(self, self->scroll);
        }

        int entry = (self->entries + self->row)[self->scroll] - 5;
        if (entry == 1) {
            entry = 2;
        } else if (entry == 2) {
            entry = 1;
        }

        conversion.words[0] = 0x43300000;
        conversion.words[1] = (entry + 1) ^ 0x80000000;
        setFrameTex__8MuObjectFf(
            self->objects->tex,
            (float)(entry + 1)
        );
        self->objects->tex->tracks->tex->setRate(lbl_2_rodata_A98);
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        return 1;
    }

    return 0;
}
}
