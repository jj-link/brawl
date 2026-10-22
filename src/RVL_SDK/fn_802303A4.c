#pragma force_active on
typedef struct {
    unsigned char n;
    int st[0xA200];
    unsigned char pad[2];
} S;
extern S lbl_804FD448;
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);

void fn_802303A4(void) {
    int s = OSDisableInterrupts();
    lbl_804FD448.st[lbl_804FD448.n] = s;
    lbl_804FD448.n++;
    *((unsigned char*)&lbl_804FD448 + 0x28802) = 0;
    lbl_804FD448.n--;
    OSRestoreInterrupts(lbl_804FD448.st[lbl_804FD448.n]);
    while (lbl_804FD448.n != 0) {
        lbl_804FD448.n--;
        OSRestoreInterrupts(lbl_804FD448.st[lbl_804FD448.n]);
    }
}
