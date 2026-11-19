#include <mu/mu_object.h>
#pragma force_active on

extern "C" const double lbl_805A2388;
extern "C" const double lbl_805A2390;
extern "C" const float lbl_805A2370;
extern "C" const float lbl_805A2378;
extern "C" const float lbl_805A237C;
extern "C" const float lbl_805A2380;

class Class_8042EA48 {
public:
    virtual void fn_8005C534();
    virtual void fn_8005C2B0();
    virtual void fn_8005C20C();
    virtual void fn_8005C1BC();
    virtual void fn_8005C198();
    virtual void fn_8005C17C();
    virtual void fn_8005C160();
    virtual void fn_8005C0BC();
    virtual void fn_8005C06C();
    virtual void fn_8005C048();
    virtual void fn_8005C02C();
    virtual void fn_8005C010(int, void*);
    virtual void fn_8005BF6C();
    virtual void fn_8005BF1C(void*);

    char pad[0xe0];
    int count;
};

class Class_804664C0 {
public:
    virtual void fn_801B4A50();
    virtual void fn_801B45A0();
    virtual void fn_801B4918();
    virtual void fn_801B4AE8();
    virtual void fn_801B4AB8();
    virtual void fn_801AB788();
    virtual void fn_801AAC9C();
    virtual void fn_801AAE34();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AAA70();
    virtual void fn_801ABE70();
    virtual void fn_801ABFFC();
    virtual void fn_801AC0B8(void*);

    int count;
};

extern "C" void fn_800B753C(MuObject*, float);
extern "C" void fn_800B22B8(MuObject*);
extern "C" void fn_801B4CB0(Class_804664C0*, void*, unsigned int);

struct Entry {
    unsigned int id;
    int digit;
};

struct Self {
    unsigned char active : 1;
    unsigned char option : 1;
    unsigned char showHours : 1;
    unsigned char rest : 5;
    char pad1[7];
    Class_8042EA48* parent;
    Class_8042EA48* other;
    MuObject* separator;
    MuObject* digits[8];
    MuObject* animation;
    char pad2[0x11c];
    Class_804664C0* manager;
    char pad3[0x20];
    int timer;
    unsigned int time;
    unsigned int ids[8];
    Entry entries[8];
};

struct Part {
    int value;
    int mode;
};

union TempObjectFlag {
    MuObject* object;
    int flag;
};

extern "C" void fn_800DDCF8(Self* self, unsigned int time) {
    if (self->active) {
        self->time = time;
        int clamped = 0;
        TempObjectFlag state;
        state.flag = 0;

        if (!self->option && (float)time <= lbl_805A2370) {
            Class_804664C0* model = self->manager;
            if (model->count != 0) {
                if (self->other)
                    self->other->fn_8005BF1C(model);
                else
                    self->parent->fn_8005BF1C(model);
            }

            state.object = self->animation;
            float frame = (float)(301U - time);
            state.object->setFrameNode(frame);
            state.object->setFrameVisible(frame);
            state.object->setFrameMatCol(frame);

            void* animationModel = state.object->m_sceneModel;
            if (*(int*)((char*)animationModel + 4) == 0) {
                if (self->other)
                    self->other->fn_8005C010(self->other->count, animationModel);
                else
                    self->parent->fn_8005C010(self->parent->count, animationModel);
            }
        } else {
            bool skip = false;
            if (self->timer >= 0) {
                if (self->timer < 0 || (self->timer % 15) / 7 > 0)
                    skip = false;
                else
                    skip = true;
                if (skip)
                    return;
            }

            void* animationModel = self->animation->m_sceneModel;
            if (*(int*)((char*)animationModel + 4) != 0) {
                if (self->other)
                    self->other->fn_8005BF1C(animationModel);
                else
                    self->parent->fn_8005BF1C(animationModel);
            }

            Part parts[4];

            if (self->showHours) {
                if (time >= 0x1499700U) {
                    parts[0].value = 99;
                    clamped = 1;
                    parts[1].value = 59;
                    parts[2].value = 59;
                    parts[3].value = 99;
                }
            } else if (time >= 0x57e40U) {
                parts[0].value = 0;
                clamped = 1;
                parts[1].value = 99;
                parts[2].value = 59;
                parts[3].value = 99;
            }

            if (!clamped) {
                unsigned int rem = time;
                parts[0].value = rem / 216000;
                rem %= 216000;
                parts[1].value = rem / 3600;
                rem %= 3600;
                parts[2].value = rem / 60;
                rem %= 60;
                unsigned int framesPerSecond = 60;
                parts[3].value = (int)(lbl_805A2378 * (float)rem / (float)framesPerSecond);

                if (!self->showHours) {
                    parts[1].value += parts[0].value * 60;
                    parts[0].value = 0;
                }
            }

            if (!self->showHours) {
                parts[0].mode = 0;
                parts[1].mode = 2;
            } else if (parts[0].value > 0) {
                parts[0].mode = 2;
                state.flag = 1;
                parts[1].mode = 1;
            } else {
                parts[0].mode = 0;
                parts[1].mode = 2;
            }

            parts[2].mode = 1;
            parts[3].mode = 1;

            int mode;
            Part* partValue;
            char* digitPtr;
            Entry* entry;
            char* ids;
            char* idPtr;
            Part* partMode;
            int i;
            int j;
            int value;
            int n;
            Class_804664C0* manager;

            partMode = parts;
            partValue = partMode;
            manager = self->manager;
            digitPtr = (char*)self;
            ids = (char*)self;
            entry = self->entries;
            n = 0;
            for (i = 0; i < 4; ++i, ++partValue, ids += 8, ++partMode) {
                mode = partMode->mode;
                if (mode) {
                    value = partValue->value;
                    idPtr = ids;
                    for (j = 0; j < 2; ++j, idPtr += 4) {
                        MuObject* obj = ((Self*)digitPtr)->digits[0];
                        int digit = value % 10;

                        if (entry->digit != digit) {
                            entry->digit = digit;
                            fn_800B753C(obj, (float)digit);
                        }

                        unsigned int id = ((Self*)idPtr)->ids[0];
                        if (entry->id != id) {
                            entry->id = id;
                            manager->fn_801AC0B8(obj->m_sceneModel);
                            fn_801B4CB0(manager, obj->m_sceneModel, id);
                            fn_800B22B8(obj);
                        }

                        digitPtr += 4;
                        ++entry;
                        ++n;
                        value /= 10;

                        if (mode == 2 && value <= 0)
                            break;
                    }
                }
            }

            Entry* remainingEntry = self->entries + n;
            char* remainingDigit = (char*)self + n * 4;
            while (n < 8) {
                if (remainingEntry->id == 0xffffffffU)
                    break;
                remainingEntry->id = 0xffffffffU;
                manager->fn_801AC0B8(((Self*)remainingDigit)->digits[0]->m_sceneModel);
                ++remainingEntry;
                remainingDigit += 4;
                ++n;
            }

            Class_804664C0* model = self->manager;
            if (model->count == 0) {
                if (self->other)
                    self->other->fn_8005C010(self->other->count, model);
                else
                    self->parent->fn_8005C010(self->parent->count, model);
            }

            fn_800B753C(self->separator, state.flag ? lbl_805A237C : lbl_805A2380);
        }
    }
}