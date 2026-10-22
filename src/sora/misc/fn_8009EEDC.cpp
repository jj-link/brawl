#pragma force_active on
extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, void* node);
extern char lbl_8049DEDC[];

extern "C" void fn_8009EEDC(char* arg0) {
    void* it;
    if (!((*(unsigned int*)(arg0 + 8) >> 13) & 1)) {
        it = lbl_8049DEDC + 4;
        Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(lbl_8049DEDC, &it, arg0);
        *(unsigned int*)(arg0 + 8) |= 0x2000;
    }
}
