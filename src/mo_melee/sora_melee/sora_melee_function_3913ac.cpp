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
                 void*, void*, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_1D8FC8(void*, int);
void fn_27_1D90FC(void*);
void fn_27_3918B8(void*, void*, void*);
void fn_27_392EDC(void*, void*, void*);
extern char lbl_27_data_9A368[];
extern char lbl_27_data_9A380[];
extern char lbl_27_data_9A5EC[];
extern char lbl_27_data_9A858[];
}

extern "C" void* fn_27_3913AC(char* self, int arg1, void* arg2, const int* arg3) {
    int out[16];
    int t26;
    Object_vptr_0* obj = *(Object_vptr_0**)((char*)arg2 + 4);
    t26 = obj->slot5();
    int t3 = obj->slot2();

    fn_27_1DC5E8(out, 0x12, arg3, t3, 0x1F, t26, *arg3 & 0xff, -1,
                 self + 0x1FF0, (char*)arg3 + 0x38, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_9A368, out[1], out[2], arg1, arg2,
                 self + 0x55C, 1);

    char* modules = self + 0xCC;
    char* d = lbl_27_data_9A5EC;
    *(char**)(self + 0x3C) = d;
    *(char**)(self + 0x40) = d + 0x64;
    *(char**)(self + 0x48) = d + 0x70;
    *(char**)(self + 0x54) = d + 0x84;
    *(char**)(self + 0x64) = d + 0xDC;
    *(char**)(self + 0x70) = d + 0xEC;
    *(char**)(self + 0x7C) = d + 0x100;
    *(char**)(self + 0x88) = d + 0x118;
    *(char**)(self + 0x90) = d + 0x124;
    fn_27_3918B8(modules, self, out);
    fn_27_392EDC(modules + 0x1BC4, modules + 0x490, out);
    fn_27_1D90FC(self);

    char* e = lbl_27_data_9A380;
    *(char**)(self + 0x3C) = e;
    *(char**)(self + 0x40) = e + 0x64;
    *(char**)(self + 0x48) = e + 0x70;
    *(char**)(self + 0x54) = e + 0x84;
    *(char**)(self + 0x64) = e + 0xDC;
    *(char**)(self + 0x70) = e + 0xEC;
    *(char**)(self + 0x7C) = e + 0x100;
    *(char**)(self + 0x88) = e + 0x118;
    *(char**)(self + 0x90) = e + 0x124;
    *(int*)(self + 0x1FEC) = arg3[13];
    *(unsigned char*)(self + 0x1FF4) = 0;
    *(int*)(self + 0x1FFC) = 0x12;
    *(int*)(self + 0x2000) = 0xF9F;
    *(int*)(self + 0x2004) = 0x5DBF;
    *(int*)(self + 0x2008) = 0;

    char* f = lbl_27_data_9A858;
    *(char**)(self + 0x1FF8) = f;
    *(char**)(self + 0x1FF0) = f + 8;
    *(int*)(self + 0x2010) = *(int*)(self + 0x1FEC);
    fn_27_1D8FC8(self, 0);
    return self;
}
