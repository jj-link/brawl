#pragma force_active on
extern int fn_803F6150(const void*, const void*, unsigned long);
extern char lbl_80529CF8[];

int fn_8023F304(const void* arg0) {
    unsigned int i;
    char* ptr;

    i = 0;
    ptr = lbl_80529CF8 + 0x1854;
    while (i < 3) {
        if (fn_803F6150(ptr + 0x28, arg0, 6) == 0) {
            if (*(unsigned short*)(ptr + 8) == 4) {
                return 1;
            }
        }
        i++;
        ptr += 0x34;
    }
    return 0;
}
