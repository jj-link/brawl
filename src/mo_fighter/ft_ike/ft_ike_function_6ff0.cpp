#pragma force_active on
#pragma optimization_level 1
extern "C" {
extern char lbl_119_data_BD0[];
extern char lbl_119_data_D28[];
extern char lbl_119_data_E08[];
extern char lbl_119_data_EB0[];
extern char lbl_119_data_F38[];
extern unsigned char g_ftCommonDataAccesser[];
void fn_27_1A4E70(void* self, int flag);
void fn_27_19EAA4(void* self, int flag, int zero);
void* fn_27_148A88(void* accesser, int, unsigned char* out);
void fn_119_FBC4(void* sub, int index, void* param, void* value);
void fn_27_92F10(void* a, void* accesser, void* self, void* b, void* c);
}
struct Args {
    unsigned char a;
    unsigned char b;
    int c;
    int d;
    int e;
    int f;
    int* g;
    void* h;
};
extern "C" void* fn_119_6FF0(char* self, char* accesser) {
    Args args;
    int zero;
    fn_27_1A4E70(self, 0);
    fn_27_19EAA4(self + 0x10, 1, 0);
    void* vt = lbl_119_data_BD0;
    *(void**)(self + 0x2c) = vt;
    *(void**)(self + 0x30) = (char*)vt + 0x10;
    char* p = self + 0x34;
    *(void**)(self + 0x34) = lbl_119_data_E08;
    *(void**)(self + 0x38) = lbl_119_data_EB0;
    char* q = p + 0xc;
    *(void**)(self + 0x40) = lbl_119_data_F38;
    zero = 0;
    args.a = zero;
    args.b = zero;
    args.c = zero;
    int k = 0x22;
    args.d = k;
    void* value = *(void**)(*(char**)(accesser + 0xd8) + 0xc0);
    args.e = zero;
    args.f = k;
    args.g = &args.e;
    args.h = value;
    fn_119_FBC4(q + 4, 0, &args.g, fn_27_148A88(g_ftCommonDataAccesser, k, &args.b));
    *(void**)p = lbl_119_data_D28;
    *(unsigned char*)(self + 0x2344) = zero;
    fn_27_92F10(self + 0x2348, accesser, self, self + 0x2c, self + 0x10);
    return self;
}
