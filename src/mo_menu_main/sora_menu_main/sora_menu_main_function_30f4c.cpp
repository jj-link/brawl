#pragma force_active on

extern "C" {
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned long, unsigned long, unsigned long);
void allocMsgBuf__5MuMsgFUlUl(void*, unsigned long, unsigned long);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, unsigned long, void*, unsigned long, float);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, unsigned long, unsigned char, unsigned char, unsigned char, unsigned char);
void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);
void fn_800B9488(void*, unsigned long, unsigned long);
void fn_8006B660(void*, int, int);
void getWScale__5MuMsgFUlf(void*, unsigned long, float);
extern float lbl_2_rodata_12D8;
extern float lbl_2_rodata_12DC;
}

extern "C" void fn_2_30F4C(void* self, void* data) {
    char* a10;
    char* s = (char*)self;
    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(3, 0x2a, 0x2a);
    *(void**)((char*)(*(void**)(s + 0x40)) + 0x164) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x100, 0x1d);
    setMsgData__5MuMsgFPv(msg, data);

    a10 = (char*)*(void**)((char*)(*(void**)(s + 0x40)) + 0x10);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0, *(void**)(a10 + 0x10), 0, lbl_2_rodata_12D8);
    fn_800B9488(msg, 0, 1);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 0, 0xff, 0xff, 0xff, 0xff);
    fn_8006B660(*(void**)((char*)msg + 0x8), 0, 7);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 1, *(void**)(a10 + 0x10), 1, lbl_2_rodata_12D8);
    fn_8006B660(*(void**)((char*)msg + 0x8), 1, 7);

    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 2, *(void**)((char*)(*(void**)((char*)(*(void**)(s + 0x40)) + 0x28)) + 0x10), 0, lbl_2_rodata_12D8);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 2, 0, 0, 0, 0xff);
    printIndex__5MuMsgFUlUlPv(msg, 2, 0x1b, 0);
    fn_8006B660(*(void**)((char*)msg + 0x8), 2, 7);

    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 3, *(void**)((char*)(*(void**)((char*)(*(void**)(s + 0x40)) + 0x2c)) + 0x10), 0, lbl_2_rodata_12D8);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 3, 0, 0, 0, 0xff);
    printIndex__5MuMsgFUlUlPv(msg, 3, 0x1b, 0);

    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 4, *(void**)((char*)(*(void**)((char*)(*(void**)(s + 0x40)) + 0x30)) + 0x10), 0, lbl_2_rodata_12D8);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 4, 0, 0, 0, 0xff);
    printIndex__5MuMsgFUlUlPv(msg, 4, 0x1c, 0);
    fn_8006B660(*(void**)((char*)msg + 0x8), 4, 7);

    for (int i = 0; i < 0xc; i++) {
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, i + 5, *(void**)((char*)(*(void**)((char*)(*(void**)(s + 0x40)) + 0x34 + i * 4)) + 0x10), 0, lbl_2_rodata_12D8);
        fn_8006B660(*(void**)((char*)msg + 0x8), i + 5, 7);
    }

    a10 = (char*)*(void**)((char*)(*(void**)(s + 0x40)) + 0x70);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0x11, *(void**)(a10 + 0x10), 0, lbl_2_rodata_12D8);
    for (int i = 0; i < 5; i++) {
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, i + 0x12, *(void**)(a10 + 0x10), i + 1, lbl_2_rodata_12D8);
        setFontColor__5MuMsgFUlUcUcUcUc(msg, i + 0x12, 0, 0, 0, 0xff);
        fn_8006B660(*(void**)((char*)msg + 0x8), i + 0x12, 7);
    }

    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0x17, *(void**)((char*)(*(void**)((char*)(*(void**)(s + 0x40)) + 0x74)) + 0x10), 0, lbl_2_rodata_12D8);
    getWScale__5MuMsgFUlf(msg, 0x17, lbl_2_rodata_12DC);
    fn_8006B660(*(void**)((char*)msg + 0x8), 0x17, 7);

    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0x18, *(void**)((char*)(*(void**)((char*)(*(void**)(s + 0x40)) + 0x78)) + 0x10), 0, lbl_2_rodata_12D8);
    fn_8006B660(*(void**)((char*)msg + 0x8), 0x18, 7);

    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0x19, *(void**)((char*)(*(void**)((char*)(*(void**)(s + 0x40)) + 0x7c)) + 0x10), 0, lbl_2_rodata_12D8);
    fn_8006B660(*(void**)((char*)msg + 0x8), 0x19, 7);

    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0x1a, *(void**)((char*)(*(void**)((char*)(*(void**)(s + 0x40)) + 0x80)) + 0x10), 0, lbl_2_rodata_12D8);
    fn_8006B660(*(void**)((char*)msg + 0x8), 0x1a, 7);

    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0x1b, *(void**)((char*)(*(void**)((char*)(*(void**)(s + 0x40)) + 0x84)) + 0x10), 0, lbl_2_rodata_12D8);
    fn_8006B660(*(void**)((char*)msg + 0x8), 0x1b, 7);

    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0x1c, *(void**)((char*)(*(void**)((char*)(*(void**)(s + 0x40)) + 0x98)) + 0x10), 0, lbl_2_rodata_12D8);
    fn_800B9488(msg, 0x1c, 1);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 0x1c, 0xff, 0xff, 0xff, 0xff);
    fn_8006B660(*(void**)((char*)msg + 0x8), 0x1c, 7);
}
