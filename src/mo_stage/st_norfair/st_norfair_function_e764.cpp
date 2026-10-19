#pragma force_active on
extern "C" void __dt__Q28StSeUtil5SeSeqFv(void* p, int del);
extern "C" void* fn_54_2CB0(void* p, int del);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_54_E764(void* self, int del) {
    if (self != 0) {
        char* seq = (char*)self + 0x168;
        if (seq != 0) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        }
        fn_54_2CB0(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
