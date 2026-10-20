#pragma force_active on
extern "C" char lbl_1_data_6048[0x60];
extern "C" char lbl_1_data_6218[0x18];
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

extern "C" void* fn_1_1CC48() {
    unsigned char* p = (unsigned char*)__nw__FUlQ25Heaps8HeapType(0x50, 0x2e);
    if (p) {
        unsigned int* u = (unsigned int*)p;
        u[0] = (unsigned int)(unsigned char*)lbl_1_data_6048;
        u[1] = (unsigned int)(unsigned char*)lbl_1_data_6218;
        u[2] = 0;
        u[3] = 0;
        u[4] = 0;
        u[5] = 0;
        u[6] = 0;
        u[7] = 1;
        u[8] = 0;
        u[9] = 0;
        u[0x13] = 0;
    }
    return p;
}
