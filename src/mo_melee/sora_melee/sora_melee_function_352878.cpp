#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    virtual void slot3();
    virtual int slot4();
    virtual int slot5();
};

extern "C" {
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int,
                 void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_1D8FC8(void*, int);
void fn_27_1D90FC(void*);
void fn_27_3530C0(void*, void*, void*);
void fn_27_32099C(void*, void*, void*);
extern char lbl_27_data_8E578[];
extern char lbl_27_data_8E588[];
extern char lbl_27_data_8E7F4[];
extern char lbl_27_data_8EA60[];
}

extern "C" void* fn_27_352878(char* self, int arg1, void* arg2, const int* arg3) {
    int out[16];
    int t26;
    int t27;
    Object_vptr_0* obj = *(Object_vptr_0**)((char*)arg2 + 4);
    t27 = obj->slot5();
    t26 = obj->slot4();
    int t3 = obj->slot2();

    fn_27_1DC5E8(out, 0x23, arg3, t3, t26, t27, *arg3 & 0xff, -1,
                 self + 0x1D5C, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_8E578, out[1], out[2], arg1, arg2,
                 self + 0x8C4, 1);

    char* modules = self + 0xCC;
    char* d = lbl_27_data_8E7F4;
    *(char**)(self + 0x3C) = d;
    *(char**)(self + 0x40) = d + 0x64;
    *(char**)(self + 0x48) = d + 0x70;
    *(char**)(self + 0x54) = d + 0x84;
    *(char**)(self + 0x64) = d + 0xDC;
    *(char**)(self + 0x70) = d + 0xEC;
    *(char**)(self + 0x7C) = d + 0x100;
    *(char**)(self + 0x88) = d + 0x118;
    *(char**)(self + 0x90) = d + 0x124;
    fn_27_3530C0(modules, self, out);
    fn_27_32099C(modules + 0x16D8, modules + 0x7F8, out);
    fn_27_1D90FC(self);

    char* e = lbl_27_data_8E588;
    *(char**)(self + 0x3C) = e;
    *(char**)(self + 0x40) = e + 0x64;
    *(char**)(self + 0x48) = e + 0x70;
    *(char**)(self + 0x54) = e + 0x84;
    *(char**)(self + 0x64) = e + 0xDC;
    *(char**)(self + 0x70) = e + 0xEC;
    *(char**)(self + 0x7C) = e + 0x100;
    *(char**)(self + 0x88) = e + 0x118;
    *(char**)(self + 0x90) = e + 0x124;
    *(int*)(self + 0x1D58) = arg3[13];
    *(unsigned char*)(self + 0x1D60) = 0;
    *(int*)(self + 0x1D68) = 0x23;
    *(int*)(self + 0x1D6C) = 0xF9F;
    *(int*)(self + 0x1D70) = 0x5DBF;
    *(int*)(self + 0x1D74) = 0;

    char* f = lbl_27_data_8EA60;
    *(char**)(self + 0x1D64) = f;
    *(char**)(self + 0x1D5C) = f + 8;
    *(int*)(self + 0x1D78) = *(int*)(self + 0x1D58);
    fn_27_1D8FC8(self, 0);
    return self;
}