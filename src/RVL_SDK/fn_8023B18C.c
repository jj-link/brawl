#pragma force_active on
extern char lbl_80529CF8[];
extern void* fn_8022EFF8(int);
extern void fn_8024629C(void*, void*);
extern void* memset(void*, int, unsigned long);
extern char* strncpy(char*, const char*, unsigned long);

int fn_8023B18C(char* arg0) {
    void* r;
    char* base;
    if (arg0 == 0) {
        return 5;
    }
    base = lbl_80529CF8;
    if ((unsigned char)base[0x64E] <= 1) {
        return 0xC;
    }
    r = fn_8022EFF8(2);
    if (r != 0) {
        if (base != arg0) {
            memset(base, 0, 0x20);
            strncpy(base, arg0, 0x1F);
        }
        fn_8024629C(r, base);
        return 1;
    }
    return 3;
}
