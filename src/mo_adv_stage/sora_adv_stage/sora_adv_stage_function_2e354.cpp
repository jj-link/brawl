#pragma force_active on
extern "C" {
void free__13gfHeapManagerFPv(void*);
void __dl__FPv(void*);
void fn_40_19B8C(void*, int);
}

extern "C" void* fn_40_2E354(char* self, int del) {
    if (self) {
        if (self + 0x150) {
            void* p = *(void**)(self + 0x154);
            if (p) {
                free__13gfHeapManagerFPv(p);
            }
        }
        fn_40_19B8C(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
