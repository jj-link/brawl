#include <types.h>
#pragma force_active on

class ElementArray {
public:
    virtual void unused0();
    virtual void* at(s32 index);
    virtual void unused2();
    virtual s32 size();
};

struct Container {
    u8 pad[8];
    void* cache;
    ElementArray* elements;
};

extern "C" u32 fn_27_C40F4(void* self);

static inline void* findElement(Container* self, s32 id) {
    s32 count = self->elements->size();
    for (s32 i = 0; i < count; i++) {
        if (id == (s32)fn_27_C40F4(self->elements->at(i))) {
            return self->elements->at(i);
        }
    }
    return 0;
}

extern "C" void fn_27_C3874(Container* self, s32 id) {
    if (id < 0) {
        self->cache = 0;
        return;
    }
    if (self->cache != 0 && id == (s32)fn_27_C40F4(self->cache)) {
        return;
    }
    void* found = findElement(self, id);
    if (found != 0) {
        self->cache = found;
    }
}
