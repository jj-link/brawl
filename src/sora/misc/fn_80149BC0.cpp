#pragma force_active on
extern "C" {
extern char lbl_80460CF0[];
extern unsigned char __vt__8NtBuffer[];
extern char* lbl_805A0434;
void fn_80025A74(void*);
void free__13gfHeapManagerFPv(void*);
void __dl__FPv(void*);

struct NB { virtual void f0(); virtual void f1(); virtual void f2(); };
void* fn_80149BC0(void* self, int flag) {
    if (self) {
        char* p = (char*)self;
        *(void**)p = lbl_80460CF0;
        fn_80025A74(*(void**)(lbl_805A0434 + 0x353c));
        void* b = *(void**)(p + 0x3538);
        if (b) {
            free__13gfHeapManagerFPv(b);
            *(void**)(lbl_805A0434 + 0x3538) = 0;
        }
        lbl_805A0434 = 0;
        NB* n = (NB*)(p + 0x33b8);
        if (n) {
            *(void**)(p + 0x33b8) = __vt__8NtBuffer;
            n->f2();
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return self;
}
}
