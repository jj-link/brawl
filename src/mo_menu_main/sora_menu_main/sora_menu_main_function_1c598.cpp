#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

extern "C" {
extern const float lbl_2_rodata_6D0[];
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);
void getWScale__5MuMsgFUlf(void*, u32, float);
void fn_800B9428(void*, u32, float);
void setHSpace__5MuMsgFUlf(void*, u32, float);
}

#define MSG (*reinterpret_cast<void**>(self + 0x688))
#define MODEL_AT(o) (*reinterpret_cast<void**>(*reinterpret_cast<char**>(*reinterpret_cast<char**>(self + 0x64c) + (o) + 0x1c4) + 0x10))

extern "C" void fn_2_1C598(char* self) {
    const float* ro = lbl_2_rodata_6D0;
    int idx;
    int off;
    int idx1;
    int i;
    void* msg;

    msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2A, 0x2B);
    *reinterpret_cast<void**>(self + 0x688) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x182, 8);
    setMsgData__5MuMsgFPv(MSG, *reinterpret_cast<void**>(self + 0x68c));
    i = 0;
    idx = 0;
    off = 0;
    for (; i < 4; i++) {
        idx1 = idx + 1;
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(MSG, idx, MODEL_AT(off), 0, ro[3]);
        setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(MSG, idx, 1);
        setFontColor__5MuMsgFUlUcUcUcUc(MSG, idx, 0xF0, 0xF0, 0xF0, 0xFF);
        getWScale__5MuMsgFUlf(MSG, idx, ro[4]);
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(MSG, idx1, MODEL_AT(off), 1, ro[5]);
        setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(MSG, idx1, 2);
        setFontColor__5MuMsgFUlUcUcUcUc(MSG, idx1, 0xD7, 0xD9, 0xE5, 0xFF);
        fn_800B9428(MSG, idx1, ro[6]);
        setHSpace__5MuMsgFUlf(MSG, idx1, ro[7]);
        idx += 2;
        off += 4;
    }
}
