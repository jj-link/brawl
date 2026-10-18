#pragma force_active on
typedef unsigned int u32;

struct MuObject {
    void setFrameMatCol(float);
};

enum SndID {
    SndZero = 0
};

struct sndSystem {
    void playSE(SndID, int, int, int, int);
};

extern sndSystem* g_sndSystem;
extern "C" float lbl_2_rodata_EF0;
extern "C" float lbl_2_rodata_EF4;

struct MenuData {
    char pad[0x2b4];
    MuObject* object;
};

struct Menu {
    char pad[0x64c];
    MenuData* data;
    char pad2[0x1c];
    unsigned char unused : 1;
    unsigned char selected : 1;
    unsigned char rest : 6;
};

extern "C" u32 fn_18_12E0(Menu*);

extern "C" int fn_2_2B3F4(Menu* self) {
    u32 input = fn_18_12E0(self);
    MuObject* obj = self->data->object;

    if (input & 0x20) {
        g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
        return 1;
    }

    if (input & 0x10) {
        if (!self->selected) {
            g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
            return 1;
        }
        g_sndSystem->playSE((SndID)0x28, -1, 0, 0, -1);
        return 0;
    }

    if ((input & 8) && self->selected) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        obj->setFrameMatCol(lbl_2_rodata_EF0);
        self->selected = 0;
    }

    if ((input & 4) && self->selected != 1) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        obj->setFrameMatCol(lbl_2_rodata_EF4);
        self->selected = 1;
    }

    return 2;
}
