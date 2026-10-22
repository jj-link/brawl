#pragma force_active on
class gfRunnable;

namespace Heaps {
enum HeapType { HeapType_Dummy = 0 };
}

class gfThread {
public:
    void createThread(gfRunnable*, unsigned long, unsigned long, Heaps::HeapType);
    void* vtable;
    char pad4[0x33C];
};

extern "C" {
extern char __vt__8gfThread[];
extern char lbl_80423928[];
extern char lbl_80423918[];
}

extern "C" void* memcpy(void*, const void*, unsigned long);

extern "C" gfThread* fn_8003CFD0(gfThread* arg0) {
    arg0->vtable = __vt__8gfThread;
    arg0->createThread((gfRunnable*)arg0, 0xC, 0x1000, (Heaps::HeapType)0x3A);
    arg0->vtable = lbl_80423928;
    memcpy((char*)arg0 + 0x340, lbl_80423918, 0x10);
    *((char*)arg0 + 0x360) = 0;
    *(int*)((char*)arg0 + 0x364) = 0;
    *(int*)((char*)arg0 + 0x368) = 0;
    *((char*)arg0 + 0x370) = 0;
    *(int*)((char*)arg0 + 0x35C) = 0;
    return arg0;
}
