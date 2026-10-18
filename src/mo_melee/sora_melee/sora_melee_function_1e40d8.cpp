#pragma force_active on
typedef unsigned long long u64;

struct Pair {
    float x, y;
};

struct Energy {
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void* get(int);
    virtual void e7();
    virtual void e8();
    virtual void e9();
    virtual void e10();
    virtual void e11();
    virtual void e12();
    virtual u64 position(short*);
};

struct Motion {
    char pad[8];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void set(int, int);
};

struct Modules {
    char pad[0x10];
    Motion* motion;
    char pad2[0x68];
    Energy* energy;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

struct Config {
    char pad[0x9a8];
    float values[16];
};

struct Result {
    char pad[8];
    float x, y;
    float a, b, c, d, e, f, g, h;
};

extern "C" {
extern char lbl_27_data_457C0[];
extern char lbl_27_data_CDF8[];

void* __dynamic_cast(void*, long, const void*, const void*, short);

void fn_27_1E40D8(Config* self, int mode, int unused, Object* obj) {
    Energy* energy = obj->modules->energy;
    Result* result = (Result*)__dynamic_cast(
        energy->get(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);

    short index = -1;
    union {
        u64 raw;
        Pair pair;
    } position;
    position.raw = energy->position(&index);
    result->x = position.pair.x;
    result->y = position.pair.y;

    if (mode == 0) {
        Motion* motion = obj->modules->motion;
        motion->set(1, 0);
        result->a = self->values[0];
        result->b = self->values[1];
        result->e = self->values[2];
        result->f = self->values[3];
        result->c = self->values[4];
        result->d = self->values[5];
        result->g = self->values[6];
        result->h = self->values[7];
    } else {
        Motion* motion = obj->modules->motion;
        motion->set(5, 0);
        result->a = self->values[8];
        result->b = self->values[9];
        result->e = self->values[10];
        result->f = self->values[11];
        result->c = self->values[12];
        result->d = self->values[13];
        result->g = self->values[14];
        result->h = self->values[15];
    }
}
}
