#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_4448;
extern const float lbl_27_rodata_444C;
void* fn_8018F340(void*, unsigned long);
unsigned long fn_8018F394(void*);
void* fn_801AFFDC(void*, bool);
void fn_80191B9C(void*, unsigned long, GXColor*);
void fn_80191AA4(void*, unsigned long, GXColor);
void DCStore__Q34nw4r3g3d6ResMatFb(void*, bool);
}
struct AccessWrapper {
    nw4r::g3d::ScnMdl::CopiedMatAccess access;
    int padding;
    AccessWrapper(nw4r::g3d::ScnMdl* model, unsigned long id) : access(model, id) {}
};
struct MaterialData { char pad[12]; unsigned long id; };
struct Object {
    char pad0[16];
    nw4r::g3d::ScnMdl* model;
    char pad14[12];
    float f20;
    int mode;
};
extern "C" void fn_27_270D18(Object* self) {
    unsigned long i = 0;
    nw4r::g3d::ResMdl resource = self->model->m_resMdl;
    for (; i < fn_8018F394(&resource); ++i) {
        MaterialData* data = (MaterialData*)fn_8018F340(&resource, i);
        void* mat = data;
        if (data) {
            AccessWrapper access(self->model, data->id);
            void* channels = fn_801AFFDC(&access.access, false);
            if (channels) {
                GXColor color;
                fn_80191B9C(&channels, 2, &color);
                if (self->mode == 0) {
                    float f = self->f20;
                    color.a = (f < lbl_27_rodata_4448) ? 0 : (unsigned char)f;
                }
                if (self->mode == 1) {
                    float f = self->f20;
                    color.a = (f > lbl_27_rodata_444C) ? 255 : (unsigned char)f;
                }
                fn_80191AA4(&channels, 2, color);
            }
            DCStore__Q34nw4r3g3d6ResMatFb(&mat, false);
        }
    }
}
