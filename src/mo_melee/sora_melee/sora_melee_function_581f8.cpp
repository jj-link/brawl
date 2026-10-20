#pragma force_active on
struct Vec3f {
    float x, y, z;
};

struct snd3DGenerator;

struct SoundHandle {
    int id;
    snd3DGenerator* generator;
};

struct SoundArray {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual SoundHandle* at(int);
};

extern "C" void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);

extern "C" void fn_27_581F8(SoundArray* self, const Vec3f* position, int index) {
    SoundHandle* handle = self->at(index);
    if (handle->generator) {
        Vec3f copy = *position;
        setPos__14snd3DGeneratorFP5Vec3f(handle->generator, &copy);
    }
}
