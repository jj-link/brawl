#pragma force_active on
// Decrement/replace the tracked pointer: bump the refcount of the new object,
// release the previously tracked one, then record the new pointer.

extern void fn_8027E9E0(void*);
extern void fn_8027EA10(int*);

extern void* lbl_805A0EC8;

void fn_8027EC70(int* arg0) {
    if (arg0 != 0) {
        fn_8027EA10(arg0);
    }

    if (lbl_805A0EC8 != 0) {
        fn_8027E9E0(lbl_805A0EC8);
    }

    lbl_805A0EC8 = arg0;
}
