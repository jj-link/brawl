#pragma force_active on
extern void fn_8022F0E0(void *);
extern char lbl_80529918[];

void fn_802336D4(void) {
    void *p = *(void **)(lbl_80529918 + 0x74);
    if (p != 0) {
        fn_8022F0E0(p);
        *(int *)(lbl_80529918 + 0x74) = 0;
    }
}
