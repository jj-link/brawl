#pragma force_active on
typedef unsigned char u8;

struct Vec2 {
    float x, y;

    void set(float a, float b) {
        x = a;
        y = b;
    }
};

struct Entry {
    Vec2 current, previous;
};

struct Obj {
    u8 pad[0x10];
    Entry* base;
};

extern "C" void fn_801121CC(Obj* self, unsigned short idx, const Vec2* v) {
    float y = v->y;
    float x = v->x;
    self->base[idx].previous.set(x, y);
    self->base[idx].current.set(x, y);
}
