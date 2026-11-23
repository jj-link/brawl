#include <types.h>

#pragma force_active on

class Class_CF8 {
public:
    virtual void fn_27_1000C();
    virtual void fn_27_100D0();
    virtual void* fn_27_100CC();
    virtual void fn_27_10094();
    virtual void fn_27_100C8();
    virtual void* fn_27_100C4();
};

class Class_18ED8 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(void*, int, short*, int);
    virtual void slot4();
    virtual void slot5();
};

struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };

struct Vec {
    float x;
    float y;
    float z;

    Vec& operator=(const Vec& other) {
        ((unsigned int*)this)[0] = ((const unsigned int*)&other)[0];
        ((unsigned int*)this)[1] = ((const unsigned int*)&other)[1];
        ((unsigned int*)this)[2] = ((const unsigned int*)&other)[2];
        return *this;
    }
};

extern "C" {
void fn_27_1DC5E8(void*, int, const void*, void*, int, void*, unsigned char,
                  int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, unsigned int, unsigned int, int, void*,
                  void*, int);
void fn_27_3B3884(void*, void*, void*);
void fn_27_2DBBA8(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);

extern char lbl_27_data_A0268[];
extern char lbl_27_data_A0278[];
extern char lbl_27_data_A0590[];
extern char lbl_27_data_A08C8[];
extern char lbl_27_data_13730[];
extern float lbl_27_rodata_7FD0;
extern float lbl_27_rodata_7FD4;
}

extern "C" void* fn_27_3B3280(char* self, int arg1, void* arg2, const int* arg3) {
    char* p = (char*)self;
    const char* a = (const char*)arg3;
    void* v1;
    Class_CF8* iface = *(Class_CF8**)((char*)arg2 + 4);
    v1 = iface->fn_27_100C4();
    void* v2 = iface->fn_27_100CC();
    unsigned int buf[18];
    unsigned char kind = (unsigned char)*(int*)a;
    char* sp8 = p + 0x1f18;
    int spC = 0;
    int sp10 = 0;
    int sp14 = 0;
    int sp18 = 0;
    int sp1C = 0;
    int sp20 = 0;
    int sp24 = 0;

    fn_27_1DC5E8(buf, 0x89, arg3, v2, 0x1f, v1,
                  kind, -1, sp8, spC, sp10, sp14, sp18, sp1C, sp20, sp24);
    fn_27_1D7EF0(p, lbl_27_data_A0268, buf[1], buf[2], arg1, arg2,
                  p + 0x8c4, 1);

    char* sub = p + 0xcc;
    *(void**)(p + 0x3c) = lbl_27_data_A0590;
    *(void**)(p + 0x40) = lbl_27_data_A0590 + 0x64;
    *(void**)(p + 0x48) = lbl_27_data_A0590 + 0x70;
    *(void**)(p + 0x54) = lbl_27_data_A0590 + 0x84;
    *(void**)(p + 0x64) = lbl_27_data_A0590 + 0xdc;
    *(void**)(p + 0x70) = lbl_27_data_A0590 + 0xec;
    *(void**)(p + 0x7c) = lbl_27_data_A0590 + 0x100;
    *(void**)(p + 0x88) = lbl_27_data_A0590 + 0x118;
    *(void**)(p + 0x90) = lbl_27_data_A0590 + 0x124;

    fn_27_3B3884(sub, p, buf);
    fn_27_2DBBA8(sub + 0x181c, sub + 0x7f8, buf);
    fn_27_1DBA64(p + 0x1e98);

    Vec v5 = {lbl_27_rodata_7FD0, lbl_27_rodata_7FD0, lbl_27_rodata_7FD0};
    Vec v4 = {lbl_27_rodata_7FD4, lbl_27_rodata_7FD4, lbl_27_rodata_7FD4};
    Vec v2a = {lbl_27_rodata_7FD0, lbl_27_rodata_7FD0, lbl_27_rodata_7FD0};
    Vec v3 = {lbl_27_rodata_7FD4, lbl_27_rodata_7FD4, lbl_27_rodata_7FD4};
    Vec v0 = {lbl_27_rodata_7FD4, lbl_27_rodata_7FD4, lbl_27_rodata_7FD4};

    *(u8*)(p + 0x1ed4) = 0;
    ((FlagByte*)(p + 0x1ed5))->flag = 1;
    *(u8*)(p + 0x1ed6) = 0;
    *(void**)(p + 0x1ed0) = lbl_27_data_13730;
    *(Vec*)(p + 0x1ed8) = v0;
    *(Vec*)(p + 0x1ee4) = v3;
    *(Vec*)(p + 0x1ef0) = v2a;
    *(Vec*)(p + 0x1efc) = v4;
    *(Vec*)(p + 0x1f08) = v5;

    fn_27_1D90FC(p);

    struct ShortSlot { short value; short pad; } one2, one;
    one.value = 1;
    ((Class_18ED8*)*(void**)((char*)*(void**)
        ((char*)*(void**)(p + 0x60) + 0xd8) + 0x7c))
        ->slot3(p + 0x1e98, 0, &one.value, -1);

    one2.value = 1;
    ((Class_18ED8*)*(void**)((char*)*(void**)
        ((char*)*(void**)(p + 0x60) + 0xd8) + 0x7c))
        ->slot3(p + 0x1ed0, 1, &one2.value, -1);

    *(void**)(p + 0x3c) = lbl_27_data_A0278;
    *(void**)(p + 0x40) = lbl_27_data_A0278 + 0x64;
    *(void**)(p + 0x48) = lbl_27_data_A0278 + 0x70;
    *(void**)(p + 0x54) = lbl_27_data_A0278 + 0x84;
    *(void**)(p + 0x64) = lbl_27_data_A0278 + 0xdc;
    *(void**)(p + 0x70) = lbl_27_data_A0278 + 0xec;
    *(void**)(p + 0x7c) = lbl_27_data_A0278 + 0x100;
    *(void**)(p + 0x88) = lbl_27_data_A0278 + 0x118;
    *(void**)(p + 0x90) = lbl_27_data_A0278 + 0x124;
    *(int*)(p + 0x1f14) = arg3[13];
    *(u8*)(p + 0x1f1c) = 0;
    *(int*)(p + 0x1f24) = 0x89;
    *(int*)(p + 0x1f28) = 0xf9f;
    *(int*)(p + 0x1f2c) = 0x5dbf;
    *(int*)(p + 0x1f30) = 0;
    *(void**)(p + 0x1f20) = lbl_27_data_A08C8;
    *(void**)(p + 0x1f18) = lbl_27_data_A08C8 + 8;
    *(int*)(p + 0x1f34) = arg3[13];

    fn_27_1D8FC8(p, 0);
    return self;
}
