#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Sub { char pad[0x10]; void* m10; };

extern "C" {
extern const float lbl_2_rodata_1698[];
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void getWScale__5MuMsgFUlf(void*, u32, float);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);
void fn_800B9488(void*, u32, u32);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
void fn_800B9428(void*, u32, float);

void fn_2_38A54(char* self, void* data) {
    const float* ro = lbl_2_rodata_1698;
    Sub* p;
    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    *(void**)(self + 0x74) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x168, 0x7);
    setMsgData__5MuMsgFPv(msg, data);
    p = (Sub*)*(void**)(self + 0x44);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0, p->m10, 0, ro[0xbc / 4]);
    getWScale__5MuMsgFUlf(msg, 0, ro[0xc0 / 4]);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 0, 0x35, 0x47, 0x26, 0xff);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 1, p->m10, 1, ro[0xbc / 4]);
    getWScale__5MuMsgFUlf(msg, 1, ro[0xc0 / 4]);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 1, 0x35, 0x47, 0x26, 0xff);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 2, p->m10, 2, ro[0xbc / 4]);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 3, p->m10, 3, ro[0xbc / 4]);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 4, p->m10, 4, ro[0xbc / 4]);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 4, 0x35, 0x47, 0x26, 0xff);
    getWScale__5MuMsgFUlf(msg, 4, ro[0xc0 / 4]);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 5, p->m10, 5, ro[0xbc / 4]);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 5, 0, 0, 0, 0xff);
    if (*(int*)(self + 0x40) == 0) {
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(*(void**)(self + 0x74), 6, ((Sub*)*(void**)(self + 0x4c))->m10, 0, ro[0xbc / 4]);
        fn_800B9488(*(void**)(self + 0x74), 6, 1);
        setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(*(void**)(self + 0x74), 6, 1);
        fn_800B9428(*(void**)(self + 0x74), 6, ro[0xc4 / 4]);
        setFontColor__5MuMsgFUlUcUcUcUc(*(void**)(self + 0x74), 6, 0x80, 0x80, 0x80, 0xff);
    }
}
}