#pragma force_active on
typedef int s32;

extern "C" s32 OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(s32);
extern "C" void* fn_801BE7BC();
extern "C" void fn_801BE8D0(void*, void*);
extern "C" void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void* list, void* node);
extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(void* list, void** it, void* node);

extern "C" void fn_801D2F30(char* self, char* arg) {
    s32 irq1 = OSDisableInterrupts();
    void* g = fn_801BE7BC();
    fn_801BE8D0(g, arg);
    s32 irq2 = OSDisableInterrupts();
    char* node = arg + 0x124;
    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(self + 4, node);
    void* it = self + 0x14;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(self + 0x10, &it, node);
    OSRestoreInterrupts(irq2);
    OSRestoreInterrupts(irq1);
}
