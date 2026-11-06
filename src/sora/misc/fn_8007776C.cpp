#pragma force_active on
struct Src {
    int a;
    int b;
    float c;
};

extern "C" void* fn_801C0390(void*);
extern "C" int fn_801C0234(void*, void*);

extern "C" void fn_8007776C(unsigned char* self, float v) {
    if (self[0x6EF]) {
        Src local = *(Src*)fn_801C0390(self + 0xA48);
        local.c = v;
        fn_801C0234(self + 0xA48, &local);
    }
}
