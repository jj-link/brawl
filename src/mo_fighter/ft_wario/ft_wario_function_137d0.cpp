#pragma force_active on
extern "C" void fn_110_14BF8(void* a, void* b);

struct Flags {
    unsigned char pad[5];
    unsigned char f : 1;
    unsigned char g : 7;
    unsigned char h;
};

extern "C" int fn_110_137D0(void* a, void* b, void* c) {
    Flags* p = (Flags*)b;
    bool flag = p->f;
    if (flag == true && p->h == 0) {
        fn_110_14BF8(b, c);
    }
    return 1;
}
