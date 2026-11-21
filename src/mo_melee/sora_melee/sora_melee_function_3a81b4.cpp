#include <types.h>
#pragma force_active on

class soModuleAccesserBuildData {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2();
    virtual void slot3();
    virtual void* slot4();
    virtual void* slot5();
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
    virtual void slot28();
};

class soNullable {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(void*, int, short*, int);
    virtual void slot4();
    virtual void slot5();
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
    virtual void slot28(void**, int);
};

extern "C" {
extern char g_soParamAccesserNull[];
extern char lbl_27_bss_8B44[];
extern char lbl_27_data_13730[];
extern char lbl_27_data_9DAC8[];
extern char lbl_27_data_9DAF8[];
extern char lbl_27_data_9DD64[];
extern float lbl_27_rodata_7EF0;
extern float lbl_27_rodata_7EF4;

void fn_27_1DC5E8(void*, int, const void*, void*, void*, void*, unsigned char, int,
                  void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_3A8568(void*, void*, void*);
void fn_27_2E2754(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_B7148(void*);
void fn_27_1DC268(void*, int);
void fn_27_1D8FC8(void*, int);
}

static inline soNullable* module(char* p, int offset) {
    return *(soNullable**)(*(char**)(*(char**)(p + 0x60) + 0xd8) + offset);
}

extern "C" void* fn_27_3A81B4(void* arg0, int arg1, void* arg2, const int* arg3) {
    struct ShortSlot {
        short value;
        short padding;
    };

    int out[20];
    float tbl[15];
    ShortSlot s3;
    ShortSlot s2;
    ShortSlot s1;

    char* self = (char*)arg0;
    void* second;
    void* first;
    soModuleAccesserBuildData* data = *(soModuleAccesserBuildData**)((char*)arg2 + 4);
    first = data->slot5();
    second = data->slot4();
    void* third = data->slot2();

    fn_27_1DC5E8(out + 4, 0x8c, arg3, third, second, first, *arg3 & 0xff, 0,
                 g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_9DAC8, out[5], out[6], arg1, arg2, self + 0x8c4, 1);

    char* modules = self + 0xcc;
    char* d = lbl_27_data_9DD64;
    *(char**)(self + 0x3c) = d;
    *(char**)(self + 0x40) = d + 0x64;
    *(char**)(self + 0x48) = d + 0x70;
    *(char**)(self + 0x54) = d + 0x84;
    *(char**)(self + 0x64) = d + 0xdc;
    *(char**)(self + 0x70) = d + 0xec;
    *(char**)(self + 0x7c) = d + 0x100;
    *(char**)(self + 0x88) = d + 0x118;
    *(char**)(self + 0x90) = d + 0x124;
    fn_27_3A8568(modules, self, out + 4);
    fn_27_2E2754(modules + 0x18b0, modules + 0x7f8, out + 4);
    fn_27_1DBA64(self + 0x1f2c);

    struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };

    tbl[12] = lbl_27_rodata_7EF0;
    tbl[9] = lbl_27_rodata_7EF4;
    tbl[13] = lbl_27_rodata_7EF0;
    tbl[14] = lbl_27_rodata_7EF0;
    tbl[10] = lbl_27_rodata_7EF4;
    tbl[11] = lbl_27_rodata_7EF4;
    tbl[6] = lbl_27_rodata_7EF0;
    tbl[7] = lbl_27_rodata_7EF0;
    tbl[8] = lbl_27_rodata_7EF0;
    tbl[3] = lbl_27_rodata_7EF4;
    tbl[4] = lbl_27_rodata_7EF4;
    tbl[5] = lbl_27_rodata_7EF4;
    tbl[0] = lbl_27_rodata_7EF4;
    tbl[1] = lbl_27_rodata_7EF4;
    tbl[2] = lbl_27_rodata_7EF4;
    int* ti = (int*)tbl;

    *(unsigned char*)(self + 0x1f68) = 0;
    ((FlagByte*)(self + 0x1f69))->flag = 1;
    *(unsigned char*)(self + 0x1f6a) = 0;
    *(void**)(self + 0x1f64) = lbl_27_data_13730;
    *(int*)(self + 0x1f6c) = ti[0];
    *(int*)(self + 0x1f70) = ti[1];
    *(int*)(self + 0x1f74) = ti[2];
    *(int*)(self + 0x1f78) = ti[3];
    *(int*)(self + 0x1f7c) = ti[4];
    *(int*)(self + 0x1f80) = ti[5];
    *(int*)(self + 0x1f84) = ti[6];
    *(int*)(self + 0x1f88) = ti[7];
    *(int*)(self + 0x1f8c) = ti[8];
    *(int*)(self + 0x1f90) = ti[9];
    *(int*)(self + 0x1f94) = ti[10];
    *(int*)(self + 0x1f98) = ti[11];
    *(int*)(self + 0x1f9c) = ti[12];
    *(int*)(self + 0x1fa0) = ti[13];
    *(int*)(self + 0x1fa4) = ti[14];
    fn_27_1D90FC(self);

    s1.value = 1;
    module(self, 0x7c)->slot3(self + 0x1f2c, 0, &s1.value, -1);
    s2.value = 1;
    module(self, 0x7c)->slot3(self + 0x1f64, 1, &s2.value, -1);

    char* e = lbl_27_data_9DAF8;
    *(char**)(self + 0x3c) = e;
    *(char**)(self + 0x40) = e + 0x64;
    *(char**)(self + 0x48) = e + 0x70;
    *(char**)(self + 0x54) = e + 0x84;
    *(char**)(self + 0x64) = e + 0xdc;
    *(char**)(self + 0x70) = e + 0xec;
    *(char**)(self + 0x7c) = e + 0x100;
    *(char**)(self + 0x88) = e + 0x118;
    *(char**)(self + 0x90) = e + 0x124;
    fn_27_B7148(self + 0x1fa8);

    ((void**)out)[0] = lbl_27_bss_8B44;
    ((void**)out)[1] = lbl_27_bss_8B44;
    ((void**)out)[2] = lbl_27_bss_8B44;
    module(self, 0x70)->slot28((void**)out, 3);

    s3.value = 8;
    module(self, 0x7c)->slot3(self + 0x1fa8, 2, &s3.value, -1);
    fn_27_1DC268(module(self, 0x7c), 2);
    fn_27_1D8FC8(self, 0);
    return self;
}
