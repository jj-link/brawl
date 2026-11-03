#pragma force_active on
extern unsigned lbl_805A1210;
extern unsigned lbl_805A1220;
extern unsigned lbl_805A1218;
extern void fn_803C7D64(int, int);
extern int fn_803AE480(int);
extern int fn_803C2AB0(void);
extern int fn_80204818(int, int);
extern void* fn_80204738(void*);
extern void fn_803A976C(void*, int, int);

int fn_803C49B8(unsigned arg0) {
    char* entry;
    char* p;
    unsigned val;

    if (arg0 < lbl_805A1210 && lbl_805A1220 != 0) {
        entry = (char*)(lbl_805A1220 + arg0 * 0x140);
    } else {
        entry = 0;
    }

    if (entry == 0 || *(int*)(entry + 8) == 0) {
        return 0xB003;
    }

    if (entry != 0 && *(int*)(entry + 8) != 0) {
        fn_803C7D64(*(int*)(entry + 8), 0);
    }

    if (fn_803AE480(*(int*)(entry + 8)) != 0) {
        return fn_803C2AB0();
    }

    if (entry != 0) {
        p = entry + 0x1C;
        val = *(unsigned*)p;
        if (p != 0) {
            if (*(int*)(p + 8) != 0 && val != 0) {
                fn_80204818((int)val, *(int*)(p + 8));
            }
            if (*(int*)(p + 0xC) != 0 && *(int*)p != 0) {
                fn_80204818(*(int*)p, *(int*)(p + 0xC));
            }
            if (p != 0) {
                *(int*)(p + 0) = 0;
                *(int*)(p + 4) = 0;
                *(int*)(p + 8) = 0;
                *(int*)(p + 0xC) = 0;
            }
        }
        if (val != lbl_805A1218 && val != 0) {
            fn_80204738((void*)val);
        }
    }

    fn_803A976C(entry, 0, 0x140);

    if (entry + 0x1C != 0) {
        *(int*)(entry + 0x1C) = 0;
        *(int*)(entry + 0x20) = 0;
        *(int*)(entry + 0x24) = 0;
        *(int*)(entry + 0x28) = 0;
    }

    return 0;
}