#pragma force_active on
typedef unsigned char Byte;

struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };

class Resource {
public:
    virtual void s08();
    virtual void s0c();
    virtual void* get10();
    virtual void s14();
    virtual void* get18();
    virtual void* get1c();
};

class Modules {
public:
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void attach(void*, int, void*, short);
    virtual void s18();
    virtual void s1c();
    virtual void* energy(int);
    virtual short get24();
    virtual void s28();
    virtual void configure(void*, int);
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5c();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6c();
    virtual void s70();
    virtual void s74();
    virtual void entries(int*, int);
};

struct Container {
    Byte pad[8];
    Modules sub;
};

extern "C" {
void* fn_122_23F48();
Resource* fn_122_23F40(void*);
void fn_27_1DC5E8(void*, int, void*, void*, void*, void*, unsigned char,
                  int, void*, int, int, int, int, int, int, int);

extern Byte lbl_122_data_101E0[];
extern Byte lbl_122_data_101FC[];
extern Byte lbl_122_data_E1EC[];
extern Byte lbl_122_data_81AC[];
extern const float lbl_122_rodata_140;
extern const float lbl_122_rodata_13C;

void fn_122_2460C(void*, void*, void*, void*, void*);
void fn_122_16E54(void*, short);
void* fn_122_24410(void*);
Container* fn_122_24404(void*);
void fn_122_243A0(void*, short, signed char);
void fn_122_24418(void*, short, signed char);
Vec2* fn_122_145AC(Vec2*, float, float);
void fn_122_2447C(void*, float, Vec2*, Vec2*, Vec2*, Vec2*, Vec2*, int);
void fn_122_2455C(void*, float, float, float);
Modules* fn_122_245C4(void*);
int fn_122_245D0();
Modules* fn_122_245DC(void*);
void fn_122_245E8(void*, short);
Modules* fn_122_245F0(void*);
void fn_122_CDAC(void*, short);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3* fn_122_D580(Vec3*, float, float, float);
void fn_122_245FC(void*, Vec3*);
void fn_122_24604(void*, Vec3*);
void fn_27_1D8FC8(void*, int);
}

extern "C" Byte* fn_122_23B40(
    Byte* object, void* owner, void* resource, Byte* params)
{
    Byte temporary[0x40];
    fn_27_1DC5E8(
        temporary, 0x1d, params,
        fn_122_23F40(resource)->get10(),
        fn_122_23F40(resource)->get18(),
        fn_122_23F40(resource)->get1c(),
        (Byte)*(unsigned*)params, -1, fn_122_23F48(),
        0, 0, 0, 0, 0, 0, 0);

    fn_122_2460C(object, lbl_122_data_101E0, owner, resource, temporary);
    fn_122_16E54(temporary, -1);

    short id1 = fn_122_24404(fn_122_24410(object))->sub.get24();
    fn_122_243A0(object + 0x24f8, id1, -1);
    short id2 = fn_122_24404(fn_122_24410(object))->sub.get24();
    fn_122_24418(object + 0x2504, id2, -1);

    *(Byte**)(object + 0x3c) = lbl_122_data_101FC;
    *(Byte**)(object + 0x40) = lbl_122_data_101FC + 0x64;
    *(Byte**)(object + 0x48) = lbl_122_data_101FC + 0x70;
    *(Byte**)(object + 0x54) = lbl_122_data_101FC + 0x84;
    *(Byte**)(object + 0x64) = lbl_122_data_101FC + 0xdc;
    *(Byte**)(object + 0x70) = lbl_122_data_101FC + 0xec;
    *(Byte**)(object + 0x7c) = lbl_122_data_101FC + 0x100;
    *(Byte**)(object + 0x88) = lbl_122_data_101FC + 0x118;
    *(Byte**)(object + 0x90) = lbl_122_data_101FC + 0x124;
    *(Byte**)(object + 0x24f8) = lbl_122_data_101FC + 0x26c;
    *(Byte**)(object + 0x2504) = lbl_122_data_101FC + 0x280;
    *(void**)(object + 0x2510) = *(void**)(params + 0x34);

    Vec2 a, b, c, d, e;
    fn_122_2447C(
        object + 0x2514, lbl_122_rodata_13C,
        fn_122_145AC(&a, lbl_122_rodata_13C, lbl_122_rodata_13C),
        fn_122_145AC(&b, lbl_122_rodata_13C, lbl_122_rodata_13C),
        fn_122_145AC(&c, lbl_122_rodata_140, lbl_122_rodata_140),
        fn_122_145AC(&d, lbl_122_rodata_13C, lbl_122_rodata_13C),
        fn_122_145AC(&e, lbl_122_rodata_140, lbl_122_rodata_140), 0);

    Byte* p = *(Byte**)(object + 0x2510);
    fn_122_2455C(object + 0x254c, lbl_122_rodata_13C,
                  -*(float*)(p + 0x48), *(float*)(p + 0x4c));

    fn_122_245C4(fn_122_24410(object))->configure(params + 0x38, 0);

    int entries[3] = {0, 0, 0};
    entries[0] = fn_122_245D0();
    fn_122_245DC(fn_122_24410(object))->entries(entries, 3);

    short h1;
    fn_122_245E8(&h1, 1);
    fn_122_245F0(fn_122_24410(object))->attach(
        object + 0x2514, 2, &h1, -1);
    fn_122_CDAC(&h1, -1);

    short h2;
    fn_122_245E8(&h2, 1);
    fn_122_245F0(fn_122_24410(object))->attach(
        object + 0x254c, 3, &h2, -1);
    fn_122_CDAC(&h2, -1);

    void* energy = __dynamic_cast(
        fn_122_245F0(fn_122_24410(object))->energy(1),
        0, lbl_122_data_E1EC, lbl_122_data_81AC, 0);

    if (energy) {
        Vec3 v1, v2;
        fn_122_245FC(
            energy,
            fn_122_D580(&v1, lbl_122_rodata_13C, lbl_122_rodata_13C,
                *(float*)(*(Byte**)(object + 0x2510) + 0x1c)));
        fn_122_24604(
            energy,
            fn_122_D580(&v2, lbl_122_rodata_13C, lbl_122_rodata_13C,
                *(float*)(*(Byte**)(object + 0x2510) + 0x20)));
    }

    fn_27_1D8FC8(object, 0);
    return object;
}
