#pragma force_active on
extern "C" void OSJoinThread(void*, void*);
extern "C" void fn_801CFA14(void);
extern "C" void fn_801D0130(void);

extern "C" void fn_801D02EC(void* self) {
    unsigned char* p = (unsigned char*)self;
    if (p[0x31D]) {
        p[0x31C] = 1;
        fn_801CFA14();
        fn_801D0130();
        OSJoinThread(self, 0);
        p[0x31D] = 0;
    }
}
