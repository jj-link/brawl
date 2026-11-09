#pragma force_active on
extern unsigned int fn_80391144(void *, unsigned int);
extern void *fn_803970D4(int, void *);
extern void fn_80397274(int, void *);

int fn_803935E4(int arg0, void *arg1) {
    int result = 0;
    unsigned int temp = fn_80391144(arg1, *(unsigned int *)((char *)arg1 + 4));
    if (*(int *)((char *)arg1 + 0x1c) == 0 || *(int *)((char *)arg1 + 0x28) == 0 || temp != 0) {
        void *p = fn_803970D4(arg0, arg1);
        if (p != 0) {
            fn_80397274(arg0, p);
            if (*(int *)((char *)arg1 + 0x28) != 0 && *(int *)((char *)arg1 + 0x1c) != 0 && fn_80391144(arg1, *(unsigned int *)((char *)arg1 + 4)) == 0) {
                result = 1;
            }
        }
    } else if (temp == 0) {
        result = 1;
    }
    return result;
}