#pragma force_active on

extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, void* node);

extern "C" void fn_801829C0(char* arg0, char* arg1) {
    void* sp8;
    sp8 = arg0 + 0x14;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(arg0 + 0x10, &sp8, arg1 + 4);
    *(void**)(arg1 + 0xC) = arg0;
}
