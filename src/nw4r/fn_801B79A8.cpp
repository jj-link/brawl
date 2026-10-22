#pragma force_active on
extern "C" void fn_802010D8(int);
extern "C" void fn_801B8458(void*, int);
extern "C" void fn_801FFE28(int, int);
extern "C" void fn_801FFE8C(int, int);
extern "C" void fn_801FFEF0(int, int);

extern "C" void fn_801B79A8(void* self) {
    unsigned char* p = (unsigned char*)self;
    if (p[0x18]) {
        fn_802010D8(*(int*)(p + 0x14));
        fn_801B8458(self, 0);
        fn_801B8458(self, 1);
        fn_801B8458(self, 2);
        fn_801FFE28(*(int*)(p + 0xD8), *(int*)(p + 0xE4));
        fn_801FFE8C(*(int*)(p + 0xDC), *(int*)(p + 0xE8));
        fn_801FFEF0(*(int*)(p + 0xE0), *(int*)(p + 0xEC));
        *(int*)(p + 0xD8) = 0;
        *(int*)(p + 0xE4) = 0;
        *(int*)(p + 0xDC) = 0;
        *(int*)(p + 0xE8) = 0;
        *(int*)(p + 0xE0) = 0;
        *(int*)(p + 0xEC) = 0;
        *(int*)(p + 0x4) = 0;
        p[0x18] = 0;
    }
}
