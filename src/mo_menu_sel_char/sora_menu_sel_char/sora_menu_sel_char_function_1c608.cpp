#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void fn_18_10E0(void*, void*, void*);
extern u8 lbl_10_data_CF8[];
extern float lbl_10_rodata_8A0;

void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
    void*, u32, void*, u32, float);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);
void FUN_800b9448__5MuMsgFUlb(void*, u32, u8);
}

extern "C" void* fn_10_1C608(void* arg0, void* arg1, void* arg2) {
    u8* self = (u8*)arg0;

    fn_18_10E0(arg0, arg1, arg2);

    u32 flags = self[0x2C];
    flags &= 0xFFFFFFFDu;

    *(void**)(self + 0x3C) = lbl_10_data_CF8;
    *(void**)(self + 0x4C) = arg1;
    self[0x50] = 0;
    self[0x2C] = (u8)flags;

    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2A, 0x2B);
    *(void**)(self + 0x48) = msg;

    allocMsgBuf__5MuMsgFUlUl(msg, 0x200, 1);
    setMsgData__5MuMsgFPv(*(void**)(self + 0x48), arg2);

    u8* data = (u8*)*(void**)(self + 0x4C);
    void* model = *(void**)(data + 0x10);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
        *(void**)(self + 0x48), 0, model, 0, lbl_10_rodata_8A0);

    setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(*(void**)(self + 0x48), 0, 0);
    setFontColor__5MuMsgFUlUcUcUcUc(
        *(void**)(self + 0x48), 0, 0x2F, 0x2E, 0x2E, 0xFF);
    FUN_800b9448__5MuMsgFUlb(*(void**)(self + 0x48), 0, 0);

    self[0x50] = 1;
    return arg0;
}
