#include <gf/gf_pad_system.h>
#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_scngroup.h>
#include <stdio.h>
#include <string.h>

#pragma force_active on

extern "C" void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern "C" int fn_8006CEEC(char*, int);

extern char lbl_16_data_3308[];
extern unsigned char lbl_16_rodata_58[];
extern float lbl_16_rodata_30;

struct Self {
    int active;
    char* text;
    int capacity;
    char buffer[0x18];
    int indexes[6];
    int selected;
    int frame;
    MuObject* base;
    MuObject* options[5];
    MuObject* node;
    MuObject* cursor;
    MuMsg* msg;
    char pad68[4];
    nw4r::g3d::ScnGroup* scene;
    unsigned long msgIndex;
    int position;
    MuObject* current;
    unsigned char flag;
    char pad7d[3];
    int value;
    int length;
    char pad88[4];
    int timer;
    int padIndex;
};

extern "C" void fn_16_5A8(Self* self, const char* name, char* buffer, int capacity) {
    self->active = 1;
    if (buffer) {
        self->text = buffer;
        self->capacity = capacity;
    } else {
        self->text = self->buffer;
        self->capacity = 5;
    }

    if (name)
        strcpy(self->text, name);
    else
        *self->text = 0;

    if (self->msg)
        self->msg->printf(self->msgIndex, self->text);

    self->current = 0;
    char pos2[12];
    char pos[12];
    sprintf(pos, lbl_16_data_3308, self->position + 1);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->base->m_sceneModel, pos);

    MuObject* option;
    int index = self->indexes[self->selected];
    if (self->current) {
        self->scene->Remove(self->current->m_sceneModel);
        self->current = 0;
    }

    option = self->options[index];
    sprintf(pos2, lbl_16_data_3308, self->position + 1);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, option->m_sceneModel, pos2);
    self->current = option;
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->node->m_sceneModel, pos);
    if (self->cursor)
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scene, self->cursor->m_sceneModel, pos);

    int frame;
    if (*self->text) {
        self->value = 10;
        frame = 13;
    } else {
        frame = 1;
        self->value = frame;
    }

    float f = (float)(frame + 1);
    self->base->setFrameMatCol(f);
    if (self->current)
        self->current->setFrameMatCol(f);
    self->node->setFrameNode(f);
    self->frame = frame;
    self->flag = 1;

    int length = fn_8006CEEC(self->text, 0x7fff);
    if (!self->flag) {
        length--;
        if (length < 0)
            length = 0;
    }

    int max = self->capacity - 1;
    if (length > max)
        length = max;
    if (self->cursor)
        self->cursor->setFrameNode((float)(length + 1));

    self->length = length;
    self->timer = 0x23;

    int type;
    gfPadStatus status;
    if (self->padIndex >= 0 && self->padIndex < 8) {
        g_gfPadSystem->getSysPadStatus(self->padIndex, &status);
        type = status.m_controllerType;
    } else {
        type = 4;
    }

    unsigned int tex;
    if (type >= 0 && type < 4)
        tex = lbl_16_rodata_58[type];
    else
        tex = 4;

    self->base->setFrameTex((float)tex);
    self->base->m_modelAnim->m_anmObjTexPatRes->SetUpdateRate(lbl_16_rodata_30);
}
