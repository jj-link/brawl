#pragma force_active on
extern "C" {
extern char lbl_8049E594[];
void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(void* list, void** it, void* node);

void fn_80133C1C(unsigned char* self) {
    void* it;
    if (!((self[0x71] >> 5) & 1)) {
        it = lbl_8049E594 + 4;
        Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(lbl_8049E594, &it, self);
        self[0x71] = (unsigned char)(self[0x71] | 0x20);
    }
}
}
