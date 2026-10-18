#pragma force_active on
struct gfPadStatus {
    unsigned char data[0x3c];
    int type;
};

struct gfPadSystem {
    void getSysPadStatus(int, gfPadStatus*);
};

struct MuObject {
    void setFrameTex(float);
};

extern gfPadSystem* g_gfPadSystem;
extern const float lbl_3_rodata_8160[];

struct Menu {
    char pad[0x638];
    MuObject* object;
    char pad2[0x9f4 - 0x63c];
    int index;
    char pad3[0xb1c - 0x9f8];
    unsigned char state;
};

extern "C" void fn_3_A3A0(Menu* self) {
    const float* values = lbl_3_rodata_8160;
    gfPadStatus status;
    unsigned int state = self->state;
    int index = self->index;

    if (index >= 0 && index < 8)
        g_gfPadSystem->getSysPadStatus(index, &status);
    else
        state = 0;

    if (state == 1) {
        switch (status.type) {
        case 0:
            self->object->setFrameTex(values[0x8c / 4]);
            break;
        case 3:
            self->object->setFrameTex(values[0xa4 / 4]);
            break;
        case 2:
            self->object->setFrameTex(values[0xa0 / 4]);
            break;
        case 1:
            self->object->setFrameTex(values[0xa8 / 4]);
            break;
        default:
            self->object->setFrameTex(values[0xac / 4]);
            break;
        }
    } else {
        self->object->setFrameTex(values[0xac / 4]);
    }
}
