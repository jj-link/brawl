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

extern "C" {
u32 fn_27_C41A8(void*);
void* fn_27_C41A0(void*);
void* fn_27_C3B58(void*, int);
void* __register_global_object(void*, void* (*)(void*, int), void*);

extern s8 lbl_27_bss_2C0C;
extern void* lbl_27_bss_2C10;
extern u8 lbl_27_bss_2C20[16];
extern u8 lbl_27_data_17D90[72];
}

static inline void* find(Obj* self, s32 arg) {
    if (self->arr == 0) {
        return 0;
    }

    s32 n = self->arr->size__41soArrayContractibleTable_C12soStatusData_CFv();
    for (s32 i = 0; i < n; i++) {
        if (arg == (s32)fn_27_C41A8(self->arr->fn_27_C7528(i))) {
            return self->arr->fn_27_C7528(i);
        }
    }
    return 0;
}

extern "C" void* fn_27_C3F00(Obj* self, s32 arg) {
    void* p = find(self, arg);
    if (p == 0) {
        if (lbl_27_bss_2C0C == 0) {
            lbl_27_bss_2C10 = 0;
            lbl_27_bss_2C10 = lbl_27_data_17D90;
            void** obj = &lbl_27_bss_2C10;
            __register_global_object(
                obj,
                fn_27_C3B58,
                lbl_27_bss_2C20);
            lbl_27_bss_2C0C = 1;
        }
        return &lbl_27_bss_2C10;
    }
    return fn_27_C41A0(p);
}
