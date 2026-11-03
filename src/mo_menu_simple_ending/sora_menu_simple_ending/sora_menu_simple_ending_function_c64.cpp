#include <gf/gf_pad_system.h>
#include <gf/gf_3d_scene.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" {
void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void* root, int layer, void* mdl);
void fn_8000D1B8(void* root, int layer, void* mdl);
}

union EndingButtons {
    unsigned int bits;
    struct {
        unsigned int padding : 11;
        unsigned int confirm : 1;
        unsigned int remaining : 20;
    } fields;
};

inline unsigned int endingPressed(unsigned int buttons) {
    EndingButtons input;
    input.bits = buttons;
    if (buttons & 0x100)
        return 1;
    if (buttons & 0x200)
        return 1;
    if (buttons & 0x1000)
        return 1;
    return input.fields.confirm;
}

struct EndingObject48 {
    char pad[0x10];
    nw4r::g3d::ScnMdl* mdl;
};

struct EndingMenu {
    char pad0[0x48];
    EndingObject48* field48;
    char pad1[0x964];
    int field9B0;
    int field9B4;
    int state;
    int counter;
};

extern "C" void fn_19_C64(EndingMenu* self) {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);

    switch (self->state) {
    case 1:
        self->state = 2;
        break;

    case 2:
        add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 8, self->field48->mdl);
        self->state = 3;
        break;

    case 3:
        if (endingPressed(status.m_buttonsPressedThisFrame.bits) == 1) {
            self->state = 4;
        }
        if (self->field9B0 <= self->field9B4 + 1) {
            self->state = 4;
        }
        break;

    case 4:
        fn_8000D1B8(g_gfSceneRoot, 8, self->field48->mdl);
        self->state = 5;
        break;

    case 5:
    case 6:
        break;
    }

    ++self->counter;
}
