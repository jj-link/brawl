#pragma force_active on
extern "C" void fn_80012504(void* a, void* b);
extern int lbl_804207DC[7];
extern void* lbl_8059FF90;

extern "C" void* fn_80010E50(void* p, int flag) {
    if (p) {
        unsigned char f = *((unsigned char*)p + 0x1C);
        *(int**)((char*)p + 0x44) = lbl_804207DC;
        if ((unsigned int)((f >> 4) & 1) == 1U) {
            fn_80012504(lbl_8059FF90, p);
            *((unsigned char*)p + 0x1C) &= ~0x10;
        }
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
