#pragma force_active on
extern "C" void fn_27_2816A4(void* self, void* a, void* b, void* c) {
    extern void* __vt__13soGeneralWork[];
    unsigned char* p = (unsigned char*)self;
    p[4] = 0;
    *(void**)(p + 8) = __vt__13soGeneralWork;
    *(void**)(p + 0) = (char*)__vt__13soGeneralWork + 8;
    *(void**)(p + 12) = a;
    *(void**)(p + 16) = b;
    *(void**)(p + 20) = c;
}
