#include <types.h>
#pragma force_active on

extern "C" float fn_27_112D18(void* p) {
    void* obj = *reinterpret_cast<void**>(p);
    return *reinterpret_cast<float*>(reinterpret_cast<char*>(obj) + 0x4c4);
}
