#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <snd/snd_system.h>

#pragma force_active on

struct RawPadStatus {
    u32 words[16];
};

struct Vec2 {
    float x;
    float y;
    Vec2() {}
    Vec2(const Vec2& other) {
        x = other.x;
        y = other.y;
    }
};

struct PadStatus {
    u32 words[6];
    Vec2 vectors[3];
    unsigned char bytes[9];
    int last;
};

struct Scene {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void remove(void*);
};

struct Object {
    char pad[0x10];
    void* model;
};

struct Entry {
    unsigned char scene;
    char pad[3];
    char* node;
    unsigned char frame;
    char tail[3];
};

extern "C" {
extern gfPadSystem* g_gfPadSystem;
extern const Entry lbl_14_rodata_3E8[];

void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, RawPadStatus*);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void setFrameNode__8MuObjectFf(void*, float);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
}

inline RawPadStatus getRawPadStatus() {
    RawPadStatus status;
    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, 0xF0, &status);
    return status;
}

struct Input {
    PadStatus status;

    Input(const PadStatus& source) : status(source) {}
};

inline void updateSelection(char* self, int choice) {
    Object* object;
    int selected;

    switch (choice) {
    case 0:
        selected = 0;
        break;
    case 1:
        selected = 1;
        break;
    case 2:
        selected = 6;
        break;
    }

    object = *(Object**)(self + 0x94);
    for (int i = 0; i < 8; i++) {
        Scene* scene =
            *(Scene**)(self + 0x1BC + lbl_14_rodata_3E8[i].scene * 4);
        scene->remove(object->model);
    }

    if (selected != 7) {
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            *(void**)(self + 0x1BC +
                      lbl_14_rodata_3E8[selected].scene * 4),
            object->model,
            lbl_14_rodata_3E8[selected].node);

        setFrameNode__8MuObjectFf(
            object, (float)lbl_14_rodata_3E8[selected].frame);
    }
}

extern "C" int fn_14_4238(char* self) {
    int choice;
    int state = *(int*)(self + 0x24C4);

    choice = *(int*)(self + 0x24D4);

    Input input(*(PadStatus*)&getRawPadStatus());
    u32 buttons = *(u32*)(self + 0x218);

    if (buttons & 8) {
        if (--choice < 0)
            choice = 0;

        if (choice == 1) {
            if (*(int*)(self + 0x2A28) != 0 ||
                64 - *(int*)(self + 0x24C0) <= 0)
                --choice;
        }
    }

    if (buttons & 4) {
        if (++choice >= 3)
            choice = 2;

        if (choice == 1) {
            if (*(int*)(self + 0x2A28) != 0 ||
                64 - *(int*)(self + 0x24C0) <= 0) {
                choice = *(int*)(self + 0x24C0) <= 0 ? 0 : choice + 1;
            }
        }

        if (*(int*)(self + 0x24C0) <= 0 && choice == 2)
            choice = 1;
    }

    if (choice != *(int*)(self + 0x24D4)) {
        updateSelection(self, choice);
        *(int*)(self + 0x24D4) = choice;
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
    }

    if (input.status.words[3] & 0x200) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 2, -1, 0, 0, -1);
        *(int*)(self + 0x44) = 7;
        state = 0x21;
    }

    if ((input.status.words[3] & 0x100) ||
        (input.status.words[3] & 0x1000)) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, -1, 0, 0, -1);

        switch (*(int*)(self + 0x24D4)) {
        case 0:
            if (*(int*)(self + 0x2A28) == 0)
                state = 0x18;
            else
                state = 0x20;
            break;
        case 1:
            state = 0x11;
            break;
        case 2:
            state = 3;
            break;
        }
    }

    if (choice == 2 && *(int*)(self + 0x24C0) <= 3) {
        *(int*)(self + 0x24E0) = 1;
        state = 4;
        *(int*)(self + 0x24D8) = 0;
    }

    return state;
}
