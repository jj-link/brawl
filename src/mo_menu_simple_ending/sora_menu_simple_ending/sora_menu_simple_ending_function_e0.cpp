#include <gf/gf_pad_system.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>
#pragma force_active on

struct EndingScene {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void attach(void*, nw4r::g3d::ScnMdl*);
    virtual void slot38();
    virtual void detach(nw4r::g3d::ScnMdl*);

    char padding[0xE0];
    void* fieldE4;
};

struct EndingParent {
    char padding[0x48];
    EndingScene* scene;
};

struct EndingMenu {
    char padding[0x48];
    EndingParent* parent;
    MuObject* object;
    unsigned int field50;
    unsigned int state;
    unsigned int counter;
};

struct EndingGameData {
    char padding[0x2E];
    unsigned char flags;
};

struct EndingGlobal {
    char padding[0x10];
    EndingGameData* data;
};

extern "C" {
extern EndingGlobal* g_GameGlobal;
extern char lbl_19_data_8[];
extern const float lbl_19_rodata_0[];
unsigned int fn_800B6310(MuObject*);
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

extern "C" void fn_19_E0(EndingMenu* self) {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);

    switch (self->state) {
    case 1:
        self->state = 2;
        break;

    case 2:
        if ((((unsigned int)g_GameGlobal->data->flags >> 5) & 7) == 4) {
            g_sndSystem->playSE((SndID)0x1FD4, -1, 0, 0, -1);
        } else {
            g_sndSystem->playSE((SndID)0x1FD3, -1, 0, 0, -1);
        }
        {
            EndingScene* scene = self->parent->scene;
            scene->attach(scene->fieldE4, self->object->m_scnMdl);
        }
        self->state = 3;
        self->counter = 0;
        break;

    case 3:
        if (endingPressed(status.m_buttonsPressedThisFrame.bits) == 1) {
            g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
            self->state = 4;
        }
        break;

    case 4:
        self->state = 5;
        break;

    case 5:
        self->object->changeClrAnimN(lbl_19_data_8);
        self->object->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(lbl_19_rodata_0[0]);
        self->state = 6;
        break;

    case 6:
        if (fn_800B6310(self->object) == 1) {
            self->state = 7;
        }
        break;

    case 7:
        {
            EndingScene* scene = self->parent->scene;
            scene->detach(self->object->m_scnMdl);
        }
        self->state = 8;
        break;

    case 9:
        break;
    }

    ++self->counter;
}
