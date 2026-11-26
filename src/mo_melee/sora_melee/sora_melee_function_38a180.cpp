#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    virtual void slot3(void*, int, short*, int);
    virtual int slot4();
    virtual int slot5();
};

extern "C" {
extern char lbl_27_data_13730[];
extern char lbl_27_data_99588[];
extern char lbl_27_data_995A0[];
extern char lbl_27_data_9980C[];
extern char lbl_27_data_99A78[];
extern char lbl_27_data_99B38[];
extern char lbl_27_data_99D98[];
extern float lbl_27_rodata_7D10;
extern float lbl_27_rodata_7D14;

void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int,
                  void*, void*, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_1D8FC8(void*, int);
void fn_27_1D90FC(void*);
void fn_27_1DBA64(void*);
void fn_27_38A8D0(void*, void*, void*);
void fn_27_38BDF4(void*, void*, void*);
}

struct F15 {
    float v[15];
};

extern "C" void* fn_27_38A180(void* arg0, int arg1, void* arg2, const int* arg3) {
    struct ShortSlot {
        short value;
        short padding;
    };

    ShortSlot sp2c;
    ShortSlot sp28;
    void* spb0[7];
    int params[16];
    float tbl[15];

    char* self = (char*)arg0;
    int t15;
    int t16;
    Object_vptr_0* obj = *(Object_vptr_0**)((char*)arg2 + 4);
    t16 = obj->slot5();
    t15 = obj->slot4();
    int t6 = obj->slot2();

    fn_27_1DC5E8(params, 0x10, arg3, t6, t15, t16,
                 *arg3 & 0xff, -1, self + 0x17dc, (char*)arg3 + 0x38,
                 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_99588, params[1], params[2],
                 arg1, arg2, self + 0x538, 1);

    char* modules = self + 0xcc;
    char* p = lbl_27_data_9980C;
    *(void**)(self + 0x3c) = p;
    *(void**)(self + 0x40) = p + 0x64;
    *(void**)(self + 0x48) = p + 0x70;
    *(void**)(self + 0x54) = p + 0x84;
    *(void**)(self + 0x64) = p + 0xdc;
    *(void**)(self + 0x70) = p + 0xec;
    *(void**)(self + 0x7c) = p + 0x100;
    *(void**)(self + 0x88) = p + 0x118;
    *(void**)(self + 0x90) = p + 0x124;
    fn_27_38A8D0(modules, self, params);
    fn_27_38BDF4(modules + 0x1358, modules + 0x46c, params);
    fn_27_1DBA64(self + 0x175c);

    tbl[12] = lbl_27_rodata_7D10;
    tbl[9] = lbl_27_rodata_7D14;
    tbl[13] = lbl_27_rodata_7D10;
    tbl[14] = lbl_27_rodata_7D10;
    tbl[10] = lbl_27_rodata_7D14;
    tbl[11] = lbl_27_rodata_7D14;
    tbl[6] = lbl_27_rodata_7D10;
    tbl[7] = lbl_27_rodata_7D10;
    tbl[8] = lbl_27_rodata_7D10;
    tbl[3] = lbl_27_rodata_7D14;
    tbl[4] = lbl_27_rodata_7D14;
    tbl[5] = lbl_27_rodata_7D14;
    tbl[0] = lbl_27_rodata_7D14;
    tbl[1] = lbl_27_rodata_7D14;
    tbl[2] = lbl_27_rodata_7D14;

    struct FlagByte {
        unsigned char flag : 1;
        unsigned char rest : 7;
    };

    self[0x1798] = 0;
    ((FlagByte*)(self + 0x1799))->flag = 1;
    self[0x179a] = 0;
    *(void**)(self + 0x1794) = lbl_27_data_13730;
    *(F15*)(self + 0x179c) = *(F15*)tbl;
    fn_27_1D90FC(self);

    sp28.value = 1;
    Object_vptr_0* o = *(Object_vptr_0**)(
        *(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c);
    o->slot3(self + 0x175c, 0, &sp28.value, -1);

    sp2c.value = 1;
    o = *(Object_vptr_0**)(
        *(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c);
    o->slot3(self + 0x1794, 1, &sp2c.value, -1);

    char* q = lbl_27_data_995A0;
    *(void**)(self + 0x3c) = q;
    *(void**)(self + 0x40) = q + 0x64;
    *(void**)(self + 0x48) = q + 0x70;
    *(void**)(self + 0x54) = q + 0x84;
    *(void**)(self + 0x64) = q + 0xdc;
    *(void**)(self + 0x70) = q + 0xec;
    *(void**)(self + 0x7c) = q + 0x100;
    *(void**)(self + 0x88) = q + 0x118;
    *(void**)(self + 0x90) = q + 0x124;

    char* r23 = (*(char**)(self + 0x17d8) = *(char**)((char*)arg3 + 0x34));
    self[0x17e0] = 0;
    *(int*)(self + 0x17e8) = 0x10;
    *(int*)(self + 0x17ec) = 0xf9f;
    *(int*)(self + 0x17f0) = 0x5dbf;
    *(int*)(self + 0x17f4) = 0;
    *(void**)(self + 0x17e4) = lbl_27_data_99A78;
    *(void**)(self + 0x17dc) = lbl_27_data_99A78 + 8;
    *(void**)(self + 0x17f8) = r23 + 0x14;
    *(void**)(self + 0x17fc) = r23 + 0x18;
    *(void**)(self + 0x1800) = r23 + 0x1c;
    *(void**)(self + 0x1804) = r23 + 0x20;
    *(void**)(self + 0x1808) = r23 + 0x24;
    *(void**)(self + 0x180c) = r23 + 0x28;
    *(void**)(self + 0x1810) = r23 + 0x2c;
    *(void**)(self + 0x1814) = r23 + 0x38;
    *(void**)(self + 0x1818) = r23 + 0x3c;
    *(void**)(self + 0x1820) = r23;
    *(void**)(self + 0x1824) = r23 + 4;

    spb0[0] = r23 + 8;
    spb0[1] = r23 + 0xc;
    spb0[2] = r23 + 0x10;
    spb0[3] = r23 + 0x30;
    spb0[4] = r23 + 0x34;
    *(void**)(self + 0x1828) = spb0[0];
    *(void**)(self + 0x182c) = spb0[1];
    *(void**)(self + 0x1830) = spb0[2];
    *(void**)(self + 0x1834) = spb0[3];
    *(void**)(self + 0x1838) = spb0[4];

    *(void**)(self + 0x1844) = lbl_27_data_99D98;
    *(void**)(self + 0x1848) = lbl_27_data_99D98 + 0x48;
    *(unsigned int*)(self + 0x184c) &= 0x3fffff;
    *(void**)(self + 0x18c8) = lbl_27_data_99B38;
    *(void**)(self + 0x18cc) = lbl_27_data_99B38 + 0x48;
    *(unsigned int*)(self + 0x18d0) &= 0x3fffff;

    fn_27_1D8FC8(self, 0);
    return arg0;
}
