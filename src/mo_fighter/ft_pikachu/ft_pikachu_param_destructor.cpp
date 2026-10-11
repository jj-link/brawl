#include <so/so_module_accesser.h>

extern "C" void* fn_98_1B294(void*, short);

static inline void destroyParamBase(void* accesser) {
    if (accesser) fn_98_1B294(accesser, static_cast<short>(0));
}

extern "C" void* fn_98_1B2D4(void* accesser, int deleting) {
    if (accesser) {
        destroyParamBase(accesser);
        if (static_cast<short>(deleting) > 0) operator delete(accesser);
    }
    return accesser;
}
