#pragma force_active on
struct Vec2f { float x, y; };

struct Modules {
    char pad[0x7c];
    void* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

class Kinetic {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
};

extern "C" {
extern const char lbl_96_data_AF64[];
extern const char lbl_96_data_B2F4[];
extern const char lbl_96_data_5E00[];
extern const float lbl_96_rodata_4C;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_96_B890(Vec2f*, const Vec2f*);

void fn_96_15378(Accesser* a, Vec2f* v) {
    Kinetic* k = (Kinetic*)a->modules->kinetic;

    void* obj1 = k->getEnergy(3);
    void* energy1 = __dynamic_cast(obj1, 0, lbl_96_data_AF64, lbl_96_data_5E00, 1);

    void* obj2 = k->getEnergy(1);
    void* energy2 = __dynamic_cast(obj2, 0, lbl_96_data_B2F4, lbl_96_data_5E00, 1);

    ((unsigned char*)energy1)[5] |= 0x80;

    Vec2f v1, v2, v3, v4;

    v1.x = v->x; v1.y = lbl_96_rodata_4C;
    fn_96_B890((Vec2f*)((char*)energy1 + 8), &v1);

    v2.x = lbl_96_rodata_4C; v2.y = lbl_96_rodata_4C;
    fn_96_B890((Vec2f*)((char*)energy1 + 0x10), &v2);

    v3.x = v->x; v3.y = lbl_96_rodata_4C;
    fn_96_B890((Vec2f*)((char*)energy1 + 0x28), &v3);

    v4.x = v->x; v4.y = lbl_96_rodata_4C;
    fn_96_B890((Vec2f*)((char*)energy1 + 0x18), &v4);

    ((unsigned char*)energy2)[5] |= 0x80;
    float y = v->y;
    *(float*)((char*)energy2 + 0xc) = y;
    *(float*)((char*)energy2 + 0x10) = lbl_96_rodata_4C;
    *(float*)((char*)energy2 + 0x1c) = y;
    *(float*)((char*)energy2 + 0x14) = y;
}
}
