#pragma force_active on
#pragma optimization_level 1
extern "C" {
extern char lbl_111_data_B10[];
extern char lbl_111_data_D7C[];
extern char lbl_111_data_E2C[];
extern char lbl_111_data_EBC[];
extern char lbl_111_data_C94[];
extern unsigned char g_ftCommonDataAccesser[];
void fn_27_1A558C(void* self, int flag);
void fn_27_19F434(void* array, int count, int size);
void* fn_27_1496A8(void* accesser, int, unsigned char* out);
void fn_111_DD64(void* sub, int index, void* param, void* value);
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
extern "C" void* fn_111_75A8(char* self, char* accesser) {
    Args args;
    int zero;
    fn_27_1A558C(self, 0);
    fn_27_19F434(self + 0x20, 5, 0);
    void* vt = lbl_111_data_B10;
    *(void**)(self + 0x7c) = vt;
    *(void**)(self + 0x80) = (char*)vt + 0x10;
    char* p = self + 0x84;
    *(void**)(self + 0x84) = lbl_111_data_D7C;
    *(void**)(self + 0x88) = lbl_111_data_E2C;
    char* q = p + 0xc;
    *(void**)(self + 0x90) = lbl_111_data_EBC;
    zero = 0;
    args.a = zero;
    args.b = zero;
    args.c = zero;
    int k = 0x16;
    args.d = k;
    void* value = *(void**)(*(char**)(accesser + 0xd8) + 0xc0);
    args.e = zero;
    args.f = k;
    args.g = &args.e;
    args.h = value;
    fn_111_DD64(q + 4, 0, &args.g, fn_27_1496A8(g_ftCommonDataAccesser, k, &args.b));
    *(void**)p = lbl_111_data_C94;
    *(unsigned char*)(self + 0x2138) = zero;
    fn_27_92F10(self + 0x213c, accesser, self, self + 0x7c, self + 0x20);
    return self;
}
