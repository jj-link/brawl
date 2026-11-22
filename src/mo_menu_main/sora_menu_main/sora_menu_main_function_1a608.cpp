#include <gf/gf_model.h>
#include <gf/gf_pad_system.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>
#include <string.h>

#pragma force_active on

struct AnimInfoA {
    char pad[0x10];
    unsigned value;
};

struct AnimInfoB {
    char pad[0x0c];
    unsigned value;
};

struct MenuObject {
    char pad[0x0c];
    char* scene;
    char pad10[4];
    gfModelAnimation* anim;
    AnimInfoA* a;
    AnimInfoB* b;
};

struct MenuContext {
    char pad[0x40];
    int state;
    char pad44[0x224 - 0x44];
    int action;
    char pad228[0x254 - 0x228];
    int category;
    int categoryIndex;
    char pad25c[4];
    int padIndex;
    char pad264[0x274 - 0x264];
    int result;
};

struct RecordManager {
    unsigned pad;
    unsigned counts[45];
    unsigned getCount(int category) {
        if (category >= 45) return 0;
        return counts[category];
    }
};

class MenuView {
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
    virtual void slot14();
    virtual void slot15();
};

struct MenuBase {
    char pad0[0x42];
    unsigned short selection;
    char pad44[0x634 - 0x44];
    int result;
    char pad638[0x64c - 0x638];
    MenuObject** objects;
    void** resources;
    MenuView* view;
    char pad658[0x664 - 0x658];
    int mode;
};

struct Menu : MenuBase {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6(unsigned);

    char pad66c[4];
    int category;
    unsigned char flag;
    char pad675;
    unsigned short field676;
    unsigned short field678;
    char pad67a[2];
    int controllerType;
    int field680;
    unsigned total;
    int count4;
    int count5;
    char pad690[4];
    MenuContext* context;
    int records[15];
    unsigned recordCount;
};

struct CategoryTable {
    int values[66];
};

extern "C" {
extern const float lbl_2_rodata_688[];
extern char lbl_2_data_2460[];
extern CategoryTable lbl_2_data_2528;
extern RecordManager* lbl_805A01D8;

int fn_80078D8C(RecordManager*, int, unsigned);
unsigned fn_8004F978(int);
void fn_80078DAC(RecordManager*, int, int, int);
void fn_801AAFF0(void*, int);
void fn_801AB014(void*, int);
void fn_2_1B958(Menu*, unsigned, int, int);
void fn_18_17B0(Menu*, int, int, float);
void fn_80073F84(sndSystem*, int);
float getFrame__16gfModelAnimationFd(gfModelAnimation*);
void fn_800B330C(MenuObject*, void*, int);
unsigned fn_18_12E0(Menu*);
void fn_11_69D0(MenuContext*);
}

