#include <gf/gf_task.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

class Object50 {
    char pad[0x50];
public:
    virtual ~Object50();
};
class Object5C {
    char pad[0x5C];
public:
    virtual ~Object5C();
};
struct Prefix { char pad[4]; };
struct TaskWithPrefix : Prefix, gfTask {};
struct Self {
    char pad0[0x3C];
    void* vtable;
    char pad40[8];
    gfTask* task48;
    char pad4C[0x18];
    Object5C* object64;
    char pad68[0xA0];
    void* buffer108;
    char pad10C[4];
    TaskWithPrefix* task110;
    char pad114[0x8C];
    void* buffer1A0;
    char pad1A4[0x48];
    void* buffer1EC;
    char pad1F0[8];
    Object50* object1F8;
};
extern "C" {
extern char lbl_80457030[];
int fn_800390C8(void*);
void fn_800C37CC(void*, int);
void __destroy_arr(void*, void (*)(void*, int), int, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
Self* fn_800C383C(Self* self, int flag) {
    if (self) {
        self->vtable = lbl_80457030;
        fn_800390C8(self->task110);
        __destroy_arr((char*)self + 0x358, fn_800C37CC, 0x14, 2);
        if (&self->buffer1EC) {
            if (&self->object1F8) {
                delete self->object1F8;
            }
            if (&self->buffer1EC) {
                if (&self->buffer1EC) {
                    if (self->buffer1EC) gfHeapManager::free(self->buffer1EC);
                    self->buffer1EC = 0;
                }
            }
        }
        if (&self->buffer1A0) {
            if (self->buffer1A0) gfHeapManager::free(self->buffer1A0);
            self->buffer1A0 = 0;
        }
        if (&self->task110) {
            if (self->task110) {
                static_cast<gfTask*>(self->task110)->exit();
            }
            self->task110 = 0;
        }
        if (self) {
            if (&self->buffer108) {
                if (self->buffer108) gfHeapManager::free(self->buffer108);
                self->buffer108 = 0;
            }
            if (&self->object64) {
                delete self->object64;
            }
            if ((char*)self + 0x40) {
                if (&self->task48) {
                    if (self->task48) self->task48->exit();
                    self->task48 = 0;
                }
            }
            __dt__6gfTaskFv(self, 0);
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
}