#include <so/so_array.h>
#include <types.h>
#pragma force_active on

struct FtRobotArrayAggregate {
    void* vtable;
    u32 pad[3];
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
    soArrayFixed<u32>* a;
};

extern "C" s32 fn_120_9BBC(FtRobotArrayAggregate* arrays) {
    s32 size = arrays->a->size();
    if (size < arrays->b->size()) {
        size = arrays->b->size();
    }
    if (size < arrays->c->size()) {
        size = arrays->c->size();
    }
    return size;
}
