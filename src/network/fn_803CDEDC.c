#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;

extern const s32 lbl_8041ACB0[];
extern s32 lbl_8059FEA8;

extern void *fn_803CD2E0(void);
extern s32 fn_803CD270(void);
extern void *fn_803CD284(s32 size);
extern void fn_803CD298(void *ptr);

extern s32 fn_8020BA48(s32 arg0, void *arg1, s32 arg2);
extern s32 fn_8020AC38(void *arg0, s32 arg1, s32 arg2);
extern u32 fn_8020AA78(void *arg0, void *arg1, u32 arg2);
extern void fn_8020BC3C(void *arg0);

s32 fn_803CDEDC(u32 arg0, u32 arg1) {
    s32 file[0x24];
    const s32 *table;
    u32 idx;
    s32 ptr;
    void *buf;
    unsigned char *entry;
    s32 temp;
    u32 size;
    u32 aligned;
    s32 *data;

    table = lbl_8041ACB0;
    idx = table[arg0];
    ptr = (s32)fn_803CD2E0();
    if (ptr == 0) {
        ptr = 0;
    } else {
        entry = (unsigned char *)ptr + idx * 8;
        if (arg1 >= *(unsigned short *)entry) {
            ptr = 0;
        } else {
            if (fn_803CD270() == 0) {
                temp = 0;
            } else {
                buf = fn_803CD2E0();
                if (buf == 0) {
                    temp = 0;
                } else {
                    temp = *(s32 *)((unsigned char *)buf + 0x98);
                }
            }

            if (temp != 0) {
                data = (s32 *)(*(s32 *)(ptr + 0x94) + *(s32 *)(entry + 4));
                ptr = data[arg1 + 1] - data[(unsigned short)arg1];
            } else {
                ptr = 0;
                buf = fn_803CD284(0x400);
                if (fn_8020BA48(lbl_8059FEA8, file, 1) == 0) {
                    size = *(unsigned short *)entry * 4;
                    aligned = (size + 0x23) & ~0x1Fu;
                    fn_8020AC38(file, *(s32 *)(entry + 4), 0);
                    if (fn_8020AA78(file, buf, aligned) == aligned) {
                        data = (s32 *)buf;
                        ptr = data[arg1 + 1] - data[(unsigned short)arg1];
                    }
                    fn_8020BC3C(file);
                }
                fn_803CD298(buf);
            }
        }
    }
    return ptr;
}
