#include <types.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2();
    virtual void slot3(void*, int, short*, int);
    virtual void* slot4();
    virtual void* slot5();
};

extern "C" {
void fn_27_1DC5E8(void*, int, const void*, void*, void*, void*, unsigned char, int,
                  void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, unsigned int, unsigned int, int, void*, void*, int);
void fn_27_31D7D8(void*, void*, void*);
void fn_27_2DBBA8(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);

extern char lbl_27_data_853D0[];
extern char lbl_27_data_853E4[];
extern char lbl_27_data_85650[];
extern char lbl_27_data_858BC[];
extern char lbl_27_data_13730[];
extern float lbl_27_rodata_7538;
extern float lbl_27_rodata_753C;
}

struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };

struct Vec {
    float x;
    float y;
    float z;
};

struct Words {
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

struct Arg3 {
    int id;
    char padding[0x30];
    int value;
};

extern "C" void* fn_27_31D1BC(char* self, int arg1, char* arg2, const int* arg3) {
    void* b;
    void* a;
    Object_vptr_0* obj = *(Object_vptr_0**)(arg2 + 4);
    a = obj->slot5();
    b = obj->slot4();
    void* c = obj->slot2();
    char* resource = self + 0x1EFC;
    unsigned char id = *arg3 & 0xff;

    unsigned int desc[18];
    fn_27_1DC5E8(desc, 0x22, arg3, c, b, a, id & 0xFF,
                  -1, resource, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_853D0, desc[1], desc[2], arg1, arg2,
                 self + 0x8C4, 1);

    char* subobject = self + 0xCC;
    *(char**)(self + 0x3C) = lbl_27_data_85650;
    *(char**)(self + 0x40) = lbl_27_data_85650 + 0x64;
    *(char**)(self + 0x48) = lbl_27_data_85650 + 0x70;
    *(char**)(self + 0x54) = lbl_27_data_85650 + 0x84;
    *(char**)(self + 0x64) = lbl_27_data_85650 + 0xDC;
    *(char**)(self + 0x70) = lbl_27_data_85650 + 0xEC;
    *(char**)(self + 0x7C) = lbl_27_data_85650 + 0x100;
    *(char**)(self + 0x88) = lbl_27_data_85650 + 0x118;
    *(char**)(self + 0x90) = lbl_27_data_85650 + 0x124;

    fn_27_31D7D8(subobject, self, desc);
    fn_27_2DBBA8(subobject + 0x1800, subobject + 0x7F8, desc);
    fn_27_1DBA64(self + 0x1E7C);

    Vec v4 = {lbl_27_rodata_7538, lbl_27_rodata_7538, lbl_27_rodata_7538};
    Vec v3 = {lbl_27_rodata_753C, lbl_27_rodata_753C, lbl_27_rodata_753C};
    Vec v2 = {lbl_27_rodata_7538, lbl_27_rodata_7538, lbl_27_rodata_7538};
    Vec v1 = {lbl_27_rodata_753C, lbl_27_rodata_753C, lbl_27_rodata_753C};
    Vec v0 = {lbl_27_rodata_753C, lbl_27_rodata_753C, lbl_27_rodata_753C};

    self[0x1EB8] = 0;
    ((FlagByte*)(self + 0x1EB9))->flag = 1;
    self[0x1EBA] = 0;
    *(char**)(self + 0x1EB4) = lbl_27_data_13730;
    *(Words*)(self + 0x1EBC) = *(Words*)&v0;
    *(Words*)(self + 0x1EC8) = *(Words*)&v1;
    *(Words*)(self + 0x1ED4) = *(Words*)&v2;
    *(Words*)(self + 0x1EE0) = *(Words*)&v3;
    *(Words*)(self + 0x1EEC) = *(Words*)&v4;

    fn_27_1D90FC(self);

    short y[2];
    short x[2];
    x[0] = 1;
    Object_vptr_0* observer =
        *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x7C);
    observer->slot3(self + 0x1E7C, 0, x, -1);

    y[0] = 1;
    observer = *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x7C);
    observer->slot3(self + 0x1EB4, 1, y, -1);

    *(char**)(self + 0x3C) = lbl_27_data_853E4;
    *(char**)(self + 0x40) = lbl_27_data_853E4 + 0x64;
    *(char**)(self + 0x48) = lbl_27_data_853E4 + 0x70;
    *(char**)(self + 0x54) = lbl_27_data_853E4 + 0x84;
    *(char**)(self + 0x64) = lbl_27_data_853E4 + 0xDC;
    *(char**)(self + 0x70) = lbl_27_data_853E4 + 0xEC;
    *(char**)(self + 0x7C) = lbl_27_data_853E4 + 0x100;
    *(char**)(self + 0x88) = lbl_27_data_853E4 + 0x118;
    *(char**)(self + 0x90) = lbl_27_data_853E4 + 0x124;

    *(int*)(self + 0x1EF8) = arg3[13];
    self[0x1F00] = 0;
    *(int*)(self + 0x1F08) = 0x22;
    *(int*)(self + 0x1F0C) = 0xF9F;
    *(int*)(self + 0x1F10) = 0x5DBF;
    *(int*)(self + 0x1F14) = 0;
    *(char**)(self + 0x1F04) = lbl_27_data_858BC;
    *(char**)(self + 0x1EFC) = lbl_27_data_858BC + 8;
    *(int*)(self + 0x1F18) = arg3[13];

    fn_27_1D8FC8(self, 0);
    return self;
}
