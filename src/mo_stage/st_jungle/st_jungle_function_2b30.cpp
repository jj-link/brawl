#pragma force_active on
extern "C" void __dt__Q28StSeUtil5SeSeqFv(void*, int);
extern "C" void __dt__10grYakumonoFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_51_2B30(void* self, int del) {
    if (self != 0) {
        void* seq = (char*)self + 0x164;
        if (seq != 0) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        }
        if (self != 0) {
            __dt__10grYakumonoFv(self, 0);
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
