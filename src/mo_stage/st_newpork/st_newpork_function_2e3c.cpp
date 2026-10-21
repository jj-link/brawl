#pragma force_active on
extern "C" void createSoundWork__9grGimmickFUlUl(void*, unsigned long, unsigned long);
extern "C" const float lbl_69_rodata_8C;

struct IntPair {
    unsigned long a, b;
};

struct Vec2 {
    float x, y;

    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
    Vec2(const Vec2& v) {
        *(IntPair*)this = *(const IntPair*)&v;
    }
};

struct Sound {
    unsigned long id, a, b;
    unsigned short c;
    unsigned short pad;
    Vec2 pos;
    char rest[16];
};

struct Work {
    char pad[12];
    Sound sound;
};

struct Object {
    char pad[0xA8];
    Work* work;
};

extern "C" void fn_69_2E3C(Object* o) {
    createSoundWork__9grGimmickFUlUl(o, 1, 1);
    Vec2 l, v;
    v.x = lbl_69_rodata_8C;
    v.y = lbl_69_rodata_8C;
    *(IntPair*)&l = *(IntPair*)&v;
    o->work->sound.id = 0x1CF4;
    o->work->sound.a = 0;
    o->work->sound.c = 0;
    o->work->sound.b = 0;
    o->work->sound.pos = l;
}
