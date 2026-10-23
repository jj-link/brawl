#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" {
    void* getInstance__8ipSwitchFv(void);
    void netReport__FPCce(const char*, ...);
    void fn_8004B23C(void*, void**, int*);
    void fn_8004C050(int);
    u8 fn_8014F8E8(void);
    void fn_80152B5C(void*, int);
    void fn_80152BDC(void*, int);
    void fn_80152C4C(void*, int, int);
    void fn_80153488(void*);
    void fn_80153498(void*, int);
    void fn_80153610(void*, void*, u64, int, int, int);
    void fn_80153E2C(void*, int);
    void fn_80153E3C(void*, int);
    void fn_80153EC4(void*, void*);
    int fn_80153810(void*);
    int fn_80154018(void*);
    int fn_80154104(void*, int);
    void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(int, int, int);
    u64 OSGetTime(void);
    extern char lbl_80461718[];
}

extern "C" int fn_80155F54(void* arg0, void** arg1, int* arg2) {
    const char* base = lbl_80461718;
    int spC = 0;
    int sp8 = 0;
    char sp10[8];
    char sp18[0x14];
    char sp2C[0xB4];
    u8* inst;
    u16 lim;
    int type;
    void* heap;

    inst = (u8*)getInstance__8ipSwitchFv();
    if (((u8*)*(void**)(inst + 0x18))[0x3B] != 0) {
        netReport__FPCce(base + 0x408);
        return 0;
    }
    inst = (u8*)getInstance__8ipSwitchFv();
    fn_8004B23C(*(void**)(inst + 0x18), (void**)&spC, &sp8);
    fn_8004C050(spC);
    lim = (u16)((u8)fn_8014F8E8() * 0xE10 + 0x168);
    if (*(u16*)(*(u8**)(*(u8**)((u8*)getInstance__8ipSwitchFv() + 0x18) + 0x24) + 6) > lim) {
        netReport__FPCce(base + 0x438);
        return 0;
    }
    fn_80152B5C(sp18, 0x2A);
    fn_80152C4C(sp18, spC, sp8);
    fn_80153488(sp10);
    {
        u64 t = OSGetTime();
        fn_80153610(sp10, sp18, t, 0x2A, 0, 0);
    }
    fn_80153E2C(sp2C, 0x2A);
    if (fn_80154104(sp2C, fn_80153810(sp10)) == 0) {
        netReport__FPCce(base + 0x458);
        fn_80153E3C(sp2C, -1);
        fn_80153498(sp10, -1);
        fn_80152BDC(sp18, -1);
        return 0;
    }
    type = fn_80154018(sp2C);
    heap = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(0x2A, type, 0x20);
    if (heap == 0) {
        netReport__FPCce(base + 0x470);
        fn_80153E3C(sp2C, -1);
        fn_80153498(sp10, -1);
        fn_80152BDC(sp18, -1);
        return 0;
    }
    fn_80153EC4(sp2C, heap);
    *arg2 = type;
    *arg1 = heap;
    fn_80153E3C(sp2C, -1);
    fn_80153498(sp10, -1);
    fn_80152BDC(sp18, -1);
    return 1;
}
