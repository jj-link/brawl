#include <types.h>
#pragma force_active on

typedef void (*PFN_elem)(void*);
extern "C" void __construct_array(void*, PFN_elem, PFN_elem, unsigned long, int);
extern "C" void fn_27_A6948(void*);
extern "C" void fn_27_A6978(void*);
extern "C" char lbl_27_data_3A248[];

struct fn27Elem {
    u8 pad[0x24];
};

struct fn27Obj {
    void* vt0;
    void* vt1;
    u32 m_bits;
    fn27Elem m_elems[2];
};

extern "C" {
fn27Obj* fn_27_198F08(fn27Obj* self) {
    self->vt0 = lbl_27_data_3A248;
    self->vt1 = lbl_27_data_3A248 + 0x48;
    self->m_bits &= 0x3fffff;
    __construct_array(&self->m_elems[0], (PFN_elem)fn_27_A6948, (PFN_elem)fn_27_A6978, 0x24, 2);
    return self;
}
}
