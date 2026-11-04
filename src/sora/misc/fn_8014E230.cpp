#include <types.h>
#pragma force_active on
extern "C" int fn_803A3540(u16*, int);
extern "C" int fn_803A3FA0(void*, unsigned int);
extern "C" int fn_803A3CB4(void*);

struct Entry {
    char pad[8];
    u32 value;
    char pad2[0x1f0];
    u8 flag;
};

extern "C" int fn_8014E230(u32 arg0, int arg1) {
    Entry entry;
    int last = 0;
    int result = 0;
    u16 index = last;
    int status = fn_803A3540(&index, 1);
    while (status >= 0) {
        if (result != 0)
            last = result;
        result = last;
        last = fn_803A3FA0(&entry, index);
        if (last >= 0 && entry.flag && (arg1 != 0 || arg0 == entry.value))
            last = fn_803A3CB4(&entry);
        status = fn_803A3540(&index, 0);
    }
    return result;
}