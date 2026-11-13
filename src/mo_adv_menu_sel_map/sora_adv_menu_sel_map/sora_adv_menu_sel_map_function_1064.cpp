#include <gf/gf_pad_system.h>
#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#include <snd/snd_system.h>
#include <stdio.h>
#pragma force_active on

struct MapTask {
    char pad[0x100];
    unsigned char result;
    char pad101[3];
    int state;
};

struct MapEntry {
    int unknown;
    int state;
    char pad[0xC];
};

struct MapGlobal {
    char pad[0x30];
    MapEntry* entries;
};

struct MapPosition {
    float x;
    float y;
};

union MapPositionWords {
    MapPosition pos;
    unsigned int words[2];
};

union MapButtons {
    unsigned int bits;
    struct {
        unsigned int padding : 30;
        unsigned int right : 1;
        unsigned int left : 1;
    } fields;
};

struct MapMenu {
    char pad00[0x40];
    int state;
    int result;
    int selectedMap;
    int selectedOption;
    char pad50[9];
    unsigned char mapMode;
    unsigned char secondPlayer;
    char pad5B;
    int player;
    int otherPlayer;
    char pad64[0x10];
    unsigned int directions;
    char pad78[0x94];
    char playerInfo[0xB0];
    int delay;
    MuMsg* message;
    int positionObject;
    MuObject* transitionObject;
    char pad1CC[0x22C];
    MuObject* playerObject;
    MuObject* visibleObject;
    char pad400[0x9C];
    int dialogData;
    int dialogArgument;
    int dialogState;
    char pad4A8[4];
    int scroll;
    int scrollTarget;
    int scrollLimit;
    unsigned char pending;
    char pad4B9;
    unsigned char skipOption;
    char pad4BB;
    int pendingOption;
    char pad4C0[0x11C];
    MapTask* dialog;
    int dialogResource;
    unsigned char dialogOpen;
    char pad5E5;
    unsigned char inputDisabled;
    char pad5E7;
    int mapCounter;
};

extern "C" {
extern MapGlobal* g_GameGlobal;
extern char lbl_31_data_0[];
extern char lbl_31_data_328[];
extern const float lbl_31_rodata_0[];

void fn_800B96E8(void*, unsigned char);
void fn_800B753C(MuObject*, float);
void fn_800B672C(int, MapPosition*, const char*);
MapTask* fn_800BEEB8(int, int, int, void*, int, int, int, int,
                     int, int, int, int);
void exit__6gfTaskFv(void*);
int fn_31_AFC(MapMenu*, int, int);
unsigned int fn_31_F0C(MapMenu*, gfPadStatus*);
unsigned int fn_31_FB8(MapMenu*, gfPadStatus*);
void fn_31_2264(MapMenu*, int);
void fn_31_2648(MapMenu*, int);
}

static inline unsigned int mapBusy(int state) {
    if (state == 2 || state == 3 || state == 4 ||
        state == 8 || state == 9 || (unsigned int)(state - 5) <= 1)
        return 1;
    return 0;
}

static inline unsigned int mapDirection(MapMenu* self, gfPadStatus* status,
                                        unsigned int buttons) {
    MapButtons input;
    input.bits = buttons;
    if (fn_31_F0C(self, status) == 1 || fn_31_FB8(self, status) == 1)
        return 0;
    if (buttons & 8)
        return 1;
    if (buttons & 4)
        return 1;
    if (buttons & 1)
        return 1;
    return input.fields.right;
}

static inline unsigned int mapConfirm(gfPadStatus* status) {
    switch (status->m_controllerType) {
    case 0:
    case 1:
    case 3:
        if (status->m_buttonsPressedThisFrame.bits & 0x100)
            return 1;
        break;
    case 2:
        if (!(status->m_buttonsCurrentFrame2.bits & 0x400000) &&
            (status->m_buttonsPressedThisFrame.bits & 0x20000))
            return 1;
        break;
    }
    return 0;
}

