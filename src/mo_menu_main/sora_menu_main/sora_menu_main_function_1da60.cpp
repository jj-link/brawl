#include <mu/mu_object.h>
#pragma force_active on

struct MenuObjects {
    char pad[0x1bc];
    MuObject* m1bc;
    char pad2[0x1d4 - 0x1c0];
    MuObject* m1d4;
};

struct Menu {
    char pad[0x64c];
    MenuObjects* objects;
    char pad650[0x20];
    int state;
};

extern "C" {
extern const float lbl_2_rodata_710[];
extern unsigned char lbl_2_data_27D0[];
extern unsigned char lbl_2_data_27F8[];
void fn_800B798C(MuObject*, float);
void fn_800B330C(MuObject*, void*, int);
}

extern "C" void fn_2_1DA60(Menu* self, int state) {
    const float* ro = lbl_2_rodata_710;
    if (state != self->state) {
        switch (state) {
        case 0:
            *(int*)((char*)self->objects->m1d4 + 0x1c) = 0;
            self->objects->m1d4->setFrameNode(ro[0x1f8 / 4]);
            self->objects->m1d4->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[0x1d8 / 4]);
            *(int*)((char*)self->objects->m1bc + 0x1c) = 0;
            self->objects->m1bc->setFrameNode(ro[0x1fc / 4]);
            self->objects->m1bc->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[0x1d8 / 4]);
            fn_800B798C(self->objects->m1bc, ro[0x1fc / 4]);
            self->objects->m1bc->m_modelAnim->m_anmObjTexSrtRes->SetUpdateRate(ro[0x1d8 / 4]);
            break;
        case 1:
            fn_800B330C(self->objects->m1d4, lbl_2_data_27F8, 0);
            fn_800B330C(self->objects->m1bc, lbl_2_data_27D0, 0);
            break;
        case 2:
            *(int*)((char*)self->objects->m1d4 + 0x1c) = 0;
            self->objects->m1d4->setFrameNode(ro[0x1ec / 4]);
            self->objects->m1d4->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[0x1d8 / 4]);
            *(int*)((char*)self->objects->m1bc + 0x1c) = 0;
            self->objects->m1bc->setFrameNode(ro[0x1f8 / 4]);
            self->objects->m1bc->m_modelAnim->m_anmObjChrRes->SetUpdateRate(ro[0x1d8 / 4]);
            fn_800B798C(self->objects->m1bc, ro[0x1f8 / 4]);
            self->objects->m1bc->m_modelAnim->m_anmObjTexSrtRes->SetUpdateRate(ro[0x1d8 / 4]);
            break;
        case 3:
            fn_800B330C(self->objects->m1d4, lbl_2_data_27F8 + 0x14, 0);
            fn_800B330C(self->objects->m1bc, lbl_2_data_27D0 + 0x14, 0);
            break;
        }
        self->state = state;
    }
}
