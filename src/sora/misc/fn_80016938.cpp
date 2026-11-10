#pragma force_active on
#include <gf/gf_heap_manager.h>
#include <revolution/GX/GXInit.h>

struct Light {
    unsigned int data[16];
};

struct Color {
    unsigned char r, g, b, a;
};

struct Vec3f {
    float x, y, z;
};

struct Screen {
    unsigned char pad0[0x7C];
    unsigned int a;
    unsigned int b;
    unsigned char pad1[8];
    unsigned short c;
    unsigned short d;
};

extern "C" void fn_801F2400(Light*, Color);
extern "C" void fn_801F2284(Light*, float, float, float);
extern "C" void fn_8003DE70(Vec3f*);
extern "C" void fn_801F22B0(Light*, float, float, float);
extern "C" void fn_801F202C(Light*, int, float);
extern "C" void fn_801F21B4(Light*, int, float, float);
extern "C" void fn_801F2418(Light*, unsigned int);
extern "C" void fn_801F47D8(int, int);
extern "C" void fn_801F5500(int, int, int, int);
extern "C" void fn_801F5484(float, float, float, float, float, float);
extern "C" void fn_801F4880(int);
extern "C" void fn_80023E7C(Screen*);
extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
extern "C" void* memset(void*, int, unsigned long);

extern const float lbl_805A13C8;
extern const float lbl_805A13CC;
extern const float lbl_805A13D0;
extern const float lbl_805A13D4;
extern const float lbl_805A13D8;
extern const float lbl_805A13DC;

extern "C" void fn_80016938(Screen* screen) {
    Light light;
    Vec3f dir;
    Color color;

    void* buf = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(4, 0x40000);
    if (buf) {
        memset(buf, 0, 0x40000);
    }
    GXInit(buf, 0x00040000);

    color.r = color.g = color.b = color.a = 0x80;
    fn_801F2284(&light, lbl_805A13C8, lbl_805A13CC, lbl_805A13C8);
    fn_801F2400(&light, color);

    dir.x = lbl_805A13D0;
    dir.y = lbl_805A13D0;
    dir.z = lbl_805A13D0;
    fn_8003DE70(&dir);
    fn_801F22B0(&light, dir.x, dir.y, dir.z);

    fn_801F202C(&light, 0, lbl_805A13D4);
    fn_801F21B4(&light, 0, lbl_805A13CC, lbl_805A13D8);
    fn_801F2418(&light, 1);
    fn_801F2418(&light, 2);
    fn_801F2418(&light, 4);
    fn_801F2418(&light, 0x80);

    fn_801F47D8(screen->a, screen->b);
    fn_801F5500(0, 0, screen->c, screen->d);
    fn_801F5484(lbl_805A13C8, lbl_805A13C8, (float)screen->c, (float)screen->d, lbl_805A13C8, lbl_805A13DC);
    fn_801F4880(0);
    fn_80023E7C((Screen*)((char*)screen + 0x58));
}
