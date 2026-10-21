#pragma force_active on
extern "C" int fn_801F6524(void*);

extern "C" void fn_8015D00C(void* self) {
    unsigned char* p = (unsigned char*)self;
    if (p[0x6E] != 0 && p[0x4] != 0) {
        fn_801F6524(p + 0x28);
        p[0x4] = 0;
    }
}
