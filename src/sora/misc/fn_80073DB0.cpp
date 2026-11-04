#include <types.h>
#pragma force_active on

class Class_80466A60 {
public:
    virtual void fn_801C49AC();
    virtual void fn_801C46C4();
    virtual void fn_801BCBFC();
    virtual void fn_801BC66C();
    virtual void fn_801BC684(int);
    virtual void fn_801BC854();
    virtual void fn_801BCAD8();
    virtual void fn_801BCAF0(unsigned long);
    virtual void fn_801C45E8();
    virtual void fn_801C49A4();
    virtual void fn_801BCBF4();
    virtual void fn_801BD33C();
    virtual void fn_801BD368(float, int);
};

extern "C" int fn_801BD2C8(Class_80466A60*);
extern "C" int fn_801CBFB0(void*, void*, int, int, int, int);

struct sndSystem {
    char pad0[0x198];
    char player[0x548];
    Class_80466A60* sound;
    int bgmId;
    char pad6E8[4];
    unsigned char available;
    char pad6ED[2];
    unsigned char enabled;
    char pad6F0[0x10];
    float volume700;
    float volume704;
    float volume708;
    char pad70C[8];
    float volume714;
};

inline int remaining(Class_80466A60* sound) {
    return sound ? fn_801BD2C8(sound) : 0;
}
inline void stop(Class_80466A60* sound) {
    if (sound) sound->fn_801BC684(0);
}
inline void fade(Class_80466A60* sound, unsigned long frames) {
    if (sound) sound->fn_801BCAF0(frames);
}
inline void volume(Class_80466A60* sound, float value) {
    if (sound) sound->fn_801BD368(value, 0);
}

extern "C" int playBGM__9sndSystemFiUlb(sndSystem* self, int id, unsigned long frames, bool force) {
    if (!self->enabled) return 0;
    if (id == self->bgmId) return 1;
    if (self->sound && remaining(self->sound)) {
        stop(self->sound);
        self->bgmId = -1;
    }
    if (self->bgmId != -1 && force && self->enabled && self->available) {
        stop(self->sound);
        self->bgmId = -1;
    }
    self->bgmId = -1;
    if ((unsigned int)id == 0xFFFFFFFF) return 0;
    if (!self->available) return 0;
    if (fn_801CBFB0(self->player, &self->sound, id, 0, 0, 0) == 0) {
        fade(self->sound, frames);
        volume(self->sound, self->volume704 * (self->volume714 * (self->volume700 * self->volume708)));
        self->bgmId = id;
        return 1;
    }
    return 0;
}
