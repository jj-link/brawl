#pragma force_active on
extern "C" void fn_93_10C84(void*, int);
extern "C" void fn_93_10BA0(void*, struct Vec3f*, struct Vec3f*);
extern const float lbl_93_rodata_64;
extern const float lbl_93_rodata_6C;

struct Vec3f {
    float x, y, z;
};

struct Local {
    int a;
    int b;
    Vec3f p;
    Vec3f q;
};

class Class_8B7C {
public:
    virtual void fn_93_22F8() = 0;
    virtual void fn_93_12AB4() = 0;
    virtual void fn_93_14638() = 0;
    virtual void fn_93_14634() = 0;
    virtual void fn_93_14630() = 0;
    virtual void fn_93_1462C(int, int) = 0;
    virtual void fn_93_14624() = 0;
    virtual void fn_93_1466C() = 0;
    virtual void fn_93_14664() = 0;
    virtual void fn_93_1465C() = 0;
    virtual void fn_93_14654() = 0;
    virtual void fn_93_1464C() = 0;
    virtual void fn_93_145E4() = 0;
    virtual void fn_93_14618() = 0;
    virtual void fn_93_1460C() = 0;
    virtual void fn_93_14604() = 0;
    virtual void fn_93_145F8() = 0;
    virtual int fn_93_145F0(int) = 0;
};

class Class_8D00 {
public:
    virtual void fn_93_22F8() = 0;
    virtual void fn_93_12B10() = 0;
    virtual void fn_93_147F4() = 0;
    virtual void fn_93_147EC() = 0;
    virtual void fn_93_147E4() = 0;
    virtual void fn_93_147DC() = 0;
    virtual void fn_93_147D4() = 0;
    virtual void fn_93_147CC() = 0;
    virtual void fn_93_147C4() = 0;
    virtual void fn_93_147BC() = 0;
    virtual void fn_93_147B4() = 0;
    virtual int fn_93_147AC(unsigned int, int, Vec3f*, Vec3f*, float, int, int, int) = 0;
    virtual void fn_93_147A4() = 0;
    virtual void fn_93_1479C() = 0;
    virtual void fn_93_1474C() = 0;
    virtual void fn_93_14794() = 0;
    virtual void fn_93_14784() = 0;
    virtual void fn_93_14774() = 0;
};

struct Modules {
    char pad00[0x64];
    Class_8B7C* a;
    char pad68[0x20];
    Class_8D00* b;
};

extern "C" void fn_93_10AB0(void* arg0) {
    Modules* m = *reinterpret_cast<Modules**>(reinterpret_cast<char*>(arg0) + 0xd8);
    if (m->a->fn_93_145F0(0x22000014) != 0) {
        m = *reinterpret_cast<Modules**>(reinterpret_cast<char*>(arg0) + 0xd8);
        Class_8B7C* o30 = m->a;
        Class_8D00* o29 = m->b;
        fn_93_10C84(arg0, 0x20000001);
        Local loc;
        fn_93_10BA0(arg0, &loc.p, &loc.q);
        loc.q.y = lbl_93_rodata_64;
        loc.a = -1;
        int r = o29->fn_93_147AC(0xE20004, 0, &loc.p, &loc.q, lbl_93_rodata_6C, 1, 0, 0);
        o30->fn_93_1462C(r, 0x20000002);
    }
}
