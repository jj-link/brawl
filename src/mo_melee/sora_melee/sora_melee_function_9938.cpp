#include <types.h>
#pragma force_active on

class soModelModuleImpl {
    char _buf[204];
public:
    void setUpMtxFinal();
};

extern "C" void fn_27_973C(soModelModuleImpl*);
extern "C" void fn_80047BAC(void*, void*);
extern "C" void fn_800471A4(void*, int, int, void*, void*, int, int, int);

void soModelModuleImpl::setUpMtxFinal() {
    char* self = reinterpret_cast<char*>(this);
    if (*(self + 0xC2) != 2) {
        fn_27_973C(this);
        void* p = *(void**)(self + 0xC);
        *(int*)(self + 0x48) = 0;
        fn_80047BAC(p, *(void**)(self + 0xA8));
        fn_800471A4(p, 0, 0, *(void**)(self + 0xA8), *(void**)(self + 0xAC), 1, 0, 1);
        *(unsigned char*)(self + 0xC2) = 2;
    }
}
