#pragma force_active on
extern "C" void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(char* list, char* node);
extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, char* node);
extern "C" int OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(int level);

extern "C" void fn_801BB9AC(char* list, char* node) {
    int a = OSDisableInterrupts();
    node[0x1D] = 1;
    int b = OSDisableInterrupts();
    char* n = node + 0x40;
    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(list, n);
    void* it = list + 0x1C;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(list + 0x18, &it, n);
    OSRestoreInterrupts(b);
    OSRestoreInterrupts(a);
}
