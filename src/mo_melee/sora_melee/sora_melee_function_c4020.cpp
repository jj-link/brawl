#include <types.h>
#pragma force_active on

class Class_20958 {
public:
    virtual void fn_27_C76A8();
    virtual void* fn_27_C7528(s32);
    virtual void fn_27_C7538();
    virtual s32 size__41soArrayContractibleTable_C12soStatusData_CFv();
};
struct Obj {
    u8 pad[4];
    Class_20958* arr;
};
extern "C" u32 fn_27_C41A8(void*);
extern "C" s32 fn_27_C42D0(void*, s32);
inline void* find(Obj* self, s32 arg) {
    if (self->arr == 0) return 0;
    s32 n = self->arr->size__41soArrayContractibleTable_C12soStatusData_CFv();
    for (s32 i = 0; i < n; i++) {
        if (arg == (s32)fn_27_C41A8(self->arr->fn_27_C7528(i)))
            return self->arr->fn_27_C7528(i);
    }
    return 0;
}
extern "C" s32 fn_27_C4020(Obj* self, s32 arg, s32 arg2) {
    void* p = find(self, arg);
    if (p == 0) return 0;
    return fn_27_C42D0(p, arg2);
}
