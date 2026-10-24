#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern const unsigned char lbl_27_rodata_6008[];
extern void* g_GameGlobal;

void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void fn_8006B660(void*, int, int);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
void fn_800B93DC(void*, u32, int);
void setHScale__5MuMsgFUlf(void*, u32, float);
void getHScale__5MuMsgFUlf(void*, u32, float);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);
void FUN_800b9448__5MuMsgFUlb(void*, u32, int);
void FUN_800b9460__5MuMsgFUlUcUcUcf(void*, u32, u8, u8, u8, float);
void fn_800B9488(void*, u32, u32);
void setHSpace__5MuMsgFUlf(void*, u32, float);
void fn_800B940C(void*, u32);
int fn_8004D9E8(void*);
}

extern "C" void fn_27_2C33C4(char* self, void* data)
{
    const unsigned char* ro = lbl_27_rodata_6008;
    *reinterpret_cast<void**>(self + 0x5c) = create__5MuMsgFUlQ25Heaps8HeapTypeUl(0, 0xe, 0x1f);
    allocMsgBuf__5MuMsgFUlUl(*reinterpret_cast<void**>(self + 0x5c), 0x200, 2);
    setMsgData__5MuMsgFPv(*reinterpret_cast<void**>(self + 0x5c), data);

    const u8* e = ro + 0x18;
    int i = 0;
    do {
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
            *reinterpret_cast<void**>(self + 0x5c), i,
            *reinterpret_cast<void**>(*reinterpret_cast<char**>(self + 0x54 + e[0] * 4) + 0x10),
            e[1], *reinterpret_cast<const float*>(ro + 0x30));
        fn_8006B660(*reinterpret_cast<void**>((char*)*reinterpret_cast<void**>(self + 0x5c) + 8), i, 7);
        setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(
            *reinterpret_cast<void**>(self + 0x5c), i,
            *reinterpret_cast<const u32*>(e + 4));
        fn_800B93DC(*reinterpret_cast<void**>(self + 0x5c), i,
            *reinterpret_cast<const u32*>(e + 8));
        setHScale__5MuMsgFUlf(*reinterpret_cast<void**>(self + 0x5c), i,
            *reinterpret_cast<const float*>(ro + 0x34));
        getHScale__5MuMsgFUlf(*reinterpret_cast<void**>(self + 0x5c), i,
            *reinterpret_cast<const float*>(ro + 0x34));
        switch (e[2]) {
        case 1:
            setFontColor__5MuMsgFUlUcUcUcUc(*reinterpret_cast<void**>(self + 0x5c), i, 0xff, 0xff, 0xff, 0xff);
            FUN_800b9448__5MuMsgFUlb(*reinterpret_cast<void**>(self + 0x5c), i, 1);
            FUN_800b9460__5MuMsgFUlUcUcUcf(*reinterpret_cast<void**>(self + 0x5c), i, 0, 0, 0, *reinterpret_cast<const float*>(ro + 0x38));
            break;
        case 2:
            setFontColor__5MuMsgFUlUcUcUcUc(*reinterpret_cast<void**>(self + 0x5c), i, 0x80, 0x80, 0x80, 0xff);
            break;
        case 3:
            setFontColor__5MuMsgFUlUcUcUcUc(*reinterpret_cast<void**>(self + 0x5c), i, 0, 0, 0, 0xff);
            break;
        }
        fn_800B9488(*reinterpret_cast<void**>(self + 0x5c), i, 3);
        setHSpace__5MuMsgFUlf(*reinterpret_cast<void**>(self + 0x5c), i,
            *reinterpret_cast<const float*>(ro + 0x3c));
        if (fn_8004D9E8(g_GameGlobal) == 0) {
            fn_800B940C(*reinterpret_cast<void**>(self + 0x5c), i);
        }
        ++i;
        e += 0xc;
    } while (i < 2);
}
