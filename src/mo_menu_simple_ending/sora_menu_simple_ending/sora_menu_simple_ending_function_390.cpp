#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern "C" {
extern char lbl_19_data_0[];
extern const float lbl_19_rodata_0[];
extern void* g_GameGlobal;

void* fn_800AFBFC(const void*, u32, void*, u32);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(void*, const char*, int, void*, int);
void fn_800B7184(void*, const char*, u32, void*);
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);
void FUN_800b9448__5MuMsgFUlb(void*, u32, int);
void FUN_800b9460__5MuMsgFUlUcUcUcf(void*, u32, u8, u8, u8, float);
void printf__5MuMsgFUlPCce(void*, u32, const char*, ...);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void* fn_800B6AC0(void*, const char*);
void fn_80192ECC(void*, float, float, float);
}

extern "C" void fn_19_390(u8* self, void* archive) {
    const float* ro = lbl_19_rodata_0;
    *reinterpret_cast<void**>(self + 0x48) =
        fn_800AFBFC(lbl_19_data_0 + 0x4C, 0x10, archive, 0);
    *reinterpret_cast<void**>(self + 0x40) =
        getData__9gfArchiveF11ARCNodeTypeiUs(archive, 2, 3, 0xFFFE);
    *reinterpret_cast<void**>(self + 0x44) =
        getData__9gfArchiveF11ARCNodeTypeiUs(archive, 2, 4, 0xFFFE);
    Init__Q34nw4r3g3d7ResFileFPv(self + 0x40);
    Init__Q34nw4r3g3d7ResFileFPv(self + 0x44);
    void* obj = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
            self + 0x40, lbl_19_data_0 + 0x58, 1, 0, 0x2A);
    *reinterpret_cast<void**>(self + 0x4C) = obj;
    fn_800B7184(obj, lbl_19_data_0 + 0x70, 0, self + 0x44);
    *reinterpret_cast<void**>(self + 0x50) =
        create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2A, 0x2B);
    allocMsgBuf__5MuMsgFUlUl(*reinterpret_cast<void**>(self + 0x50), 0x200, 1);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
        *reinterpret_cast<void**>(self + 0x50), 0,
        *reinterpret_cast<void**>(*reinterpret_cast<u8**>(self + 0x4C) + 0x10),
        0, ro[1]);
    setFontColor__5MuMsgFUlUcUcUcUc(*reinterpret_cast<void**>(self + 0x50), 0, 0xFF, 0xFF, 0xFF, 0xFF);
    FUN_800b9448__5MuMsgFUlb(*reinterpret_cast<void**>(self + 0x50), 0, 1);
    FUN_800b9460__5MuMsgFUlUcUcUcf(*reinterpret_cast<void**>(self + 0x50), 0, 0, 0, 0, ro[2]);
    printf__5MuMsgFUlPCce(*reinterpret_cast<void**>(self + 0x50), 0, lbl_19_data_0 + 0x7C);

    u8* rec = reinterpret_cast<u8*>(getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal));
    u32 bit = (rec[0x28] >> 7) & 1;
    if (bit == 1) {
        void* n = fn_800B6AC0(*reinterpret_cast<void**>(self + 0x4C), lbl_19_data_0 + 0x80);
        fn_80192ECC(&n, ro[3], ro[3], ro[0]);
    }
}
