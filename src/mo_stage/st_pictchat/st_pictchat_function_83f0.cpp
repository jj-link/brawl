#include <st/module.h>
#pragma force_active on

typedef struct Vec3f { float x, y, z; } Vec3f;
typedef struct snd3DGenerator { char pad[8]; } snd3DGenerator;

extern "C" {
int playSE__14snd3DGeneratorF5SndIDiii(snd3DGenerator*, int, int, int, int);
void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);
extern const float lbl_73_rodata_78;
}

struct Obj {
    char pad[0x294];
    snd3DGenerator gen;
    int handle;
};

extern "C" void fn_73_83F0(Obj* self) {
    self->handle = playSE__14snd3DGeneratorF5SndIDiii(&self->gen, 0x1d2a, 0, 0, -1);
    Vec3f pos;
    pos.x = lbl_73_rodata_78;
    pos.y = lbl_73_rodata_78;
    pos.z = lbl_73_rodata_78;
    setPos__14snd3DGeneratorFP5Vec3f(&self->gen, &pos);
}
