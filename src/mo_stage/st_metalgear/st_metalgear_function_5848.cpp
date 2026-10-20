#pragma force_active on
extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void* p, int flag);
void* fn_71_276C(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_71_5848(void* self, int flag) {
    if (self != 0) {
        void* seq = (char*)self + 0x198;
        if (seq != 0) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        }
        if (self != 0) {
            fn_71_276C(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
