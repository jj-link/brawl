#include <types.h>
#pragma force_active on

class soHeapModuleImpl {
public:
    ~soHeapModuleImpl();
};
extern "C" void operator delete(void*);

extern "C" soHeapModuleImpl* fn_27_1E0C6C(soHeapModuleImpl* obj, s32 param) {
    if (obj) {
        obj->~soHeapModuleImpl();
        if (param > 0)
            operator delete(obj);
    }
    return obj;
}
