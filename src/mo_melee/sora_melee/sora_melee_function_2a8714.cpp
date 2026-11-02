#include <types.h>
#pragma force_active on

extern u32 lbl_27_bss_64A0[0xB2];
extern const s16 lbl_27_rodata_53A0[];

class List {
public:
    virtual void f0();
    virtual void f1();
    virtual void* get(s32);
    virtual s32 size();
};

struct Object {
    char pad[0x6D8];
    List list;
};

extern "C" s32 fn_27_2A8714(Object* arg0) {
    s32 count = 0;
    s32 i = 0;

    while (i < arg0->list.size()) {
        char* obj = *(char**)arg0->list.get(i);
        if (obj != 0) {
            s32 kind = *(s32*)(obj + 0x8C0);
            s32 cached = lbl_27_bss_64A0[kind];
            s32 result;

            if (cached != 0) {
                result = (cached - 1) == 0;
            } else {
                s32 j = 0;
                const s16* p = lbl_27_rodata_53A0 + kind * 7;

                while (j < 7 && *p != -1) {
                    if (*p == -2) {
                        lbl_27_bss_64A0[kind] = 1;
                        result = 1;
                        goto done;
                    }
                    p++;
                    j++;
                }

                lbl_27_bss_64A0[kind] = 2;
                result = 0;
            }

        done:
            if (result) {
                count++;
            }
        }
        i++;
    }

    return count;
}
