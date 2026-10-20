#pragma force_active on

struct Vec2f {
    float x, y;

    Vec2f(float a, float b) : x(a), y(b) {}
};

class Kinetic {
public:
    virtual bool isNull() const;
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy();
    virtual void eraseEnergy();
    virtual void eraseEnergyAll();
    virtual void* getEnergy(int);
};

struct Modules {
    char pad[0x7c];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern const char lbl_104_data_80B4[];
extern const char lbl_104_data_2404[];
extern const float lbl_104_rodata_B0;

void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_104_13810(void*, Accesser* accesser) {
    char* energy = (char*)__dynamic_cast(
        accesser->modules->kinetic->getEnergy(0),
        0, lbl_104_data_80B4, lbl_104_data_2404, 1);

    Vec2f v(lbl_104_rodata_B0, lbl_104_rodata_B0);
    ((Vec2f*)(energy + 8))->x = v.x;
    ((Vec2f*)(energy + 8))->y = v.y;
}
