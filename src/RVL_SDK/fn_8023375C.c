#pragma force_active on
extern int lbl_80529918[];
void fn_8022F0E0(void*);

void fn_8023375C(void) {
    if (lbl_80529918[5]) {
        fn_8022F0E0((void*)lbl_80529918[5]);
        lbl_80529918[5] = 0;
    }
    ((void (*)(int, int))lbl_80529918[0])(4, 0);
}
