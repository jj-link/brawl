#pragma force_active on
extern "C" {
void free__13gfHeapManagerFPv(void*);
void __dl__FPv(void*);
}

extern "C" void* fn_800C37CC(char* self, int del) {
    if (self) {
        if (self + 0x10) {
            void* p = *(void**)(self + 0x10);
            if (p) {
                free__13gfHeapManagerFPv(p);
            }
            *(void**)(self + 0x10) = 0;
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}