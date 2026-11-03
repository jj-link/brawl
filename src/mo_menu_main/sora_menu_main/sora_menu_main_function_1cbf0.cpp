#include <mu/mu_object.h>
#include <snd/snd_system.h>
#pragma force_active on

struct Objects {
    char pad[0x1c0];
    MuObject* arrow;
    MuObject* items[4];
};
struct Menu {
    char pad[0x64c];
    Objects* objects;
    char pad2[0x24];
    int direction;
    char pad3[4];
    int count;
    int selected;
    int offset;
};
extern "C" {
extern const float lbl_2_rodata_6D0[];
void fn_2_1C6F0(Menu*, int);
}
extern "C" int fn_2_1CBF0(Menu* self, int flags) {
    const float* c = lbl_2_rodata_6D0;
    int result = 0;
    int changed = 0;
    int i;
    if (flags & 1) {
        if (self->selected > 0) {
            int selected = self->selected - 1;
            i = 0;
            self->selected = selected;
            int offset = 0;
            do {
                ((MuObject**)((char*)self->objects + offset + 0x1c4))[0]->setFrameMatCol(i == selected ? c[2] : c[1]);
                ((MuObject**)((char*)self->objects + offset + 0x1c4))[0]->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(c[1]);
                i++;
                offset += 4;
            } while (i < 4);
            changed = 1;
        } else if (self->offset > 0) {
            self->offset--;
            fn_2_1C6F0(self, self->offset);
            changed = 1;
        }
    }
    if (changed) {
        if (self->direction != 1) {
            self->objects->arrow->setFrameMatCol(c[2]);
            self->objects->arrow->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(c[2]);
            self->direction = 1;
        }
        result = 1;
    }
    int changed2 = 0;
    if (flags & 2) {
        if (self->offset + self->selected < self->count - 1) {
            if (self->selected < 3) {
                flags = self->selected + 1;
                self->selected = flags;
                for (i = 0; i < 4; i++) {
                    self->objects->items[i]->setFrameMatCol(i == flags ? c[2] : c[1]);
                    self->objects->items[i]->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(c[1]);
                }
                changed2 = 1;
            } else if (self->offset < self->count - 4) {
                self->offset++;
                fn_2_1C6F0(self, self->offset);
                changed2 = 1;
            }
        }
    }
    if (changed2) {
        if (self->direction != 2) {
            self->objects->arrow->setFrameMatCol(c[15]);
            self->objects->arrow->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(c[2]);
            self->direction = 2;
        }
        result = 1;
    }
    if (result) g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
    return result;
}