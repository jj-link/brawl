#include <mu/mu_object.h>
#pragma force_active on

struct MenuObjects {
    char pad[0x1bc];
    MuObject* object;
};

struct Menu {
    char pad[0x64c];
    MenuObjects* objects;
    char pad650[0x24];
    int state;
};

extern "C" {
extern const float lbl_2_rodata_B40[];
extern unsigned char lbl_2_data_2ED0[];
void fn_800B798C(MuObject*, float);
void fn_800B330C(MuObject*, void*, int);
}

extern "C" void fn_2_26A38(Menu* self, int state) {
    const float* ro = lbl_2_rodata_B40;
    if (state != self->state) {
        switch (state) {
        case 0:
            *(int*)((char*)self->objects->object + 0x1c) = 0;
            self->objects->object->setFrameNode(ro[0x2a0 / 4]);
            self->objects->object->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[0x260 / 4]);
            fn_800B798C(self->objects->object, ro[0x2a0 / 4]);
            self->objects->object->m_modelAnim->m_anmObjTexSrtRes->SetUpdateRate(ro[0x260 / 4]);
            break;
        case 1:
            fn_800B330C(self->objects->object, lbl_2_data_2ED0, 0);
            break;
        case 2:
            *(int*)((char*)self->objects->object + 0x1c) = 0;
            self->objects->object->setFrameNode(ro[0x29c / 4]);
            self->objects->object->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[0x260 / 4]);
            fn_800B798C(self->objects->object, ro[0x29c / 4]);
            self->objects->object->m_modelAnim->m_anmObjTexSrtRes->SetUpdateRate(ro[0x260 / 4]);
            break;
        case 3:
            fn_800B330C(self->objects->object, lbl_2_data_2ED0 + 0x14, 0);
            break;
        }
        self->state = state;
    }
}
