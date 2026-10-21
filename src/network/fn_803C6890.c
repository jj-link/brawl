#pragma force_active on

typedef unsigned int u32;
extern u32 lbl_805A1210;
extern u32 lbl_805A1220;
extern int fn_803C7D10(void*);

int fn_803C6890(u32 arg0) {
    void* p;
    if (arg0 < lbl_805A1210 && lbl_805A1220 != 0)
        p = (void*)(lbl_805A1220 + arg0 * 0x140);
    else
        p = 0;
    if (p != 0) {
        void* v = *(void**)((char*)p + 8);
        if (v != 0)
            return fn_803C7D10(v);
    }
    return -1;
}
