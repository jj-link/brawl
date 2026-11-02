#pragma force_active on

extern "C" {
extern char lbl_27_data_457C0[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_65B0;
extern const float lbl_27_rodata_65B4;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1DA1F4(void*, int);
}

struct Vec2f {
    float x, y;
    Vec2f() {}
    Vec2f(float a, float b) : x(a), y(b) {}
};

static inline const float& asFloat(const unsigned long long& v) {
    return *(const float*)&v;
}

struct Kinetic {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void* get(int);
};

struct Work {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual int getInt(unsigned long);
};

struct Modules {
    char pad0[0x64];
    Work* work;
    char pad1[0x7c - 0x68];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Entry {
    char pad[0x14];
    float x;
    float y;
};

struct Table {
    char pad[0x70];
    Entry* entries;
};

struct Energy {
    virtual void d0();
    virtual void d1();
    virtual unsigned long long getRaw();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void update();
    char pad4[4];
    Vec2f m8;
    char pad10[8];
    Vec2f m18;
    Vec2f m20;
    Vec2f m28;
};

struct Self {
    char pad[0x60];
    Accesser* accesser;
    char pad2[0x2044 - 0x64];
    Table* table;
};

extern "C" void fn_27_30EBD8(Self* self, int arg) {
    fn_27_1DA1F4(self, arg);
    if (arg == 2) {
        Energy* e = (Energy*)__dynamic_cast(
            self->accesser->modules->kinetic->get(0), 0,
            lbl_27_data_457C0, lbl_27_data_CDF8, 0);
        if (e != 0) {
            Entry* ent = &self->table->entries[self->accesser->modules->work->getInt(0x10000005)];
            e->m8 = Vec2f(asFloat(e->getRaw()), lbl_27_rodata_65B4);
            e->m18 = Vec2f(lbl_27_rodata_65B4, lbl_27_rodata_65B4);
            e->m20 = Vec2f(ent->x, lbl_27_rodata_65B0);
            e->m28 = Vec2f(ent->y, lbl_27_rodata_65B4);
            e->update();
        }
    }
}
