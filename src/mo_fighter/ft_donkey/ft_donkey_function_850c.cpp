#pragma force_active on
#pragma optimization_level 1
extern "C" {
extern char lbl_92_data_AE4[];
extern char lbl_92_data_119C[];
extern char lbl_92_data_124C[];
extern char lbl_92_data_12DC[];
extern char lbl_92_data_136C[];
extern char lbl_92_data_13FC[];
extern char lbl_92_data_E64[];
extern char lbl_92_data_FCC[];
extern char lbl_92_data_105C[];
extern char lbl_92_data_D14[];
extern unsigned char g_ftCommonDataAccesser[];

void fn_27_1A558C(void* self, int flag);
void fn_27_19F434(void* array, int count, int size);
void fn_92_8698(void* sub, void* accesser);
void* fn_27_14981C(void* accesser, int, unsigned char* out);
void fn_92_10324(void* sub, int index, void* param, void* value);
void fn_27_92F10(void* a, void* accesser, void* self, void* b, void* c);
}

struct Fn92Args {
    unsigned char a;
    unsigned char b;
    int c;
    int d;
    int e;
    int f;
    int* g;
    void* h;
};

extern "C" void* fn_92_850C(char* self, char* accesser) {
    Fn92Args args;
    char* p;
    char* base;
    fn_27_1A558C(self, 0);
    fn_27_19F434(self + 0x20, 5, 0);
    base = self + 0x7c;
    void* vt = lbl_92_data_AE4;
    *(void**)(self + 0x7c) = vt;
    *(void**)(self + 0x80) = (char*)vt + 0x10;
    *(void**)(self + 0x84) = lbl_92_data_119C;
    p = base + 0xc;
    *(void**)(self + 0x88) = lbl_92_data_124C;
    *(void**)(self + 0x8c) = lbl_92_data_12DC;
    char* q = p + 0x8;
    *(void**)(self + 0x90) = lbl_92_data_136C;
    *(void**)(self + 0x94) = lbl_92_data_13FC;
    fn_92_8698(q + 0xc, accesser);
    fn_92_8698(q + 0x1fdc, accesser);
    fn_92_8698(p + 0x3fb4, accesser);
    fn_92_8698(p + 0x5f84, accesser);
    *(void**)(base + 0x8) = lbl_92_data_E64;
    *(void**)(base + 0x7f60) = lbl_92_data_FCC;
    char* r = base + 0x7f68;
    *(void**)(base + 0x7f68) = lbl_92_data_105C;
    int zero = 0;
    args.a = zero;
    args.b = zero;
    args.c = zero;
    int one = 1;
    args.d = one;
    void* value = *(void**)(*(char**)(accesser + 0xd8) + 0xc0);
    args.e = zero;
    args.f = one;
    args.g = &args.e;
    args.h = value;
    fn_92_10324(r + 4, 0, &args.g, fn_27_14981C(g_ftCommonDataAccesser, one, &args.b));
    *(void**)(base + 0x8) = lbl_92_data_D14;
    *(unsigned char*)(base + 0x9ff4) = zero;
    fn_27_92F10(self + 0xa074, accesser, self, base, self + 0x20);
    return self;
}
