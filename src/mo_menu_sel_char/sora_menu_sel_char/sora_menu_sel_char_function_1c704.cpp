#pragma force_active on
extern "C" void fn_800B8EDC(void*, void*);

extern "C" void fn_10_1C704(void* self) {
    unsigned char* p = (unsigned char*)self;
    if (p[0x50]) {
        fn_800B8EDC(*(void**)(p + 0x48), *(void**)(p + 0x4C));
        p[0x50] = 0;
    }
}
