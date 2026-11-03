#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern const u8 lbl_2_rodata_12E0[];
extern const u8 lbl_2_rodata_14A8[];
}

extern "C" int fn_2_31C6C(void* self, int index, int* out) {
    int n;
    const u8* choices;
    int i;
    int j;
    int choice;
    int count;
    const u8* entry;
    count = 0;
    choices = lbl_2_rodata_14A8;
    entry = lbl_2_rodata_12E0 + index * 16;
    i = 0;
    do {
        choice = *choices;
        if (choice != 2 || entry[5] == 0 ||
            (u32)(((*(u8**)((u8*)self + 0x40))[0x1A8] >> 7) & 1) != 1) {
            n = entry[4];
            for (j = 0; j < n; j++) {
                if (choice == (*(u8**)((u8*)self + 0x40))[j + 0x19C])
                    break;
            }
            if (j >= n) {
                *out++ = choice;
                count++;
            }
        }
        i++;
        choices++;
    } while (i < 5);
    return count;
}
