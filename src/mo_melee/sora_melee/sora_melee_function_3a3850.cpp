#pragma force_active on
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual unsigned int slot2();
    virtual void slot3(void* a, int b, void* c, int d);
    virtual unsigned int slot4();
    virtual unsigned int slot5();
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
    virtual void slot28(void* a, int b);
};

struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };

#define SET_PTR(base, off, val) (*reinterpret_cast<unsigned char**>(reinterpret_cast<unsigned char*>(base) + (off)) = reinterpret_cast<unsigned char*>(val))
#define MOD_D8(self) (*reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(reinterpret_cast<unsigned char*>(self) + 0x60) + 0xD8))
#define SUB_AT(self, off) (*reinterpret_cast<soNullable**>(MOD_D8(self) + (off)))
#define COPY_WORD(dst, src) (*reinterpret_cast<unsigned int*>(dst) = *reinterpret_cast<unsigned int*>(&(src)))

extern "C" {
extern unsigned char g_soParamAccesserNull[];
extern unsigned char lbl_27_bss_8A8C[];
extern unsigned char lbl_27_data_13730[];
extern unsigned char lbl_27_data_9CB60[];
extern unsigned char lbl_27_data_9CB6C[];
extern unsigned char lbl_27_data_9CDD8[];
extern const float lbl_27_rodata_7EA8;
extern const float lbl_27_rodata_7EAC;

void fn_27_1DC5E8(void*, int, const void*, unsigned int, unsigned int, unsigned int, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, unsigned int, unsigned int, int, void*, void*, int);
void fn_27_1D8FC8(void*, int);
void fn_27_1D90FC(void*);
void fn_27_1DBA64(void*);
void fn_27_3097BC(void*, void*, void*);
void fn_27_3A3BB4(void*, void*, void*);
}

extern "C" void* fn_27_3A3850(unsigned char* self, int owner, void* resource, const int* parameters) {
    unsigned int resourceB;
    unsigned int resourceC;
    soNullable* ids = *reinterpret_cast<soNullable**>(reinterpret_cast<unsigned char*>(resource) + 4);
    resourceC = ids->slot5();
    resourceB = ids->slot4();
    unsigned int resourceA = ids->slot2();

    unsigned char descriptor[64];
    fn_27_1DC5E8(descriptor, 0x2E, parameters, resourceA, resourceB, resourceC,
                 (unsigned char)(*parameters & 0xff), -1,
                 g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_9CB60, *reinterpret_cast<unsigned int*>(descriptor + 4),
                 *reinterpret_cast<unsigned int*>(descriptor + 8), owner, resource, self + 0x8C4, 1);

    unsigned char* modules = self + 0xCC;
    SET_PTR(self, 0x3C, lbl_27_data_9CDD8);
    SET_PTR(self, 0x40, lbl_27_data_9CDD8 + 0x64);
    SET_PTR(self, 0x48, lbl_27_data_9CDD8 + 0x70);
    SET_PTR(self, 0x54, lbl_27_data_9CDD8 + 0x84);
    SET_PTR(self, 0x64, lbl_27_data_9CDD8 + 0xDC);
    SET_PTR(self, 0x70, lbl_27_data_9CDD8 + 0xEC);
    SET_PTR(self, 0x7C, lbl_27_data_9CDD8 + 0x100);
    SET_PTR(self, 0x88, lbl_27_data_9CDD8 + 0x118);
    SET_PTR(self, 0x90, lbl_27_data_9CDD8 + 0x124);

    fn_27_3A3BB4(modules, self, descriptor);
    fn_27_3097BC(modules + 0x1924, modules + 0x7F8, descriptor);
    fn_27_1DBA64(self + 0x1FA0);

    float tbl[15];
    tbl[12] = lbl_27_rodata_7EA8;
    tbl[9] = lbl_27_rodata_7EAC;
    tbl[13] = lbl_27_rodata_7EA8;
    tbl[14] = lbl_27_rodata_7EA8;
    tbl[10] = lbl_27_rodata_7EAC;
    tbl[11] = lbl_27_rodata_7EAC;
    tbl[6] = lbl_27_rodata_7EA8;
    tbl[7] = lbl_27_rodata_7EA8;
    tbl[8] = lbl_27_rodata_7EA8;
    tbl[3] = lbl_27_rodata_7EAC;
    tbl[4] = lbl_27_rodata_7EAC;
    tbl[5] = lbl_27_rodata_7EAC;
    tbl[0] = lbl_27_rodata_7EAC;
    tbl[1] = lbl_27_rodata_7EAC;
    tbl[2] = lbl_27_rodata_7EAC;

    self[0x1FDC] = 0;
    ((FlagByte*)(self + 0x1FDD))->flag = 1;
    self[0x1FDE] = 0;
    SET_PTR(self, 0x1FD8, lbl_27_data_13730);
    COPY_WORD(self + 0x1FE0, tbl[0]);
    COPY_WORD(self + 0x1FE4, tbl[1]);
    COPY_WORD(self + 0x1FE8, tbl[2]);
    COPY_WORD(self + 0x1FEC, tbl[3]);
    COPY_WORD(self + 0x1FF0, tbl[4]);
    COPY_WORD(self + 0x1FF4, tbl[5]);
    COPY_WORD(self + 0x1FF8, tbl[6]);
    COPY_WORD(self + 0x1FFC, tbl[7]);
    COPY_WORD(self + 0x2000, tbl[8]);
    COPY_WORD(self + 0x2004, tbl[9]);
    COPY_WORD(self + 0x2008, tbl[10]);
    COPY_WORD(self + 0x200C, tbl[11]);
    COPY_WORD(self + 0x2010, tbl[12]);
    COPY_WORD(self + 0x2014, tbl[13]);
    COPY_WORD(self + 0x2018, tbl[14]);

    fn_27_1D90FC(self);

    struct ShortSlot { short n; short pad; };
    void* ptr;
    ShortSlot s2c;
    ShortSlot s28;
    s28.n = 1;
    SUB_AT(self, 0x7C)->slot3(self + 0x1FA0, 0, &s28.n, -1);
    s2c.n = 1;
    SUB_AT(self, 0x7C)->slot3(self + 0x1FD8, 1, &s2c.n, -1);

    SET_PTR(self, 0x3C, lbl_27_data_9CB6C);
    SET_PTR(self, 0x40, lbl_27_data_9CB6C + 0x64);
    SET_PTR(self, 0x48, lbl_27_data_9CB6C + 0x70);
    SET_PTR(self, 0x54, lbl_27_data_9CB6C + 0x84);
    SET_PTR(self, 0x64, lbl_27_data_9CB6C + 0xDC);
    SET_PTR(self, 0x70, lbl_27_data_9CB6C + 0xEC);
    SET_PTR(self, 0x7C, lbl_27_data_9CB6C + 0x100);
    SET_PTR(self, 0x88, lbl_27_data_9CB6C + 0x118);
    SET_PTR(self, 0x90, lbl_27_data_9CB6C + 0x124);
    *reinterpret_cast<int*>(self + 0x201C) = parameters[13];

    ptr = lbl_27_bss_8A8C;
    SUB_AT(self, 0x70)->slot28(&ptr, 1);

    fn_27_1D8FC8(self, 0);
    return self;
}
