#pragma force_active on
#include <mt/mt_matrix.h>
#include <snd/snd_3d_generator.h>
#include <new>

struct Flags { u32 pad; u32 flags; };
class Class_2110 {
public:
    virtual void fn_57_C674();
    virtual void fn_57_BA94();
    virtual void fn_57_BAA4();
    virtual void fn_57_ADD8();
    virtual void fn_57_AB4C(int, int);
    Flags* data;
    u32 state;
};
struct Obj {
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    Class_2110 anim;
    char padDC[0x84];
    u32 a160;
    Matrix m164;
    Matrix m194;
    float a1c4, a1c8, a1cc;
    u32 a1d0;
    unsigned char a1d4;
    float a1d8;
    unsigned char a1dc, a1dd;
    u32 a1e0;
    char a1e4[8];
    unsigned int a1ec:3;
    unsigned int rest:29;
    char pad1f0[0x78];
    char generator[8];
    int a270, a274;
};
extern "C" void __ct__14snd3DGeneratorFv(snd3DGenerator*);
extern "C" void fn_57_3980(void*, const char*);
extern "C" void fn_8009ED40(void*, int, int);
extern "C" void fn_8009F1FC(void*);
extern "C" char lbl_57_data_2C70[];
extern "C" const float lbl_57_rodata_300;

extern "C" Obj* fn_57_ECD8(Obj* p, const char* name) {
    fn_57_3980(p, name);
    p->vtable = lbl_57_data_2C70;
    fn_8009ED40(p->a1e4, 0, 1);
    __ct__14snd3DGeneratorFv((snd3DGenerator*)p->generator);
    p->a160 = 0;
    p->m164.setIdentity();
    p->m194.setIdentity();
    Class_2110* a = &p->anim;
    p->a1d0 = 0;
    p->a1c4 = lbl_57_rodata_300;
    p->a1c8 = lbl_57_rodata_300;
    p->a1cc = lbl_57_rodata_300;
    p->a1d4 = 1;
    p->a1d8 = lbl_57_rodata_300;
    p->a1dc = 0;
    p->a1dd = 0;
    p->a1e0 = 0;
    if (!a) return p;
    a->state = 1;
    a->fn_57_AB4C(0, 15);
    a->data->flags |= 1;
    fn_8009F1FC(p->a1e4);
    p->a1ec = 1;
    p->a270 = -1;
    p->a274 = -1;
    return p;
}