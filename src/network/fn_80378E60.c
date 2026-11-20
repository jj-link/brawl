#pragma force_active on
extern void *lbl_8059F9A8;
extern unsigned int fn_8035D728(void);
extern void fn_80379034(void *);
extern void fn_80378F78(void *);
void fn_80378E60(void *arg0) {
    int i;
    char *obj;
    unsigned int now;
    obj = (char *)arg0;
    if (obj == 0) obj = (char *)lbl_8059F9A8;
    if (*(unsigned int *)(obj + 0xBC) != 0) fn_80379034(obj);
    fn_80378F78(obj);
    i = 0;
    now = fn_8035D728();
    for (; i < 40; obj += 16, i++) {
        if (*(unsigned int *)(obj + 0x118) != 0 && now - *(unsigned int *)(obj + 0x120) > 0xFA0U)
            *(unsigned int *)(obj + 0x118) = 0;
    }
}