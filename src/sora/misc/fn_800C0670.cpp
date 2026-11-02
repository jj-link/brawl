#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Inner { char pad[0x10]; void* m10; };
struct Self { char pad0[0x40]; Inner* p40; char pad1[0x18]; void* msg; };

extern "C" {
extern float lbl_805A22D8;
extern float lbl_805A22DC;
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void getWScale__5MuMsgFUlf(void*, u32, float);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);

void fn_800C0670(Self* self, void* data) {
    Inner* p;
    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    setMsgData__5MuMsgFPv(msg, data);
    self->msg = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x168, 4);
    p = self->p40;
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0, p->m10, 0, lbl_805A22D8);
    getWScale__5MuMsgFUlf(msg, 0, lbl_805A22DC);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 0, 0, 0, 0, 0xff);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 1, p->m10, 1, lbl_805A22D8);
    getWScale__5MuMsgFUlf(msg, 1, lbl_805A22DC);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 1, 0, 0, 0, 0xff);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 2, p->m10, 2, lbl_805A22D8);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 2, 0, 0, 0, 0xff);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 3, p->m10, 3, lbl_805A22D8);
    setFontColor__5MuMsgFUlUcUcUcUc(msg, 3, 0, 0, 0, 0xff);
}
}
