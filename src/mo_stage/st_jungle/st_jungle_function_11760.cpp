#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Base {
    char pad[0x3C];
};

struct Parameters {
    char pad[0x10];
    float height;
};

#define SLOT(n) virtual void unused##n();

struct Object : Base {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48)
    virtual void getPos(Vec3f*, int, const char*);
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57)
    SLOT(58) SLOT(59) SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65)
    SLOT(66)
    virtual float getFrame(int);

    char pad40[0x124];
    Parameters* parameters;
    char pad168[0x38];
    char generator[8];
    int handle;
};

#undef SLOT

extern "C" {
extern char lbl_51_data_7BC0[];
extern float lbl_51_rodata_1C4;
extern float lbl_51_rodata_1C8;

void setPos__14snd3DGeneratorFP5Vec3f(void*, Vec3f*);
void stopSE__14snd3DGeneratorFll(void*, int, int);
int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);

void fn_51_11760(Object* self) {
    Vec3f pos;
    self->getPos(&pos, 0, lbl_51_data_7BC0);
    setPos__14snd3DGeneratorFP5Vec3f(self->generator, &pos);

    if (self->getFrame(0) >= lbl_51_rodata_1C4) {
        if (pos.y < self->parameters->height - lbl_51_rodata_1C8) {
            if (self->handle != -1) {
                stopSE__14snd3DGeneratorFll(
                    self->generator, self->handle, 0x78);
                self->handle = -1;
            }
        } else if (self->handle == -1) {
            self->handle = playSE__14snd3DGeneratorF5SndIDiii(
                self->generator, 0x1B8F, 0, 0x78, -1);
        }
    } else {
        self->handle = -1;
    }
}
}
