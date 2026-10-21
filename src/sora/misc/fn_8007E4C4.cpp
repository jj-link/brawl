#pragma force_active on
extern "C" {
extern void OSCancelThread(void* thread);
extern char* lbl_805A0208;

void fn_8007E4C4(void) {
    if (*(int*)lbl_805A0208 != 0) {
        OSCancelThread(lbl_805A0208 + 8);
        *(int*)lbl_805A0208 = 0;
    }
}
}
#pragma force_active reset
