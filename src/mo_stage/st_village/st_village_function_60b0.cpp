#pragma force_active on
namespace StSeUtil {
class SeSeq;
}

void operator delete(void* p);

extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void* p, int flag);
void* fn_70_60B0(void* p, int n);
}

void* fn_70_60B0(void* p, int n) {
    if (p) {
        __dt__Q28StSeUtil5SeSeqFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
