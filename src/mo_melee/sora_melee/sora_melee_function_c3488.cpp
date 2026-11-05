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
    u8 pad[0xc];
    Class_20958* arr;
};

extern "C" s32 fn_27_C40F4(void*);
extern "C" void fn_27_C40FC(void*, s32);
extern "C" u32 fn_27_C3C54(void*, s32);
extern "C" void fn_27_C3D08(void*, s32, s32);

inline void* findEq(Obj* self, s32 arg) {
    s32 n = self->arr->size__41soArrayContractibleTable_C12soStatusData_CFv();
    for (s32 i = 0; i < n; i++) {
        if (fn_27_C40F4(self->arr->fn_27_C7528(i)) == arg) {
            return self->arr->fn_27_C7528(i);
        }
    }
    return 0;
}

inline void* findNeg(Obj* self) {
    s32 n = self->arr->size__41soArrayContractibleTable_C12soStatusData_CFv();
    for (s32 i = 0; i < n; i++) {
        if (fn_27_C40F4(self->arr->fn_27_C7528(i)) < 0) {
            return self->arr->fn_27_C7528(i);
        }
    }
    return 0;
}

extern "C" void fn_27_C3488(Obj* self, s32 arg1, s32 arg2, s32 arg3) {
    void* p = findEq(self, arg1);
    if (p == 0) {
        p = findNeg(self);
        if (p != 0) {
            fn_27_C40FC(p, arg1);
        } else {
            return;
        }
    }
    if (fn_27_C3C54(p, arg2) != 1) {
        fn_27_C3D08(p, arg2, arg3);
    }
}
