#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void* slot1(int index);
    virtual void slot2();
    virtual int slot3();
};

struct Object { char padding[0xC]; Object_vptr_0* elements; };

extern "C" {
u32 fn_27_C40F4(void*);
void* fn_27_C3F00(void*, int);
void* fn_27_C3B58(void*, int);
void* __register_global_object(void*, void*, void*);
extern signed char lbl_27_bss_2C0C;
extern void* lbl_27_bss_2C10;
extern int lbl_27_data_17D90;
extern char lbl_27_bss_2C00[0xC];
}

static inline void* findElement(Object* self, int id) {
    int count = self->elements->slot3();
    for (int i = 0; i < count; ++i) {
        if (id == (int)fn_27_C40F4(self->elements->slot1(i)))
            return self->elements->slot1(i);
    }
    return 0;
}

extern "C" void* fn_27_C36B0(Object* self, int id, int value) {
    void* element = findElement(self, id);
    if (element == 0) {
        if (lbl_27_bss_2C0C == 0) {
            lbl_27_bss_2C10 = 0;
            lbl_27_bss_2C10 = &lbl_27_data_17D90;
            __register_global_object(&lbl_27_bss_2C10, (void*)fn_27_C3B58, lbl_27_bss_2C00);
            lbl_27_bss_2C0C = 1;
        }
        return &lbl_27_bss_2C10;
    }
    return fn_27_C3F00(element, value);
}