extern "C" int fn_2_1A608(Menu* self) {
                    int record;
    const float* ro = lbl_2_rodata_688;

    switch (self->mode) {
    case 0: {
        MenuContext* context = self->context;
        int result;
        if (context->state == 2)
            result = context->result;
        else if (context->action != 11)
            result = 0;
        else
            result = context->result;

        if (result == 1) {
            if (context->category == 2) {
                self->category = 42;
            } else {
                int index;
                if (context->category == 0)
                    index = 66;
                else if (context->category == 1)
                    index = context->categoryIndex;
                else
                    index = 0;
                CategoryTable table = lbl_2_data_2528;
                self->category = table.values[index];
            }

            self->selection = 0;
            self->field676 = 0;
            self->field678 = 0;
            self->mode = 1;
            memset(self->records, 0, sizeof(self->records));
            self->recordCount = 0;

            if (self->category == 4) {
                unsigned count = 0;
                unsigned i = 0;
                unsigned n = lbl_805A01D8->counts[4];
                for (; i < n; ++i) {
                    if (fn_8004F978(fn_80078D8C(lbl_805A01D8, 4, i)) == 1)
                        ++count;
                }
                self->count4 = count;

                unsigned j;
                unsigned count2 = 0;
                j = 0;
                n = lbl_805A01D8->counts[5];
                for (; j < n; ++j) {
                    if (fn_8004F978(fn_80078D8C(lbl_805A01D8, 5, j)) == 1)
                        ++count2;
                }
                self->count5 = count2;

                self->total = 0;
                self->total = lbl_805A01D8->counts[4];
                self->total = self->total + lbl_805A01D8->counts[5];

                n = lbl_805A01D8->counts[4];
                for (count2 = 0; count2 < n; ++count2) {
                    int record = fn_80078D8C(lbl_805A01D8, 4, count2);
                    if (fn_8004F978(record)) {
                        self->records[self->recordCount] = record;
                        ++self->recordCount;
                    }
                }
                n = lbl_805A01D8->counts[5];
                for (count2 = 0; count2 < n; ++count2) {
                    int record = fn_80078D8C(lbl_805A01D8, 5, count2);
                    if (fn_8004F978(record)) {
                        self->records[self->recordCount] = record;
                        ++self->recordCount;
                    }
                }
            } else {
                self->total = lbl_805A01D8->getCount(self->category);

                int category = self->category;
                record = lbl_805A01D8->getCount(category);
                unsigned count;
                for (unsigned i = 0; i < (unsigned)record; ++i) {
                    count = fn_80078D8C(lbl_805A01D8, category, i);
                    if (fn_8004F978(count)) {
                        self->records[self->recordCount] = count;
                        ++self->recordCount;
                    }
                }
            }

            if (self->category == 4) {
                int value;
                MenuObject* object = self->objects[0x5c];
                value = (unsigned char)object->scene[0xd0] + 2;
                fn_801AAFF0(object->scene, value);
                fn_801AB014(object->scene, value);
            }

            unsigned count = self->recordCount;
            if (count > 4)
                count = 4;
            fn_2_1B958(self, count, 0, 1);
            if (self->recordCount <= 4)
                fn_18_17B0(self, 0x60, 2, ro[1]);
            else
                fn_18_17B0(self, 0x60, 2, ro[2]);
            fn_18_17B0(self, 0x60, 1, ro[1]);
            fn_80073F84(g_sndSystem, 0);

            self->flag = 0;
            self->field680 = 0;
            int selected = self->flag;
            gfPadStatus status;
            g_gfPadSystem->getSysPadStatus(self->context->padIndex, &status);
            self->controllerType = status.m_controllerType;

            float frame;
            if (selected)
                frame = ro[2];
            else
                frame = ro[1];
            switch (self->controllerType) {
            case 1: frame += ro[3]; break;
            case 2: frame += ro[4]; break;
            case 3: frame += ro[5]; break;
            }
            reinterpret_cast<MuObject*>(self->objects[0x60])->setFrameTex(frame);
            return 4;
        }

        if (context->action == 1) {
            self->result = 5;
            self->mode = 4;
            return 1;
        }
        break;
    }

    case 1:
        if (ro[6] == getFrame__16gfModelAnimationFd(self->objects[0x58]->anim)) {
            fn_800B330C(self->objects[0x58], lbl_2_data_2460 + 0x3c, 1);
            self->mode = 2;
        }
        break;

    case 2: {
        bool selected = (int)self->objects[0x60]->anim->m_anmObjTexPatRes->GetFrame() % 2 != 0;
        gfPadStatus status;
        g_gfPadSystem->getSysPadStatus(self->context->padIndex, &status);
        self->controllerType = status.m_controllerType;

        float frame;
        if (selected)
            frame = ro[2];
        else
            frame = ro[1];
        switch (self->controllerType) {
        case 1: frame += ro[3]; break;
        case 2: frame += ro[4]; break;
        case 3: frame += ro[5]; break;
        }
        reinterpret_cast<MuObject*>(self->objects[0x60])->setFrameTex(frame);

        MenuObject* object = self->objects[self->field678 + 0x58];
        unsigned type;
        if (object->a)
            type = object->a->value;
        else if (object->b)
            type = object->b->value;
        else
            type = -1;

        if (type == 4 && getFrame__16gfModelAnimationFd(object->anim) >= ro[7])
            fn_800B330C(self->objects[self->field678 + 0x58],
                         lbl_2_data_2460 + 0x28, 1);

        unsigned offset;
        unsigned flags = fn_18_12E0(self);
        if (flags & 0x20) {
            if (!self->flag)
                fn_80078DAC(lbl_805A01D8, 42, 0, 0);
            g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
            unsigned i = 0;
            offset = 0;
            for (; i < 4; ++i, offset += 4) {
                MenuObject** objects = (MenuObject**)((char*)self->objects + offset);
                fn_800B330C(objects[0x58], lbl_2_data_2460 + 0x50, 1);
                if (i == self->field678)
                    fn_800B330C(((MenuObject**)((char*)self->objects + offset))[0x58], lbl_2_data_2460 + 0x50, 1);
                else
                    fn_800B330C(((MenuObject**)((char*)self->objects + offset))[0x58], lbl_2_data_2460 + 0x64, 1);
            }
            self->mode = 3;
            fn_11_69D0(self->context);
        }
        self->slot6(flags);
        break;
    }

    case 3:
        if (ro[6] == getFrame__16gfModelAnimationFd(self->objects[0x58]->anim)) {
            int offset;
            int i = 0;
            offset = 0;
            for (; i < 4; ++i, offset += 4)
                self->view->slot13(((void**)((char*)self->resources + offset))[5]);
            self->mode = 0;
        }
        break;

    case 4: {
        MenuContext* context = self->context;
        int result;
        if (context->state == 2)
            result = context->result;
        else if (context->action != 11)
            result = 0;
        else
            result = context->result;
        if (result == 2)
            return 3;
        break;
    }
    }
    return 0;
}
