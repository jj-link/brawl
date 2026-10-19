#pragma force_active on
struct Vec3f {
    float x, y, z;
};

struct snd3DGenerator;

struct SoundHandle {
    unsigned int unknown;
    int index;
    snd3DGenerator* generator;
};

extern "C" {
extern unsigned char lbl_27_bss_D0[0x18];

int fn_27_57DC8(void*);
snd3DGenerator* fn_27_57E34(void*, int);
void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);

void fn_27_57FE8(SoundHandle* self, const Vec3f* position) {
    if (self->index == -1) {
        int index = fn_27_57DC8(lbl_27_bss_D0);
        if (index != -1) {
            self->generator = fn_27_57E34(lbl_27_bss_D0, index);
            self->index = index;
            Vec3f local = *position;
            setPos__14snd3DGeneratorFP5Vec3f(self->generator, &local);
        }
    }
}
}
