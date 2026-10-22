#pragma force_active on
extern "C" {
void fn_800B20B0(void*, int);
void fn_800B21C4(void*, int);
void fn_80108258(void*, void*, int, void*);
void fn_80108340(void*, void*, int);

extern char lbl_804092E0[];
extern char lbl_80409300[];

void fn_801081C8(void** arg0, void* arg1) {
    void** p = arg0;
    void* obj;
    int i;
    fn_80108258(arg0, lbl_804092E0, 4, arg1);
    fn_80108340(arg0, lbl_80409300, 3);
    i = 0;
    do {
        obj = *p;
        fn_800B20B0(obj, 1);
        fn_800B21C4(obj, 1);
        i++;
        p++;
    } while (i < 2);
}
}
