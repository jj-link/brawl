#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct snd3DGenerator {
    char _pad[8];
};

struct PictChatObj {
    char _pad[0x294];
    Vec3f* _pos;
    char _pad2[0x10];
    snd3DGenerator _se;
    int _handle;
};

extern "C" int playSE__14snd3DGeneratorF5SndIDiii(snd3DGenerator*, int, int, int, int);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);

extern "C" void fn_73_7164(PictChatObj* self) {
    playSE__14snd3DGeneratorF5SndIDiii(&self->_se, 0x1d24, 0, 0, -1);
    self->_handle = playSE__14snd3DGeneratorF5SndIDiii(&self->_se, 0x1d25, 0, 0, -1);
    setPos__14snd3DGeneratorFP5Vec3f(&self->_se, self->_pos);
}
