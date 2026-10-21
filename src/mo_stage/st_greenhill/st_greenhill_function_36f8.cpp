#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
struct Vec3f { float x, y, z; };
extern "C" void fn_27_26399C(void*);
extern "C" int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, Vec3f*);
struct Yakumono { void setTeam(int); };
struct Arg { u8 pad[0x30]; s8 team; };
struct Self {
    u8 pad0[0x14c];
    Yakumono* object;
    u8 pad150[0xc];
    u8* state;
    u8 pad160[4];
    Vec3f* positions;
    u8 index;
    u8 pad169[7];
    int team;
    u8 pad174[0x28];
    u8 generator[1];
};
extern "C" void fn_72_36F8(Self* self, void* unused, const Arg* arg) {
    fn_27_26399C(self->object);
    *self->state = 3;
    playSE__14snd3DGeneratorF5SndIDiii(self->generator, 0x1d16, 0, 0, -1);
    setPos__14snd3DGeneratorFP5Vec3f(self->generator, self->positions + self->index);
    u8 t = arg->team;
    self->team = (s8)t;
    if (self->object != 0) {
        self->object->setTeam((s8)arg->team);
    }
}
