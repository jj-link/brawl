#pragma force_active on
extern "C" void __dt__Q28StSeUtil5SeSeqFv(void*, int);
extern "C" void __dt__10grYakumonoFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_61_30A0(void* p, int flags)
{
    if (p != 0) {
        char* seq = (char*)p + 0x174;
        if (seq != 0) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        }

        if (p != 0) {
            __dt__10grYakumonoFv(p, 0);
        }

        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
