#pragma force_active on
namespace StSeUtil {
class SeSeq;
}

extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void* p, int flag);
void __dl__FPv(void* p);

void* fn_77_1B44(StSeUtil::SeSeq* p, int flag) {
    if (p) {
        __dt__Q28StSeUtil5SeSeqFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
