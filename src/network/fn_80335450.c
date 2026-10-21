#pragma force_active on
extern void (*lbl_805A0F58)(void*, void*);

void fn_80335450(void* a, void* b) {
    if (b != 0) {
        lbl_805A0F58(a, (void*)((char*)b - 0x20));
    }
}
