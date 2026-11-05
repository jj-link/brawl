#include <gf/gf_task.h>
#pragma force_active on
class Class_17F48 {
public:
    virtual void fn_27_C51D4();
    virtual unsigned char fn_27_C518C(void*);
};
extern "C" {
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
}
struct Object {
    char pad[0x44];
    unsigned int id;
    void* arg;
    Class_17F48* callback;
    char pad2[0x3d];
    unsigned char result;
    unsigned char active;
};
extern "C" void fn_27_C6B3C(Object* self) {
    bool exists;
    if (self->id + 0x10000 == 0xffff)
        exists = false;
    else
        exists = gfTask::getTask(self->id) != 0;
    if (!exists) {
        if (self->active) self->result = 1;
    } else if (self->active && self->callback) {
        if (lbl_27_bss_F0 == 0) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
            if (p) p = fn_27_5BCD0(p);
            lbl_27_bss_F0 = p;
        }
        if (fn_27_5BEA8(lbl_27_bss_F0) == 1)
            self->result = self->callback->fn_27_C518C(self->arg);
    }
}