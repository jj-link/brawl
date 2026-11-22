#pragma force_active on
extern "C" {
int fn_80196B1C(int*);
int fn_80196CD0(int*);
int fn_80196DFC(int*);
int fn_80196FD4(int*);
void* fn_80204E5C(void*, unsigned int);
void* fn_8019CBAC(void*, void*, int*, void*, void*, void*, void*);
}
extern "C" void* fn_8019CA18(void* arg0, unsigned int* arg1, int* arg2, int arg3) {
    int s25, s24, s23, s26, s27, s22, s28;
    int e;
    if (*arg2 == 0) return 0;
    if (arg3) s26 = fn_80196B1C(arg2); else s26 = 0;
    if (arg3) s27 = fn_80196CD0(arg2); else s27 = 0;
    if (arg3) s28 = fn_80196DFC(arg2); else s28 = 0;
    if (arg3) e = fn_80196FD4(arg2); else e = 0;
    s25 = s26 * 8;
    s24 = s27 << 6;
    s23 = s28 * 0x10;
    s26 = (s25 + 0x3B) & ~3;
    s27 = (s26 + s24 + 3) & ~3;
    s22 = e * 0x34;
    s28 = (s27 + s23 + 3) & ~3;
    unsigned int s4 = (s28 + s22 + 3) & ~3;
    if (arg1) *arg1 = s4;
    if (!arg0) return 0;
    char* r3 = (char*)fn_80204E5C(arg0, s4);
    if (!r3) return 0;
    if (r3) {
        void* v9 = s22 ? r3 + s28 : 0;
        void* v8 = s23 ? r3 + s27 : 0;
        void* v7 = s24 ? r3 + s26 : 0;
        void* v6 = s25 ? r3 + 0x38 : 0;
        int sp8 = *arg2;
        return fn_8019CBAC(r3, arg0, &sp8, v6, v7, v8, v9);
    }
    return r3;
}