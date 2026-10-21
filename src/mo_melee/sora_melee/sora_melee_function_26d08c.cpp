#pragma force_active on

extern "C" void stopSE__14snd3DGeneratorFll(void*, int, int);
extern const float lbl_27_rodata_4388;

struct Vec2f {
    float x, y;

    Vec2f(float a, float b) : x(a), y(b) {}
};

struct SEInfo {
    short state;
    short pad2;
    float frames;
    int handle;
    char padC[0xE];
    unsigned short generator;
    Vec2f offset;
    float scale;
};

struct Gimmick {
    char pad[0xA0];
    char* generators;
    char padA4[4];
    SEInfo* sounds;
};

extern "C" void stopGimmickSE__9grGimmickFUl(
    Gimmick* self, unsigned long index)
{
    if (self->sounds[index].handle >= 0) {
        stopSE__14snd3DGeneratorFll(
            self->generators + (self->sounds[index].generator * 8),
            self->sounds[index].handle,
            0);

        SEInfo& sound = self->sounds[index];
        sound.state = 0;
        sound.frames = lbl_27_rodata_4388;
        sound.handle = -1;
        sound.generator = 0;
        sound.offset = Vec2f(lbl_27_rodata_4388, lbl_27_rodata_4388);
    }
}
