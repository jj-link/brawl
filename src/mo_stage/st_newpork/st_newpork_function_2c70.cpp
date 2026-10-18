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
    Sound sound[4];
};

struct Object {
    char pad[0xA8];
    Work* work;

    void set(int i, unsigned long id, const Vec2& v) {
        Vec2 local(v);
        work->sound[i].id = id;
        work->sound[i].a = 0;
        work->sound[i].c = 0;
        work->sound[i].b = 0;
        work->sound[i].pos = local;
    }
};

extern "C" void fn_69_2C70(Object* o) {
    createSoundWork__9grGimmickFUlUl(o, 4, 1);
    Vec2 l0, v0, v1, v2, v3, l3, l2, l1;

    v0.x = lbl_69_rodata_8C;
    v0.y = lbl_69_rodata_8C;
    *(IntPair*)&l0 = *(IntPair*)&v0;
    o->work->sound[0].id = 0x1CF0;
    o->work->sound[0].a = 0;
    o->work->sound[0].c = 0;
    o->work->sound[0].b = 0;
    o->work->sound[0].pos = l0;

    v1.x = lbl_69_rodata_8C;
    v1.y = lbl_69_rodata_8C;
    *(IntPair*)&l1 = *(IntPair*)&v1;
    o->work->sound[1].id = 0x1CF1;
    o->work->sound[1].a = 0;
    o->work->sound[1].c = 0;
    o->work->sound[1].b = 0;
    o->work->sound[1].pos = l1;

    v2.x = lbl_69_rodata_8C;
    v2.y = lbl_69_rodata_8C;
    *(IntPair*)&l2 = *(IntPair*)&v2;
    o->work->sound[2].id = 0x1CF2;
    o->work->sound[2].a = 0;
    o->work->sound[2].c = 0;
    o->work->sound[2].b = 0;
    o->work->sound[2].pos = l2;

    v3.x = lbl_69_rodata_8C;
    v3.y = lbl_69_rodata_8C;
    *(IntPair*)&l3 = *(IntPair*)&v3;
    o->work->sound[3].id = 0x1CF3;
    o->work->sound[3].a = 0;
    o->work->sound[3].c = 0;
    o->work->sound[3].b = 0;
    o->work->sound[3].pos = l3;
}
