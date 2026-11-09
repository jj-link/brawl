#pragma force_active on
#pragma optimization_level 1
extern "C" {
extern char lbl_110_data_96A4[];
extern char lbl_110_data_981C[];
extern char lbl_110_data_98FC[];
extern char lbl_110_data_99A4[];
extern char lbl_110_data_9A2C[];
extern unsigned char g_ftCommonDataAccesser[];
void fn_27_1A558C(void* self, int flag);
void fn_27_19F434(void* array, int count, int size);
void* fn_27_14948C(void* accesser, int, unsigned char* out);
void fn_110_F17C(void* sub, int index, void* param, void* value);
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

extern "C" void* fn_110_1EE68(char* self, char* accesser) {
    Args args;
    int zero;
    fn_27_1A558C(self, 0);
    fn_27_19F434(self + 0x20, 5, 0);
    void* vt = lbl_110_data_96A4;
    *(void**)(self + 0x7c) = vt;
    *(void**)(self + 0x80) = (char*)vt + 0x10;
    char* p = self + 0x84;
    *(void**)(self + 0x84) = lbl_110_data_98FC;
    *(void**)(self + 0x88) = lbl_110_data_99A4;
    char* q = p + 0xc;
    *(void**)(self + 0x90) = lbl_110_data_9A2C;
    zero = 0;
    args.a = zero;
    args.b = zero;
    args.c = zero;
    int k = 0x31;
    args.d = k;
    void* value = *(void**)(*(char**)(accesser + 0xd8) + 0xc0);
    args.e = zero;
    args.f = k;
    args.g = &args.e;
    args.h = value;
    fn_110_F17C(q + 4, 0, &args.g, fn_27_14948C(g_ftCommonDataAccesser, k, &args.b));
    *(void**)p = lbl_110_data_981C;
    *(unsigned char*)(self + 0x2adc) = zero;
    fn_27_92F10(self + 0x2ae0, accesser, self, self + 0x7c, self + 0x20);
    return self;
}