static inline unsigned int mapCancel(gfPadStatus* status) {
    switch (status->m_controllerType) {
    case 0:
    case 1:
    case 3:
        if (status->m_buttonsPressedThisFrame.bits & 0x200)
            return 1;
        break;
    case 2:
        if (!(status->m_buttonsCurrentFrame2.bits & 0x400000) &&
            (status->m_buttonsPressedThisFrame.bits & 0x10000))
            return 1;
        break;
    }
    return 0;
}

extern "C" void fn_31_1064(MapMenu* self) {
    const float* ro;
    const char* data;
    data = lbl_31_data_0;
    ro = lbl_31_rodata_0;
    gfPadStatus other;
    gfPadStatus pad;
    gfPadStatus scan;
    MapPosition position[5];
    char name[8];
    int oldMap;
    unsigned int directions;
    int selectedMap;
    int option;
    int positionObject;
    MuObject* obj;

    if (self->delay > 0 && --self->delay > 0)
        return;

    if (!self->inputDisabled) {
        directions = self->directions;
        g_gfPadSystem->getSysPadStatus(self->player, &pad);
        if (self->otherPlayer >= 0)
            g_gfPadSystem->getSysPadStatus(self->otherPlayer, &other);
        else
            other.init();
    } else {
        directions = 0;
        pad.init();
        other.init();
    }

    oldMap = self->selectedMap;
    option = self->selectedOption;
    selectedMap = oldMap;

    if (mapBusy(self->state) == 1)
        return;
    if (self->dialogState == 3)
        return;

    if (!self->dialogOpen && !self->inputDisabled) {
        int found = -1;
        for (int i = 0; i < 8; ++i) {
            if (i != self->player) {
                g_gfPadSystem->getSysPadStatus(i, &scan);
                if (scan.m_buttonsCurrentFrame2.bits & 0x1000)
                    found = i;
            }
        }

        if (found >= 0 && !self->secondPlayer) {
            self->otherPlayer = found;
            self->state = 4;
            fn_800B96E8(self->playerInfo, (unsigned char)found);
            obj = self->playerObject;
            obj->changeAnimN(data + 0x94);
            obj->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[16]);
            obj->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(ro[16]);
            g_sndSystem->playSE((SndID)0x2288, -1, 0, 0, -1);
            g_sndSystem->playSE((SndID)0x26, -1, 0, 0, -1);
        }

        if (other.m_buttonsPressedThisFrame.bits & 0x200) {
            if (self->secondPlayer == 1) {
                g_sndSystem->playSE((SndID)0x2052, -1, 0, 0, -1);
                obj = self->playerObject;
                self->state = 0;
                self->secondPlayer = 0;
                obj->changeAnimN(lbl_31_data_328);
                fn_800B753C(obj, ro[13]);
                obj->m_modelAnim->setUpdateRate(ro[16]);
                self->message->printf(5, data + 0xAC);
            } else {
                g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
            }
        }
    }

    if (mapBusy(self->state) == 1)
        return;

    if (self->mapMode) {
        if (!self->inputDisabled && !self->pending) {
            if (mapDirection(self, &pad, directions) == 1)
                selectedMap = fn_31_AFC(self, 0, oldMap);
        } else {
            selectedMap = oldMap;
        }

        positionObject = self->positionObject;
        sprintf(name, data + 0x28, selectedMap);
        fn_800B672C(positionObject, &position[3], name);
        float srcY = position[3].y;
        float srcX = position[3].x;
        position[0].y = srcY;
        position[0].x = srcX;
        ((MapPositionWords*)&position[1])->words[0] =
            ((MapPositionWords*)&position[0])->words[0];
        ((MapPositionWords*)&position[1])->words[1] =
            ((MapPositionWords*)&position[0])->words[1];
        position[2] = position[1];

        if (mapDirection(self, &pad, directions) == 1) {
            if (position[2].x <= ro[17])
                self->scrollTarget = 0;
            if (ro[17] < position[2].x &&
                position[2].x < ro[18])
                self->scrollTarget = 40;
            if (ro[18] <= position[2].x)
                self->scrollTarget = 80;
        }

        if (fn_31_FB8(self, &pad) == 1 &&
            self->scrollTarget < self->scrollLimit)
            ++self->scrollTarget;
        if (fn_31_F0C(self, &pad) == 1 && self->scrollTarget > 0)
            --self->scrollTarget;
        if (self->scrollTarget < self->scroll)
            --self->scroll;
        if (self->scroll < self->scrollTarget)
            ++self->scroll;
        if (self->scroll < 0)
            self->scroll = 0;
        if (self->scrollLimit < self->scroll)
            self->scroll = self->scrollLimit;

        ++self->mapCounter;
        if (mapConfirm(&pad) == 1 && self->mapCounter >= 60) {
            g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
            if (g_GameGlobal->entries[oldMap].state == 1) {
                if (oldMap == 4 || oldMap == 13 || oldMap == 17 ||
                    oldMap == 18 || oldMap == 26) {
                    self->state = 5;
                } else if ((unsigned int)(oldMap - 30) <= 3) {
                    self->state = 6;
                } else {
                    self->result = 10;
                    self->dialogState = 3;
                }

                if (self->result != 10) {
                    obj = self->transitionObject;
                    obj->changeAnimN(data + 0xB0);
                    obj->setFrameNode(ro[13]);
                    obj->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[16]);
                    obj->setFrameMatCol(ro[13]);
                    obj->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(ro[16]);
                }
            } else {
                obj = self->transitionObject;
                self->state = 2;
                obj->changeAnimN(data + 0xB0);
                obj->setFrameNode(ro[13]);
                obj->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[16]);
                obj->setFrameMatCol(ro[13]);
                obj->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(ro[16]);
            }
        }

        if (self->pending == 1 && !self->inputDisabled) {
            self->pending = 0;
            self->mapMode = 0;
            self->selectedOption = self->pendingOption;
        }

        if (mapCancel(&pad) == 1) {
            g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
            self->mapMode = 0;
            self->selectedOption = 3;
        }

        fn_31_2264(self, selectedMap);
        if (selectedMap != self->selectedMap) {
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            self->selectedMap = selectedMap;
        }
    } else {
        self->visibleObject->setFrameVisible(ro[13]);
        if (self->dialogOpen) {
            if (self->dialog->state == 3) {
                if (self->dialog->result) {
                    self->dialogState = 3;
                    self->dialogOpen = 0;
                } else {
                    self->result = 0;
                    self->dialogOpen = 0;
                }
                exit__6gfTaskFv(self->dialog);
                self->dialog = 0;
            }
        } else {
            if (directions & 8) {
                if ((unsigned int)(option - 2) <= 2)
                    option = 6;
            } else if (directions & 4) {
                if (option == 6)
                    option = 3;
            } else if (directions & 2) {
                if ((unsigned int)(option - 2) <= 1)
                    ++option;
                else if (option == 0)
                    option = 2;
                if (self->skipOption && option == 2)
                    option = 3;
            } else if (directions & 1) {
                if ((unsigned int)(option - 3) <= 1)
                    --option;
                else if (option == 2)
                    option = 0;
                if (self->skipOption && option == 2)
                    option = 0;
            }

            if (option != self->selectedOption) {
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                self->selectedOption = option;
            } else if (pad.m_buttonsPressedThisFrame.bits & 0x100) {
                g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
                if (option != self->selectedOption)
                    self->selectedOption = option;
                switch (self->selectedOption) {
                case 0:
                    self->state = 3;
                    break;
                case 2:
                    self->state = 7;
                    self->result = 7;
                    self->dialogState = 3;
                    break;
                case 3:
                    self->state = 8;
                    self->result = 8;
                    self->dialogState = 3;
                    break;
                case 4:
                    self->dialog = fn_800BEEB8(
                        1, self->dialogResource, 2, &self->dialogData,
                        self->dialogArgument, 0x40, 0, 0x2A, 0x2B, 1, 1,
                        (unsigned char)self->player);
                    self->result = 9;
                    self->dialogOpen = 1;
                    break;
                case 6:
                    self->mapMode = 1;
                    self->selectedOption = 5;
                    break;
                }
            } else if (pad.m_buttonsPressedThisFrame.bits & 0x200) {
                g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
                self->selectedOption = 4;
            }
        }
    }

    fn_31_2648(self, option);
}
