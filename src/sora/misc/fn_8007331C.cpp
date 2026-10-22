#pragma force_active on
extern "C" void* fn_801C07AC(void*);
extern "C" void* fn_801C0390(void*);
extern "C" void* fn_801B77F8(void);
extern "C" void fn_801B8390(void*, int, int);

extern "C" void fn_8007331C(void* self) {
    unsigned char* p = (unsigned char*)self;
    if (p[0x6EF]) {
        float* a = (float*)fn_801C07AC(p + 0x728);
        float* b = (float*)(p + 0xB6C);
        b[0] = a[0];
        b[1] = a[1];
        b[2] = a[2];
        b[3] = a[3];
        b[4] = a[4];
        b[5] = a[5];
        float* c = (float*)fn_801C0390(p + 0xA48);
        float* d = (float*)(p + 0xB84);
        d[0] = c[0];
        d[1] = c[1];
        d[2] = c[2];
        fn_801B8390(fn_801B77F8(), 0, 0xFA);
        fn_801B8390(fn_801B77F8(), 1, 0xFA);
        fn_801B8390(fn_801B77F8(), 2, 0xFA);
    }
}
