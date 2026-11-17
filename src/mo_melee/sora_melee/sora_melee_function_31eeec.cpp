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
void fn_27_31F850(void*, void*, void*);
void fn_27_32099C(void*, void*, void*);
extern char lbl_27_data_85DA8[];
extern char lbl_27_data_85DB4[];
extern char lbl_27_data_86020[];
extern char lbl_27_data_8628C[];
}

static inline void initializeBase(char* self, int arg1, void* arg2, const int* arg3) {
    int out[16];
    Object_vptr_0* obj = *(Object_vptr_0**)((char*)arg2 + 4);
    int t27;
    int t26;
    t27 = obj->slot5();
    t26 = obj->slot4();
    int t3 = obj->slot2();

    fn_27_1DC5E8(out, 0x1E, arg3, t3, t26, t27, *arg3 & 0xff, -1,
                 self + 0x1D50, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_85DA8, out[1], out[2], arg1, arg2,
                 self + 0x8B8, 1);

    char* modules = self + 0xCC;
    char* d = lbl_27_data_86020;
    *(char**)(self + 0x3C) = d;
    *(char**)(self + 0x40) = d + 0x64;
    *(char**)(self + 0x48) = d + 0x70;
    *(char**)(self + 0x54) = d + 0x84;
    *(char**)(self + 0x64) = d + 0xDC;
    *(char**)(self + 0x70) = d + 0xEC;
    *(char**)(self + 0x7C) = d + 0x100;
    *(char**)(self + 0x88) = d + 0x118;
    *(char**)(self + 0x90) = d + 0x124;
    fn_27_31F850(modules, self, out);
    fn_27_32099C(modules + 0x16CC, modules + 0x7EC, out);
    fn_27_1D90FC(self);

}

extern "C" void* fn_27_31EEEC(char* self, int arg1, void* arg2, const int* arg3) {
    initializeBase(self, arg1, arg2, arg3);

    char* e = lbl_27_data_85DB4;
    *(char**)(self + 0x3C) = e;
    *(char**)(self + 0x40) = e + 0x64;
    *(char**)(self + 0x48) = e + 0x70;
    *(char**)(self + 0x54) = e + 0x84;
    *(char**)(self + 0x64) = e + 0xDC;
    *(char**)(self + 0x70) = e + 0xEC;
    *(char**)(self + 0x7C) = e + 0x100;
    *(char**)(self + 0x88) = e + 0x118;
    *(char**)(self + 0x90) = e + 0x124;
    *(int*)(self + 0x1D4C) = arg3[13];
    *(unsigned char*)(self + 0x1D54) = 0;
    *(int*)(self + 0x1D5C) = 0x1E;
    *(int*)(self + 0x1D60) = 0xF9F;
    *(int*)(self + 0x1D64) = 0x5DBF;
    *(int*)(self + 0x1D68) = 0;

    char* f = lbl_27_data_8628C;
    *(char**)(self + 0x1D58) = f;
    *(char**)(self + 0x1D50) = f + 8;
    *(int*)(self + 0x1D6C) = *(int*)(self + 0x1D4C);
    fn_27_1D8FC8(self, 0);
    return self;
}
