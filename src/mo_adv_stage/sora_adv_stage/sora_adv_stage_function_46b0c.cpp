#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <stdio.h>
#include <string.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(void*);
};

struct Name33 {
    char text[33];
};

struct Name17 {
    char text[17];
};

struct Entry {
    unsigned char active : 1;
    unsigned char markerFlag : 1;
    unsigned char otherFlags : 6;
    signed char color;
    char pad02[0x15];
    unsigned char icons[42];
    unsigned char count;
    short type;
    char pad44[0x14];
};

struct Row {
    MuObject* visible;
    MuObject* color;
    MuObject* marker;
    MuObject* node;
    MuObject* icons[42];
    Object_vptr_0* model;
    Object_vptr_0* iconModel;
};

struct Stage {
    char pad000[0x1bc];
    int count;
    Entry entries[0x35];
    char pad13f8[0x1c];
    int selected;
    char pad1418[0xc];
    int state;
    char pad1428[0xc];
    float scroll;
    char pad1438[0x78];
    char iconData[0xbc];
    void* positionObject;
    MuObject* selection;
    char pad1574[8];
    Object_vptr_0* root;
    Row rows[4];
    char pad1880[8];
    void* messages;
};

extern "C" {
extern char lbl_40_data_17DC0[];
extern char lbl_40_data_18440[];
extern char lbl_40_data_1844C[];
extern const float lbl_40_rodata_B00;
extern const float lbl_40_rodata_B38;

double fn_804008E4(double, double*);
void fn_800B6838(void*, const Vec3f*);
void fn_800B7184(void*, const char*, int, void*);
void fn_40_4571C(Stage*, Entry*, int, float);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}

extern "C" void fn_40_46B0C(Stage* self) {
    Name17 result;
    Name17 prefix;
    Name17 name17;
    Name17 numbered;
    const char* suffix;
    int visible;
    char* data = lbl_40_data_17DC0;
    Name33 base;
    base.text[0] = '\0';
    strcat(base.text, data + 0x134);

    const char* iconPrefix;
    char* markerText;
    char* numberText;
    Row* row;
    int messageIndex;
    MuObject** icon;
    Row* rows;
    float scroll = self->scroll;
    int selected = self->selected;
    double integer;
    float fraction = (float)fn_804008E4(scroll, &integer);
    int first = (int)(float)integer;
    int i;
    int remaining = self->count - first;
    selected -= first;
    visible = 4;
    if (remaining < 4) {
        visible = remaining;
    }

    Vec3f pos;
    pos.m_x = lbl_40_rodata_B00;
    pos.m_y = lbl_40_rodata_B38 * fraction;
    pos.m_z = lbl_40_rodata_B00;
    fn_800B6838(self->positionObject, &pos);

    Name33 outSelection, outMarker, outRow;
    self->root->slot13(self->selection->m_sceneModel);
    if (self->state == 0 && selected >= 0 && selected < visible) {
        Name33 name = base;
        sprintf(name.text + strlen(name.text), lbl_40_data_1844C, selected);
        outSelection = name;
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            self->root, self->selection->m_sceneModel, outSelection.text);
    }

    Name33 markerName;
    rows = self->rows;
    numberText = numbered.text;
    markerText = markerName.text;
    iconPrefix = data + 0x23c;
    row = rows;
    i = 0;
    messageIndex = 0;
    for (; i < visible; ++row, messageIndex += 6, ++i) {
        Entry* entry = &self->entries[first + i];
        int mode;
        if (entry->type == 0) {
            mode = 1;
        } else {
            mode = 3;
        }
        if (!entry->active) {
            int previous = mode;
            mode = 2;
            if (previous == 1) {
                mode = 0;
            }
        }

        row->visible->setFrameVisible((float)mode);
        row->visible->setFrameTex((float)entry->type);

        switch (mode) {
        case 1:
        case 3: {
            float frame = (float)(entry->color + 1);
            row->color->setFrameTex(frame);
            row->color->setFrameMatCol(frame);
            row->model->slot13(row->marker->m_sceneModel);
            if (entry->markerFlag) {
                markerName = base;
                sprintf(markerText + strlen(markerName.text), lbl_40_data_1844C,
                        *(int*)(data + 0x238));
                outMarker = markerName;
                Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                    row->model, row->marker->m_sceneModel, outMarker.text);
            }
            row->node->setFrameNode((float)(entry->count - 1));
            for (unsigned int j = 0; j < 42; ++j) {
                row->iconModel->slot13(row->icons[j]->m_sceneModel);
            }
            int j = 0;
            if (j < entry->count) {
            icon = row->icons;
            for (; j < entry->count; ++icon, ++j) {
                fn_800B7184(*icon, data + 0x240,
                            entry->icons[j] + 1, self->iconData);
                suffix = data + 0x230;
                if (j < 10) {
                    suffix = data + 0x250;
                }
                prefix.text[0] = '\0';
                strcat(prefix.text, iconPrefix);
                name17 = prefix;
                strcat(name17.text, suffix);
                numbered = name17;
                sprintf(numberText + strlen(numbered.text),
                        lbl_40_data_18440, j);
                result = numbered;
                Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                    row->iconModel, (*icon)->m_sceneModel, result.text);
            }
            }
            fn_40_4571C(self, entry, i, fraction);
            break;
        }
        case 0:
        case 2: {
            int zero = 0;
            row->color->setFrameTex((float)zero);
            row->color->setFrameMatCol((float)zero);
            row->model->slot13(row->marker->m_sceneModel);
            for (unsigned int j = 0; j < 42; ++j) {
                row->iconModel->slot13(row->icons[j]->m_sceneModel);
            }
            unsigned long index = messageIndex;
            printf__5MuMsgFUlPCce(self->messages, index++, data + 0x230);
            printf__5MuMsgFUlPCce(self->messages, index++, data + 0x230);
            printf__5MuMsgFUlPCce(self->messages, index++, data + 0x230);
            printf__5MuMsgFUlPCce(self->messages, index++, data + 0x230);
            printf__5MuMsgFUlPCce(self->messages, index++, data + 0x230);
            printf__5MuMsgFUlPCce(self->messages, index, data + 0x230);
            break;
        }
        }
    }

    Name33 name;
    char* finalText = name.text;
    unsigned int finalIndex;
    for (finalIndex = 0; finalIndex < 4; ++finalIndex) {
        Row* row = &rows[finalIndex];
        self->root->slot13(row->model);
        if ((int)finalIndex < visible || lbl_40_rodata_B00 != fraction) {
            name = base;
            sprintf(finalText + strlen(name.text), lbl_40_data_1844C, finalIndex);
            outRow = name;
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                self->root, row->model, outRow.text);
        }
    }
}
