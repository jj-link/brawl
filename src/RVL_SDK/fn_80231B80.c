#pragma force_active on
extern unsigned char lbl_805297A0[0x30];
extern int lbl_805A0D24;

void OSCancelAlarm(void* alarm);
void fn_802318C8(void);
void fn_802303A4(void);

void fn_80231B80(int arg0) {
    lbl_805A0D24 = arg0;
    OSCancelAlarm(lbl_805297A0);
    fn_802318C8();
    fn_802303A4();
}
