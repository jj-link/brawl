#include <mu/mu_object.h>
#pragma force_active on
struct MenuObjects {
    char pad[0x1bc];
    MuObject* m1bc;
    MuObject* m1c0;
};
struct Menu {
    char pad[0x634];
    int s634;
    char pad638[0x14];
    MenuObjects* objects;
    char pad650[0x14];
    int s664;
    char pad668[8];
    int s670;
    int s674;
};
extern "C" {
extern const float lbl_2_rodata_6D0[];
unsigned fn_18_12E0(Menu*);
int fn_2_1CBF0(Menu*, unsigned);
void fn_2_1C8AC(Menu*, int);
}
extern "C" int fn_2_1CE70(Menu* self) {
    const float* c = lbl_2_rodata_6D0;
    int r = 0;
    switch (self->s664) {
    case 0: {
        if (self->s670 != 1) self->s664 = 2;
        unsigned flags = fn_18_12E0(self);
        if (fn_2_1CBF0(self, flags) != 0) {
            fn_2_1C8AC(self, 2);
            r = 4;
            self->s664 = 2;
        }
        if (flags & 0x20) {
            fn_2_1C8AC(self, 3);
            self->s664 = 3;
            r = 1;
            self->s634 = 0x10;
        }
        break;
    }
    case 1:
        if (self->s670 != 1) self->s664 = 2;
        break;
    case 2: {
        unsigned flags = fn_18_12E0(self);
        fn_2_1CBF0(self, flags);
        if (flags & 0x20) {
            fn_2_1C8AC(self, 3);
            self->s634 = 0x10;
            r = 1;
            self->s664 = 3;
        }
        break;
    }
    case 3:
        if (self->s670 == 0) r = 3;
        break;
    }
    switch (self->s670) {
    case 0:
    case 2:
        break;
    case 1:
        if (self->objects->m1c0->m_modelAnim->m_anmObjChrRes->GetFrame() >= c[10]) {
            if (self->objects->m1bc->m_modelAnim->m_anmObjChrRes->GetFrame() >= c[11]) {
                fn_2_1C8AC(self, 2);
            }
        }
        break;
    case 3:
        if (self->objects->m1c0->m_modelAnim->m_anmObjChrRes->GetFrame() >= c[11]) {
            if (self->objects->m1bc->m_modelAnim->m_anmObjChrRes->GetFrame() >= c[12]) {
                fn_2_1C8AC(self, 0);
            }
        }
        break;
    }
    switch (self->s674) {
    case 0:
        break;
    case 1:
        if (self->objects->m1c0->m_modelAnim->m_anmObjMatClrRes->GetFrame() >= c[13]) {
            if (self->s674 != 0) {
                self->objects->m1c0->setFrameMatCol(c[1]);
                self->objects->m1c0->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(c[1]);
                self->s674 = 0;
            }
        }
        break;
    case 2:
        if (self->objects->m1c0->m_modelAnim->m_anmObjMatClrRes->GetFrame() >= c[14]) {
            if (self->s674 != 0) {
                self->objects->m1c0->setFrameMatCol(c[1]);
                self->objects->m1c0->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(c[1]);
                self->s674 = 0;
            }
        }
        break;
    }
    return r;
}