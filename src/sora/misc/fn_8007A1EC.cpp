#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_801CA8F8(void*);
void fn_801CA880(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void free__13gfHeapManagerFPv(void*);
}

extern "C" void* fn_8007A1EC(u8* self, int deleting) {
        u8* q;
    if (self != 0) {
        fn_801CA8F8(self + 0x258);
        free__13gfHeapManagerFPv(*(void**)(self + 0x474));
        fn_801CA8F8(self + 0x284);
        free__13gfHeapManagerFPv(*(void**)(self + 0x478));
        fn_801CA8F8(self + 0x2B0);
        free__13gfHeapManagerFPv(*(void**)(self + 0x47C));
        if (*(void**)(self + 0x4A0) != 0) {
            fn_801CA8F8(self + 0x43C);
            free__13gfHeapManagerFPv(*(void**)(self + 0x4A0));
        }
        fn_801CA8F8(self + 0x38C);
        free__13gfHeapManagerFPv(*(void**)(self + 0x490));

        u8* p = self;
        int off;
        unsigned int i;
        for (i = 0, off = 0; i < 4; i++) {
            fn_801CA8F8((u8*)off + (unsigned int)self + 0x2DC);
            free__13gfHeapManagerFPv(*(void**)(p + 0x480));
            off += 0x2C;
            p += 4;
        }

        unsigned int j = 8;
        q = self + 0x3B8;
        u8* r = self + 0x20;
        do {
            fn_801CA8F8(q);
            free__13gfHeapManagerFPv(*(void**)(r + 0x474));
            j++;
            q += 0x2C;
            r += 4;
        } while (j <= 10);

        __destroy_arr(self + 0x258, fn_801CA880, 0x2C, 0x0C);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
