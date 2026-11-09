#pragma force_active on
extern "C" {
void fn_801F0A30(void);
void fn_8007E944(void* msg);
int OSReceiveMessage(void* queue, void** msg, int flags);
extern int* lbl_805A01F8;

void fn_8007D1BC(void) {
    void* msg;
    int result;

    fn_801F0A30();
    if (*lbl_805A01F8 != 0) {
        for (;;) {
            result = OSReceiveMessage((char*)lbl_805A01F8 + 0x7C0, &msg, 0);
            if (result == 1) {
                result = (int)msg;
            } else {
                result = 0;
            }
            if (result == 0) {
                break;
            }
            fn_8007E944((void*)result);
        }
    }
}
}
