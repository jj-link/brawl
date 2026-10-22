#pragma force_active on
extern char lbl_80529CF8[];
extern int fn_803F6150(const void*, const void*, unsigned long);

void* fn_8023A0F0(void* arg0) {
    char* ptr = lbl_80529CF8 + 0x1F30;
    int i;
    for (i = 0; i < 0x10; i++) {
        if (*(unsigned char*)(ptr + 0x76) & 0x80) {
            if (fn_803F6150(ptr + 0x1C, arg0, 6) == 0) {
                return ptr;
            }
        }
        ptr += 0x88;
    }
    return 0;
}
