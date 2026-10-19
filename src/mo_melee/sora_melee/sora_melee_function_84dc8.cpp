#include <types.h>
#pragma force_active on

class WorkObj {
public:
    virtual ~WorkObj();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 getCount() = 0;
};

extern "C" bool fn_27_84DC8(WorkObj* obj) {
    return obj->getCount() == 0;
}
