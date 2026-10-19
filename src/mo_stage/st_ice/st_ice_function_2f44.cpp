#pragma force_active on
extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void* p, int flag);
void __dt__10grYakumonoFv(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_62_2F44(void* p, int flag) {
    if (p != 0) {
        void* seq = (char*)p + 0x15c;
        if (seq != 0) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        }
        if (p != 0) {
            __dt__10grYakumonoFv(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
