#pragma force_active on
extern int lbl_805A0208;
extern "C" int OSReceiveMessage(void*, void*, int);

extern "C" {
int fn_8007E958(int arg0) {
    int msg;

    if (OSReceiveMessage((void*)(lbl_805A0208 + 0x1340), &msg, arg0) == 1) {
        return msg;
    }
    return 0;
}
}
