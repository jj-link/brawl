#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    virtual void slot3(void*, int, short*, int);
    virtual int slot4();
    virtual int slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28(void*, int);
};
extern "C" {
extern char g_soParamAccesserNull[];
extern char lbl_27_bss_7494[];
extern char lbl_27_data_13730[];
extern char lbl_27_data_7CB08[];
extern char lbl_27_data_7CB38[];
extern char lbl_27_data_7CDA4[];
extern float lbl_27_rodata_63B8;
extern float lbl_27_rodata_63BC;
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int,
                  void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_1D8FC8(void*, int);
void fn_27_1D90FC(void*);
void fn_27_1DBA64(void*);
void fn_27_1DC268(void*, int);
void fn_27_2E12D8(void*, void*, void*);
void fn_27_2E2754(void*, void*, void*);
void fn_27_B7148(void*);
}
struct F15 { float v[15]; };
extern "C" void* fn_27_2E0F24(void* arg0, int arg1, void* arg2, const int* arg3) {
    struct ShortSlot { short value; short padding; };
    ShortSlot sp30;
    ShortSlot sp2c;
    ShortSlot sp28;
    struct Buff { void* sp70[3]; int pad; int params[16]; } buf;
    float tbl[15];

    char* self = (char*)arg0;
    int t23;
    int t24;
    Object_vptr_0* obj = *(Object_vptr_0**)((char*)arg2 + 4);
    t24 = obj->slot5();
    t23 = obj->slot4();
    int t6 = obj->slot2();

    fn_27_1DC5E8(buf.params, 5, arg3, t6, t23, t24,
                 *arg3 & 0xff, 0, g_soParamAccesserNull,
                 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_7CB08, buf.params[1], buf.params[2],
                 arg1, arg2, self + 0x8c4, 1);

    char* modules = self + 0xcc;
    char* p = lbl_27_data_7CDA4;
    *(void**)(self + 0x3c) = p;
    *(void**)(self + 0x40) = p + 0x64;
    *(void**)(self + 0x48) = p + 0x70;
    *(void**)(self + 0x54) = p + 0x84;
    *(void**)(self + 0x64) = p + 0xdc;
    *(void**)(self + 0x70) = p + 0xec;
    *(void**)(self + 0x7c) = p + 0x100;
    *(void**)(self + 0x88) = p + 0x118;
    *(void**)(self + 0x90) = p + 0x124;
    fn_27_2E12D8(modules, self, buf.params);
    fn_27_2E2754(modules + 0x18b0, modules + 0x7f8, buf.params);
    fn_27_1DBA64(self + 0x1f2c);

    tbl[12] = lbl_27_rodata_63B8;
    tbl[9] = lbl_27_rodata_63BC;
    tbl[13] = lbl_27_rodata_63B8;
    tbl[14] = lbl_27_rodata_63B8;
    tbl[10] = lbl_27_rodata_63BC;
    tbl[11] = lbl_27_rodata_63BC;
    tbl[6] = lbl_27_rodata_63B8;
    tbl[7] = lbl_27_rodata_63B8;
    tbl[8] = lbl_27_rodata_63B8;
    tbl[3] = lbl_27_rodata_63BC;
    tbl[4] = lbl_27_rodata_63BC;
    tbl[5] = lbl_27_rodata_63BC;
    tbl[0] = lbl_27_rodata_63BC;
    tbl[1] = lbl_27_rodata_63BC;
    tbl[2] = lbl_27_rodata_63BC;
    struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };
    self[0x1f68] = 0;
    ((FlagByte*)(self + 0x1f69))->flag = 1;
    self[0x1f6a] = 0;
    *(void**)(self + 0x1f64) = lbl_27_data_13730;
    *(F15*)(self + 0x1f6c) = *(F15*)tbl;
    fn_27_1D90FC(self);

    sp28.value = 1;
    Object_vptr_0* o = *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c);
    o->slot3(self + 0x1f2c, 0, &sp28.value, -1);
    sp2c.value = 1;
    o = *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c);
    o->slot3(self + 0x1f64, 1, &sp2c.value, -1);

    char* q = lbl_27_data_7CB38;
    *(void**)(self + 0x3c) = q;
    *(void**)(self + 0x40) = q + 0x64;
    *(void**)(self + 0x48) = q + 0x70;
    *(void**)(self + 0x54) = q + 0x84;
    *(void**)(self + 0x64) = q + 0xdc;
    *(void**)(self + 0x70) = q + 0xec;
    *(void**)(self + 0x7c) = q + 0x100;
    *(void**)(self + 0x88) = q + 0x118;
    *(void**)(self + 0x90) = q + 0x124;
    fn_27_B7148(self + 0x1fa8);
    buf.sp70[0] = lbl_27_bss_7494;
    buf.sp70[1] = lbl_27_bss_7494;
    buf.sp70[2] = lbl_27_bss_7494;
    o = *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70);
    o->slot28(buf.sp70, 3);
    sp30.value = 8;
    o = *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c);
    o->slot3(self + 0x1fa8, 2, &sp30.value, -1);
    o = *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c);
    fn_27_1DC268(o, 2);
    fn_27_1D8FC8(self, 0);
    return arg0;
}