#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3AFC(void* object, short count);
extern "C" void* fn_114_20120(void* object, short deleting);
extern "C" void* fn_114_201AC(void* self, short flags);
extern "C" void* fn_114_20238(void* self, short deleting);
extern "C" void* fn_114_202C4(void* self, short flags);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_20090(void* self, short deleting) {
    if (self != 0) {
        fn_114_3AFC((char*)self + 0x4B0, -1);
        fn_114_20120((char*)self + 0x384, -1);
        fn_114_201AC((char*)self + 0x258, -1);
        fn_114_20238((char*)self + 0x12C, -1);
        fn_114_202C4(self, -1);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
