#include <so/so_value_accesser.h>
#pragma force_active on
struct SoraEntry {
    u8 type, kind;
    u16 flags;
    int a, b, c;
    float x, y, z, w;
};
struct SoraInput {
    int a;
    u8 type;
    char pad[3];
    int c;
    float x, y, z, zscale, w, wscale;
};
struct SoraOwner {
    char pad[0x4c];
    soModuleAccesser* module;
};
extern "C" SoraEntry* fn_41_23270(SoraOwner*, unsigned int);
extern "C" void fn_41_232A4(SoraOwner*, int, SoraEntry*);
extern float lbl_41_rodata_D58;
extern "C" void fn_41_23328(SoraOwner* self, unsigned int index, SoraInput* input) {
    SoraEntry* p = fn_41_23270(self, index);
    if (p) {
        int a = input->a;
        p->type = input->type;
        fn_41_232A4(self, a, p);
        if (input->c >= 0) {
            p->c = input->c;
            p->flags |= 0x201;
        } else {
            p->c = 0;
        }
        p->x = input->x;
        p->y = input->y;
        p->z = input->z;
        p->w = input->w;
        float v = soValueAccesser::getValueFloat(self->module, 0x1100000c, 0);
        if (lbl_41_rodata_D58 != input->zscale)
            p->z += input->zscale * v;
        if (lbl_41_rodata_D58 != input->wscale)
            p->w += input->wscale * v;
        if (p->kind == 12)
            p->kind = 26;
    }
}