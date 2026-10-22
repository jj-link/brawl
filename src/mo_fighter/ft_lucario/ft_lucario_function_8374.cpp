#pragma force_active on
#pragma optimization_level 1
extern "C" {
extern char lbl_118_data_B04[];
extern char lbl_118_data_1294[];
extern char lbl_118_data_1340[];
extern char lbl_118_data_13CC[];
extern char lbl_118_data_E50[];
extern char lbl_118_data_FB4[];
extern char lbl_118_data_1040[];
extern char lbl_118_data_10CC[];
extern char lbl_118_data_D04[];
extern unsigned char g_ftCommonDataAccesser[];
void fn_27_1A558C(void* self, int flag);
void fn_27_19F434(void* array, int count, int size);
void fn_118_84DC(void* sub, void* accesser);
void* fn_27_149588(void* accesser, int, unsigned char* out);
void fn_118_1185C(void* sub, int index, void* param, void* value);
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

extern "C" void* fn_118_8374(char* self, char* accesser) {
    Args args;
    int zero;
    fn_27_1A558C(self, 0);
    fn_27_19F434(self + 0x20, 5, 0);
    void* vt = lbl_118_data_B04;
    *(void**)(self + 0x7c) = vt;
    *(void**)(self + 0x80) = (char*)vt + 0x10;
    char* p = self + 0x84;
    *(void**)(self + 0x84) = lbl_118_data_1294;
    *(void**)(self + 0x88) = lbl_118_data_1340;
    char* q = p + 0xc;
    *(void**)(self + 0x90) = lbl_118_data_13CC;
    zero = 0;
    args.a = zero;
    args.b = zero;
    args.c = zero;
    int k = 0x21;
    args.d = k;
    void* value = *(void**)(*(char**)(accesser + 0xd8) + 0xc0);
    args.e = zero;
    args.f = k;
    args.g = &args.e;
    args.h = value;
    fn_118_1185C(q + 4, 1, &args.g, fn_27_149588(g_ftCommonDataAccesser, k, &args.b));
    *(void**)p = lbl_118_data_E50;
    *(void**)(p + 0x1e4c) = lbl_118_data_FB4;
    char* r = p + 0x1e50;
    *(void**)(p + 0x1e50) = lbl_118_data_1040;
    *(void**)(p + 0x1e54) = lbl_118_data_10CC;
    fn_118_84DC(r + 0xc, accesser);
    fn_118_84DC(r + 0x2060, accesser);
    fn_118_84DC(p + 0x5f04, accesser);
    *(void**)p = lbl_118_data_D04;
    *(unsigned char*)(self + 0x7fdc) = zero;
    fn_27_92F10(self + 0x7fe0, accesser, self, self + 0x7c, self + 0x20);
    return self;
}
