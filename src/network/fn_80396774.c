#pragma force_active on
extern void fn_803974FC(void);
extern int fn_80397580(void);
extern void *fn_803970CC(int a, void *b);
extern int fn_80395FA0(void *p);

int NHTTPSendRequestAsync(void *arg0) {
    void *p;
    fn_803974FC();
    p = fn_803970CC(fn_80397580(), arg0);
    if (p != 0 && fn_80395FA0(p) == 0) {
        return *(int *)((char *)p + 0x18);
    }
    return -1;
}
