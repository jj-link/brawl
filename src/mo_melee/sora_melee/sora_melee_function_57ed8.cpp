#pragma force_active on
struct Vec3f {
    float x, y, z;
};

struct snd3DGenerator;

struct SoundHandle {
    int id;
    snd3DGenerator* generator;
};

extern "C" {
extern unsigned char lbl_27_bss_D0[0x18];

int fn_27_57DC8(void*);
snd3DGenerator* fn_27_57E34(void*, int);
void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);

void fn_27_57ED8(SoundHandle* self, const Vec3f* position) {
    if (self->id == -1) {
        int id = fn_27_57DC8(lbl_27_bss_D0);
        if (id != -1) {
            self->generator = fn_27_57E34(lbl_27_bss_D0, id);
            self->id = id;
            Vec3f copy = *position;
            setPos__14snd3DGeneratorFP5Vec3f(self->generator, &copy);
        }
    }
}
}
