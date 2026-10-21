#pragma force_active on
extern "C" int fn_8020BC3C(void*);
extern "C" void fn_801C6B94(void* self);

extern "C" void fn_801C21F8(void* self) {
    unsigned char* p = (unsigned char*)self;
    if (p[0x1d8]) {
        fn_8020BC3C(p + 0x14c);
        p[0x1d8] = 0;
    }
    fn_801C6B94(self);
}
