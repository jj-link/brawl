#include <gf/gf_task.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on
extern "C" void __dt__6gfTaskFv(void*, int);
extern "C" void __dl__FPv(void*);
class Object {
    char pad[0x5c];
public:
    virtual ~Object();
};
struct Inner {
    char pad[8];
    gfTask* task;
};
struct Self {
    char pad[0x40];
    Inner inner;
    char pad4c[0x18];
    Object* object;
    char pad68[0xa0];
    void* buffer;
};
extern "C" Self* fn_800C1D9C(Self* self, int flag) {
    if (self) {
        if (&self->buffer) {
            if (self->buffer) gfHeapManager::free(self->buffer);
            self->buffer = 0;
        }
        if (&self->object) {
            delete self->object;
        }
        if (&self->inner) {
            if (&self->inner.task) {
                if (self->inner.task) self->inner.task->exit();
                self->inner.task = 0;
            }
        }
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}