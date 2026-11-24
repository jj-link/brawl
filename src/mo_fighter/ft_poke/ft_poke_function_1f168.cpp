#pragma force_active on
#pragma optimization_level 1

extern "C" {
void fn_27_1A558C(void*, int);
void fn_27_19F434(void*, int, int);
void* fn_27_1482AC(void*, int, void*);
void fn_116_23F4C(void*, int, void*, void*);
void fn_116_1F318(void*, void*);
void fn_116_1F3AC(void*, void*);
void fn_27_92F10(void*, void*, void*, void*, void*);

extern int lbl_116_data_A488;
extern int lbl_116_data_A78C;
extern int lbl_116_data_A950;
extern int lbl_116_data_AB30;
extern int lbl_116_data_ABC8;
extern int lbl_116_data_AE14;
extern int lbl_116_data_AF80;
extern int lbl_116_data_B010;
extern int lbl_116_data_B0A0;
extern int lbl_116_data_B274;
extern int lbl_116_data_B324;
extern int lbl_116_data_B3B4;
extern unsigned char g_ftCommonDataAccesser;
}

struct Local {
    unsigned char a;
    unsigned char b;
    unsigned char pad[2];
    int c;
    int d;
    int e;
    int f;
    int* g;
    void* h;
};

extern "C" void* fn_116_1F168(char* self, char* arg2) {
    Local local;

    fn_27_1A558C(self, 0);
    fn_27_19F434(self + 0x20, 5, 0);

    char* base = self + 0x7C;
    int zero;
    char* r27;

    void* vt = &lbl_116_data_A488;
    *(void**)base = vt;
    *(void**)(base + 4) = (char*)vt + 0x10;
    *(int*)(base + 8) = (int)&lbl_116_data_B274;
    *(int*)(base + 12) = (int)&lbl_116_data_B324;
    r27 = base + 0x14;
    *(int*)r27 = (int)&lbl_116_data_B3B4;

    zero = 0;
    local.a = zero;
    local.b = zero;
    local.c = zero;
    int value = 0x1F;
    local.d = value;
    void* h = *(void**)(*(char**)(arg2 + 0xD8) + 0xC0);
    local.e = zero;
    local.f = value;
    local.g = &local.e;
    local.h = h;

    fn_116_23F4C(
        r27 + 4,
        2,
        &local.g,
        fn_27_1482AC(&g_ftCommonDataAccesser, value, &local.b)
    );

    *(int*)(base + 8) = (int)&lbl_116_data_AE14;
    r27 = base + 0x1F94;
    *(int*)r27 = (int)&lbl_116_data_AF80;
    *(int*)(r27 + 4) = (int)&lbl_116_data_B010;
    *(int*)(r27 + 8) = (int)&lbl_116_data_B0A0;

    fn_116_1F318(r27 + 0x10, arg2);
    fn_116_1F318(r27 + 0x16BC, arg2);
    fn_116_1F318(r27 + 0x2D68, arg2);

    *(int*)(base + 8) = (int)&lbl_116_data_A950;
    r27 = base + 0x63A8;
    *(int*)r27 = (int)&lbl_116_data_AB30;
    *(int*)(r27 + 4) = (int)&lbl_116_data_ABC8;

    fn_116_1F3AC(r27 + 0xC, arg2);
    fn_116_1F3AC(r27 + 0x1710, arg2);

    *(int*)(base + 8) = (int)&lbl_116_data_A78C;
    *(unsigned char*)(base + 0x91BC) = zero;

    fn_27_92F10(self + 0x923C, arg2, self, base, self + 0x20);
    return self;
}
