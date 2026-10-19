#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct snd3DGenerator {
    int dummy;
};

extern "C" int playSE__14snd3DGeneratorF5SndIDiii(snd3DGenerator*, int, int, int, int);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);

struct fn63Obj {
    char pad0[0x174];
    Vec3f* pos;
    char pad1[0x17d - 0x178];
    unsigned char idx;
    char pad2[0x188 - 0x17e];
    snd3DGenerator se;
};

extern "C" void fn_63_10914(fn63Obj* self) {
    playSE__14snd3DGeneratorF5SndIDiii(&self->se, 0x1c93, 0, 0, -1);
    setPos__14snd3DGeneratorFP5Vec3f(&self->se, (Vec3f*)((char*)self->pos + self->idx * 12));
}
