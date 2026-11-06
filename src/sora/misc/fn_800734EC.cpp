#pragma force_active on

extern "C" {
extern char lbl_80454470[];
void __dt__8gfThreadFv(void*, short);
void __dl__FPv(void*);
void fn_8007A1EC(void*, int);
void fn_801BEB98(void*, int);
void fn_801BED78(void*);
void fn_801C8A68(void*, int);
void fn_801C8C14(void*);
void fn_801CA7E8(void*);
void fn_801CC228(void);
void fn_801FF1AC(void);
void free__13gfHeapManagerFPv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_800730A4(void*, int);
void fn_80073028(void*, int);
void fn_8007312C(void*, int);
}

extern "C" void* fn_800734EC(unsigned char* self, int deleting) {
    if (self) {
        void* thr = *(void**)(self + 0xB94);
        *(void**)(self + 0xBCC) = lbl_80454470;
        if (thr) {
            __dt__8gfThreadFv(thr, 0);
            __dl__FPv(thr);
        }
        thr = *(void**)(self + 0xB98);
        if (thr) {
            __dt__8gfThreadFv(thr, 0);
            __dl__FPv(thr);
        }
        fn_8007A1EC(*(void**)(self + 0x2D0), 1);
        fn_801C8C14(self + 0x18C);
        fn_801BED78(self);
        free__13gfHeapManagerFPv(*(void**)(self + 0x6F0));
        free__13gfHeapManagerFPv(*(void**)(self + 0x6F4));
        free__13gfHeapManagerFPv(*(void**)(self + 0x6F8));
        free__13gfHeapManagerFPv(*(void**)(self + 0x6FC));
        unsigned char* cursor = self;
        for (int i = 0; i < 2; ++i, cursor += 4) {
            free__13gfHeapManagerFPv(*(void**)(cursor + 0xB58));
            free__13gfHeapManagerFPv(*(void**)(cursor + 0xB60));
        }
        fn_801CC228();
        fn_801FF1AC();
        __destroy_arr(self + 0xA48, fn_800730A4, 0x88, 2);
        __destroy_arr(self + 0x728, fn_80073028, 0x190, 2);
        unsigned char* p = self + 0x6E0;
        if (p) {
            fn_801CA7E8(p);
        }
        __destroy_arr(self + 0x2D4, fn_8007312C, 0x20, 0x20);
        fn_801C8A68(self + 0x18C, -1);
        fn_801BEB98(self, -1);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
