#include <types.h>
#pragma force_active on

namespace StSeUtil {
    struct SeSeq;
}

extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void __dl__FPv(void*);
}

extern "C" StSeUtil::SeSeq* fn_27_2465FC(StSeUtil::SeSeq* seq, s32 n) {
    if (seq) {
        __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        if (n > 0)
            __dl__FPv(seq);
    }
    return seq;
}
