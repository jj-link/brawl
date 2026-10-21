#include <types.h>
#pragma force_active on

extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, void* node);

extern "C" void fn_801BF5B8(char* self, char* obj) {
    void* it = self + 4;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(self, &it, obj + 0xD0);
    *(char**)(obj + 0x14) = self;
}
