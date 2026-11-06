#include <mu/mu_object.h>
#pragma force_active on

struct MenuObjects {
    char pad[0x1bc];
    MuObject* m1bc;
    MuObject* m1c0;
};

struct Menu {
    char pad[0x64c];
    MenuObjects* objects;
    char pad650[0x20];
    int state;
};

extern "C" {
extern const float lbl_2_rodata_6D0[];
extern unsigned char lbl_2_data_2728[];
extern unsigned char lbl_2_data_2700[];
void fn_800B798C(MuObject*, float);
void fn_800B330C(MuObject*, void*, int);
}

extern "C" void fn_2_1C8AC(Menu* self, int state) {
    const float* ro = lbl_2_rodata_6D0;
    if (state != self->state) {
        switch (state) {
        case 0:
            *(int*)((char*)self->objects->m1c0 + 0x1c) = 0;
            self->objects->m1c0->setFrameNode(ro[11]);
            self->objects->m1c0->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[1]);
            *(int*)((char*)self->objects->m1bc + 0x1c) = 0;
            self->objects->m1bc->setFrameNode(ro[12]);
            self->objects->m1bc->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[1]);
            fn_800B798C(self->objects->m1bc, ro[12]);
            self->objects->m1bc->m_modelAnim->m_anmObjTexSrtRes->SetUpdateRate(ro[1]);
            break;
        case 1:
            fn_800B330C(self->objects->m1c0, lbl_2_data_2728, 0);
            fn_800B330C(self->objects->m1bc, lbl_2_data_2700, 0);
            break;
        case 2:
            *(int*)((char*)self->objects->m1c0 + 0x1c) = 0;
            self->objects->m1c0->setFrameNode(ro[10]);
            self->objects->m1c0->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[1]);
            *(int*)((char*)self->objects->m1bc + 0x1c) = 0;
            self->objects->m1bc->setFrameNode(ro[11]);
            self->objects->m1bc->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[1]);
            fn_800B798C(self->objects->m1bc, ro[11]);
            self->objects->m1bc->m_modelAnim->m_anmObjTexSrtRes->SetUpdateRate(ro[1]);
            break;
        case 3:
            fn_800B330C(self->objects->m1c0, lbl_2_data_2728 + 0x14, 0);
            fn_800B330C(self->objects->m1bc, lbl_2_data_2700 + 0x14, 0);
            break;
        }
        self->state = state;
    }
}
