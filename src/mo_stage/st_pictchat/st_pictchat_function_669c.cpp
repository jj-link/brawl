#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct snd3DGenerator {
    char _pad[8];
};

struct PictchatObject {
    char _pad[0x294];
    snd3DGenerator se;
    int handle;
};

extern "C" const float lbl_73_rodata_78;

extern "C" int playSE__14snd3DGeneratorF5SndIDiii(
    snd3DGenerator*, int, int, int, int);

extern "C" void setPos__14snd3DGeneratorFP5Vec3f(
    snd3DGenerator*, Vec3f*);

extern "C" void fn_73_669C(PictchatObject* self) {
    self->handle = playSE__14snd3DGeneratorF5SndIDiii(
        &self->se, 0x1d22, 0, 0, -1);

    Vec3f position;
    position.x = lbl_73_rodata_78;
    position.y = lbl_73_rodata_78;
    position.z = lbl_73_rodata_78;

    setPos__14snd3DGeneratorFP5Vec3f(&self->se, &position);
}
