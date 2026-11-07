#pragma force_active on
#pragma optimization_level 1
extern "C" {
extern char lbl_99_data_ADC[];
extern char lbl_99_data_11F4[];
extern char lbl_99_data_12A4[];
extern char lbl_99_data_1334[];
extern char lbl_99_data_E3C[];
extern char lbl_99_data_FA0[];
extern char lbl_99_data_102C[];
extern char lbl_99_data_CF0[];
extern unsigned char g_ftCommonDataAccesser[];
void fn_27_1A558C(void* self, int flag);
void fn_27_19F434(void* array, int count, int size);
void fn_99_7934(void* sub, void* accesser);
void* fn_27_148E3C(void* accesser, int, unsigned char* out);
void fn_99_D428(void* sub, int index, void* param, void* value);
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

extern "C" void* fn_99_77E8(char* self, char* accesser) {
    Args args;
    int zero;
    fn_27_1A558C(self, 0);
    fn_27_19F434(self + 0x20, 5, 0);
    void* vt = lbl_99_data_ADC;
    *(void**)(self + 0x7c) = vt;
    *(void**)(self + 0x80) = (char*)vt + 0x10;
    char* p = self + 0x84;
    *(void**)(self + 0x84) = lbl_99_data_11F4;
    *(void**)(self + 0x88) = lbl_99_data_12A4;
    char* q = p + 0xc;
    *(void**)(self + 0x90) = lbl_99_data_1334;
    zero = 0;
    args.a = zero;
    args.b = zero;
    args.c = zero;
    int k = 8;
    args.d = k;
    void* value = *(void**)(*(char**)(accesser + 0xd8) + 0xc0);
    args.e = zero;
    args.f = k;
    args.g = &args.e;
    args.h = value;
    fn_99_D428(q + 4, 1, &args.g, fn_27_148E3C(g_ftCommonDataAccesser, k, &args.b));
    *(void**)p = lbl_99_data_E3C;
    *(void**)(p + 0x20a0) = lbl_99_data_FA0;
    *(void**)(p + 0x20a4) = lbl_99_data_102C;
    fn_99_7934(p + 0x20ac, accesser);
    fn_99_7934(p + 0x3ff4, accesser);
    *(void**)p = lbl_99_data_CF0;
    *(unsigned char*)(self + 0x5fc0) = zero;
    fn_27_92F10(self + 0x5fc4, accesser, self, self + 0x7c, self + 0x20);
    return self;
}
