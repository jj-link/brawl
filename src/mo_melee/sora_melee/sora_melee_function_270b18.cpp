#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_4448;
extern const float lbl_27_rodata_444C;
extern int lbl_27_data_57C28;
void* fn_8018F340(void*, unsigned long);
unsigned long fn_8018F394(void*);
void* fn_801AFFDC(void*, bool);
void fn_80191AA4(void*, unsigned long, GXColor);
}
struct AccessWrapper {
    nw4r::g3d::ScnMdl::CopiedMatAccess access;
    int padding;
    AccessWrapper(nw4r::g3d::ScnMdl* model, unsigned long id) : access(model, id) {}
};
struct MaterialData { char pad[12]; unsigned long id; };
struct Object {
    char pad0[4];
    int state;
    char pad8[8];
    nw4r::g3d::ScnMdl* model;
    char pad14[4];
    float f18;
    char pad1c[4];
    float f20;
    int mode;
};
extern "C" void fn_27_270B18(Object* self) {
    unsigned long i = 0;
    nw4r::g3d::ResMdl resource = self->model->m_resMdl;
    for (; i < fn_8018F394(&resource); ++i) {
        MaterialData* data = (MaterialData*)fn_8018F340(&resource, i);
        nw4r::g3d::ResMat mat(data);
        if (data) {
            AccessWrapper access(self->model, data->id);
            void* channels = fn_801AFFDC(&access.access, false);
            if (channels) {
                GXColor color;
                if (self->mode == 0) {
                    self->f20 = lbl_27_rodata_444C;
                    color.a = (unsigned char)lbl_27_rodata_444C;
                }
                if (self->mode == 1) {
                    self->f20 = lbl_27_rodata_4448;
                    color.a = (unsigned char)lbl_27_rodata_4448;
                }
                fn_80191AA4(&channels, 2, color);
            }
            mat.DCStore(false);
        }
    }
    self->f18 = lbl_27_rodata_4448;
    self->state = lbl_27_data_57C28;
}