#pragma force_active on

struct A {
    int m0;
    unsigned char pad[0x3C];
    unsigned short m40;
};

extern "C" void fn_8005D4F8(A* arg0, int* arg1, int arg2) {
    *arg1 = *arg1 + arg0->m40;
}
