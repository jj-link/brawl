#pragma force_active on
extern "C" void OSReport(const char*, ...);
extern const char lbl_27_data_17B50[];
extern const char lbl_27_data_17B78[];

struct Obj {
    unsigned char pad[0x14];
    float a;
    float b;
    float c;
    unsigned char rest[0x100];
};

extern "C" void fn_27_C30A4(Obj* p) {
    OSReport(lbl_27_data_17B50, p->b, p->c, p->a);
    OSReport(lbl_27_data_17B78,
             *(int*)((char*)p + 8),
             *(int*)((char*)p + 16),
             *(int*)((char*)p + 12));
}
