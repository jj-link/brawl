#pragma force_active on
extern void fn_8023CAB0(int arg);
extern int lbl_80529918[];
extern void fn_80233A98(unsigned char *arg0);
extern void fn_80233B28(unsigned char *self);
extern void fn_8023C4E8(void *arg0, void *arg1, void *arg2, int *arg3);

void fn_80232C70(void *arg0) {
    int *p = (int *)arg0;
    fn_8023CAB0(0);
    lbl_80529918[0] = p[6];
    lbl_80529918[2] = p[5];
    fn_8023C4E8((char *)arg0 + 8, (void *)fn_80233A98, (void *)fn_80233B28, lbl_80529918);
}