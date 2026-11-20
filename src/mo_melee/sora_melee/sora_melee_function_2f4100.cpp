#pragma force_active on
extern "C" {
extern char g_soParamAccesserNull[];
extern char lbl_27_data_13730[];
extern char lbl_27_data_7F808[];
extern char lbl_27_data_7F818[];
extern char lbl_27_data_7FB28[];
extern float lbl_27_rodata_64E0;
extern float lbl_27_rodata_64E4;

void fn_27_1DC5E8(void* buf, int size, const void* a2, unsigned int a3, unsigned int a4, unsigned int a5,
                  unsigned char a6, int a7, void* s8, int s0c, int s10, int s14, int s18, int s1c,
                  int s20, int s24);
void fn_27_1D7EF0(void* self, void* name, unsigned int a, unsigned int b, int c, void* d, void* e, int f);
void* fn_27_2F4454(void* a, void* b, void* c);
void fn_27_2F5D64(void* a, void* b, void* c);
void fn_27_1DBA64(void* self);
void fn_27_1D90FC(void* self);
void fn_27_1D8FC8(void* self, int x);
}

class IVirt {
public:
    virtual void v0();
    virtual void v1();
    virtual int v2();
    virtual void v3(void* a, int b, short* c, int d);
    virtual int v4();
    virtual int v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28(int* a, int b);
};

struct SoD8 {
    char pad0[0x70];
    IVirt* p70;
    char pad1[8];
    IVirt* p7c;
};

struct SoP60 {
    char pad0[0xd8];
    SoD8* d8;
};

struct BuildBuf {
    void* unk0;
    int unk4;
    int unk8;
    unsigned char unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

struct F15 {
    float v[15];
};

extern "C" void* fn_27_2F4100(void* arg0, int arg1, void* arg2, const int* arg3)
{
    unsigned char* self = (unsigned char*)arg0;
    int r23;
    int r24;
    int r6;
    IVirt* obj = *(IVirt**)((unsigned char*)arg2 + 4);
    r24 = obj->v5();
    r23 = obj->v4();
    r6 = obj->v2();

    BuildBuf buf;
    fn_27_1DC5E8(&buf, 0x58, arg3, r6, r23, r24, (unsigned char)*arg3, 0,
                 g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(arg0, lbl_27_data_7F808, buf.unk4, buf.unk8, arg1, arg2, self + 0x550, 1);

    unsigned char* sub = self + 0xcc;
    char* v1 = lbl_27_data_7FB28;
    *(char**)(self + 0x3c) = v1;
    *(char**)(self + 0x40) = v1 + 0x64;
    *(char**)(self + 0x48) = v1 + 0x70;
    *(char**)(self + 0x54) = v1 + 0x84;
    *(char**)(self + 0x64) = v1 + 0xdc;
    *(char**)(self + 0x70) = v1 + 0xec;
    *(char**)(self + 0x7c) = v1 + 0x100;
    *(char**)(self + 0x88) = v1 + 0x118;
    *(char**)(self + 0x90) = v1 + 0x124;

    fn_27_2F4454(sub, arg0, &buf);
    fn_27_2F5D64(sub + 0x1394, sub + 0x484, &buf);
    fn_27_1DBA64(self + 0x17b8);

    float tbl[15];
    tbl[12] = lbl_27_rodata_64E0;
    tbl[9] = lbl_27_rodata_64E4;
    tbl[13] = lbl_27_rodata_64E0;
    tbl[14] = lbl_27_rodata_64E0;
    tbl[10] = lbl_27_rodata_64E4;
    tbl[11] = lbl_27_rodata_64E4;
    tbl[6] = lbl_27_rodata_64E0;
    tbl[7] = lbl_27_rodata_64E0;
    tbl[8] = lbl_27_rodata_64E0;
    tbl[3] = lbl_27_rodata_64E4;
    tbl[4] = lbl_27_rodata_64E4;
    tbl[5] = lbl_27_rodata_64E4;
    tbl[0] = lbl_27_rodata_64E4;
    tbl[1] = lbl_27_rodata_64E4;
    tbl[2] = lbl_27_rodata_64E4;
    struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };
    self[0x17f4] = 0;
    ((FlagByte*)(self + 0x17f5))->flag = 1;
    self[0x17f6] = 0;
    *(void**)(self + 0x17f0) = lbl_27_data_13730;
    *(F15*)(self + 0x17f8) = *(F15*)tbl;
    fn_27_1D90FC(arg0);

    struct Slots { short a; short pad1; short b; short pad2; int c; } slots;
    slots.a = 1;
    IVirt* o = ((SoP60*)*(char**)(self + 0x60))->d8->p7c;
    o->v3(self + 0x17b8, 0, &slots.a, -1);
    slots.b = 1;
    o = ((SoP60*)*(char**)(self + 0x60))->d8->p7c;
    o->v3(self + 0x17f0, 1, &slots.b, -1);

    char* v2 = lbl_27_data_7F818;
    *(char**)(self + 0x3c) = v2;
    *(char**)(self + 0x40) = v2 + 0x64;
    *(char**)(self + 0x48) = v2 + 0x70;
    *(char**)(self + 0x54) = v2 + 0x84;
    *(char**)(self + 0x64) = v2 + 0xdc;
    *(char**)(self + 0x70) = v2 + 0xec;
    *(char**)(self + 0x7c) = v2 + 0x100;
    *(char**)(self + 0x88) = v2 + 0x118;
    *(char**)(self + 0x90) = v2 + 0x124;

    slots.c = 0;
    IVirt* q = ((SoP60*)*(char**)(self + 0x60))->d8->p70;
    q->v28(&slots.c, 1);

    fn_27_1D8FC8(arg0, 0);
    return arg0;
}