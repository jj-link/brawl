#pragma force_active on

struct Entry {
    int type;
    int value;
};

extern "C" const Entry lbl_1_rodata_1378[];

extern "C" int fn_1_32638(int id)
{
    if (id < 0 || id > 0x21) {
        return 0;
    }

    const Entry* entry = lbl_1_rodata_1378;
    int found = 0;
    int index = 0;

    for (;;) {
        if (found != 0) {
            int type = entry->type;
            if (type == 0 || type == 1 || type == 3 || type == 4 || type == 0x1B) {
                return *(int*)(lbl_1_rodata_1378[index].value);
            }
        } else if (entry->type == 0x16 && id == entry->value - 1) {
            found = 1;
        }

        entry++;
        index++;
    }
}
