#pragma force_active on
extern "C" void* fn_801D2AD0(void);
extern "C" void fn_801D30E0(void* a, void* b);
extern "C" void fn_801B92BC(void* p, int n);

extern "C" void fn_801D1630(void* arg0, int arg1) {
    unsigned char* base;
    unsigned int* p;
    int outer;
    int inner;
    *(int*)((unsigned char*)arg0 + 0xb4) = arg1;
    fn_801D30E0(fn_801D2AD0(), arg0);
    if (*(int*)((unsigned char*)arg0 + 0xb4) == 1) {
        base = (unsigned char*)arg0;
        outer = 0;
        for (; outer < *(int*)((unsigned char*)arg0 + 0x9c); outer++) {
            p = (unsigned int*)base;
            for (inner = 0; inner < *(int*)((unsigned char*)arg0 + 0xa0); inner++) {
                if (p[3] != 0) {
                    fn_801B92BC((void*)p[3], 0xf);
                }
                p++;
            }
            base += 0x10;
        }
    }
}
