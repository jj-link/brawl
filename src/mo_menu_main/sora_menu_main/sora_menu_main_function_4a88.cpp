#include <gf/gf_pad_system.h>
#include <mu/mu_object.h>
#include <ty/ty_fig_listmng.h>
#include <snd/snd_system.h>
#pragma force_active on

struct FigListMenu {
    char pad0[0x40];
    int state;
    int result;
    char pad48[4];
    tyFigListDataManager* mgr;
    u32 list[12];
    char pad80[0x128-0x80];
    int selection;
    u32 category;
    int group;
    int pages;
    u32 page;
    u32 count;
    u32 cursor;
    char pad144[4];
    MuObject* object;
    MuObject* controller;
    char pad150[0x20c-0x150];
    u16 owned[1];
};
extern const float lbl_2_rodata_F8[];
extern char lbl_2_data_8C0[];
extern "C" {
float getFrame__16gfModelAnimationFd(gfModelAnimation*);
u32 fn_2_507C(FigListMenu*);
void fn_2_5178(FigListMenu*);
int fn_2_5704(FigListMenu*, int, int);
int fn_2_5838(FigListMenu*, int, int);
int fn_2_5B90(FigListMenu*, int, int);
int fn_2_5E50(FigListMenu*, int, int);
int fn_80052DB0();
void fn_800B3C5C(MuObject*, void*, int);
}

extern "C" void fn_2_4A88(FigListMenu* self) {
    const float* ro = lbl_2_rodata_F8;
    int changed = 0;
    switch (self->state) {
    case 0:
        if (ro[9] == getFrame__16gfModelAnimationFd(self->object->m_modelAnim))
            self->state = 1;
        break;
    case 1: {
        u32 flags = fn_2_507C(self);
        switch (self->selection) {
        case 0:
            if (self->category == 0 && (flags & 0x22)) {
                self->category = 1;
                self->cursor = 0;
                self->page = 0;
                self->group = 0;
                for (int i = 0x17; i < 0x21; i++) {
                    self->pages = self->mgr->getPageNumKind(i);
                    if (self->pages != 0) {
                        self->group = i - 0x17;
                        break;
                    }
                }
                changed = 1;
                g_sndSystem->playSE((SndID)0x23, -1, 0, 0, -1);
            } else if (self->category == 1 && (flags & 0x41)) {
                self->category = 0;
                self->cursor = 0;
                self->page = 0;
                self->group = 0;
                for (int i = 0; i < 0x16; i++) {
                    self->pages = self->mgr->getPageNumSeries(i);
                    if (self->pages != 0) {
                        self->group = i;
                        break;
                    }
                }
                changed = 1;
                g_sndSystem->playSE((SndID)0x23, -1, 0, 0, -1);
            } else if (flags & 4) {
                changed = 1;
                self->selection++;
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            }
            break;
        case 1:
            if (flags & 0x41) {
                changed = fn_2_5E50(self, 1, 1);
                if (changed) g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            } else if (flags & 0x22) {
                changed = fn_2_5E50(self, 0, 1);
                if (changed) g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            } else if (flags & 4) {
                changed = 1;
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                self->selection++;
            } else if (flags & 8) {
                changed = 1;
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                self->selection--;
            }
            break;
        case 2:
            if (flags & 1) changed = fn_2_5704(self, 2, 1);
            else if (flags & 2) changed = fn_2_5704(self, 3, 1);
            else if (flags & 4) changed = fn_2_5704(self, 1, 1);
            else if (flags & 8) {
                changed = fn_2_5704(self, 0, 1);
                if (!changed) {
                    changed = 1;
                    self->selection--;
                    g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                }
            } else if (flags & 0x40) changed = fn_2_5B90(self, 1, 1);
            else if (flags & 0x20) changed = fn_2_5838(self, 1, 1);
            break;
        }
        if (changed) {
            if (self->category == 0)
                self->count = self->mgr->getFigListSeries(self->group, self->page, self->list);
            else
                self->count = self->mgr->getFigListKind(self->group + 0x17, self->page, self->list);
            fn_2_5178(self);
        } else if ((flags & 0x100) && (u32)self->selection == 2) {
            if (self->owned[self->list[self->cursor]]) {
                fn_800B3C5C(self->object, lbl_2_data_8C0 + 0x14, 0);
                self->state = 2;
                self->result = 1;
                g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
            } else {
                g_sndSystem->playSE((SndID)3, -1, 0, 0, -1);
            }
        } else if (flags & 0x200) {
            fn_800B3C5C(self->object, lbl_2_data_8C0 + 0x14, 0);
            self->state = 2;
            self->result = 2;
            g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
        }
        gfPadStatus status;
        g_gfPadSystem->getSysPadStatus(fn_80052DB0(), &status);
        if (status.m_error == 0) {
            float frame;
            switch (status.m_controllerType) {
            case 0: frame = ro[4]; break;
            case 1: frame = ro[6]; break;
            case 2: frame = ro[5]; break;
            case 3: frame = ro[10]; break;
            default: frame = ro[11]; break;
            }
            self->controller->setFrameVisible(frame);
        }
        break;
    }
    case 2:
        if (ro[12] == getFrame__16gfModelAnimationFd(self->object->m_modelAnim)) {
            self->state = 3;
            self->result = 3;
        }
        break;
    }
}