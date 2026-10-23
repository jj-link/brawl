#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct MsgObj { char pad[8]; void* unk8; };

extern "C" {
MsgObj* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(MsgObj*, u32, u32);
void setMsgData__5MuMsgFPv(MsgObj*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(MsgObj*, u32, void*, u32, float);
void fn_8006B660(void*, int, int);
void setFontColor__5MuMsgFUlUcUcUcUc(MsgObj*, u32, u8, u8, u8, u8);
void FUN_800b9448__5MuMsgFUlb(MsgObj*, u32, int);
void FUN_800b9460__5MuMsgFUlUcUcUcf(MsgObj*, u32, u8, u8, u8, float);
void fn_800B9488(MsgObj*, u32, int);
void getWScale__5MuMsgFUlf(MsgObj*, u32, float);
void printIndex__5MuMsgFUlUlPv(MsgObj*, u32, u32, void*);
extern char g_HeapInfos[];
extern u8 lbl_80408CD0[];
extern float lbl_805A25C4;
extern float lbl_805A25C8;
extern float lbl_805A25CC;
}

extern "C" void fn_800F1ECC(u8* self, void* data, u32 arg2, u32 arg3) {
    u8* e;
    u32 i;
    int var_r29;
    u32 flag;

    if (*(int*)(g_HeapInfos + 0x2f0) != 0 || *(int*)(g_HeapInfos + 0x310) != 0) {
        flag = 1;
        var_r29 = 0;
    } else {
        flag = 8;
        var_r29 = 4;
    }
    *(MsgObj**)(self + 0x8c) = create__5MuMsgFUlQ25Heaps8HeapTypeUl(flag, arg2, arg3);
    allocMsgBuf__5MuMsgFUlUl(*(MsgObj**)(self + 0x8c), 0x200, 0xa);
    setMsgData__5MuMsgFPv(*(MsgObj**)(self + 0x8c), data);
    i = 0;
    e = lbl_80408CD0;
    do {
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
            *(MsgObj**)(self + 0x8c), i,
            *(void**)(*(u8**)(self + e[0] * 4 + 0x44) + 0x10),
            e[1], lbl_805A25C4);
        fn_8006B660(((MsgObj*)*(void**)(self + 0x8c))->unk8, i, 7);
        switch (e[2]) {
        case 1:
            setFontColor__5MuMsgFUlUcUcUcUc(*(MsgObj**)(self + 0x8c), i, 0xff, 0xff, 0xff, 0xff);
            FUN_800b9448__5MuMsgFUlb(*(MsgObj**)(self + 0x8c), i, 1);
            FUN_800b9460__5MuMsgFUlUcUcUcf(*(MsgObj**)(self + 0x8c), i, 0, 0, 0, lbl_805A25C8);
            break;
        case 2:
            setFontColor__5MuMsgFUlUcUcUcUc(*(MsgObj**)(self + 0x8c), i, 0x80, 0x80, 0x80, 0xff);
            break;
        }
        fn_800B9488(*(MsgObj**)(self + 0x8c), i, var_r29);
        i++;
        e += 3;
    } while ((int)i < 9);
    getWScale__5MuMsgFUlf(*(MsgObj**)(self + 0x8c), 4, lbl_805A25CC);
    getWScale__5MuMsgFUlf(*(MsgObj**)(self + 0x8c), 5, lbl_805A25CC);
    getWScale__5MuMsgFUlf(*(MsgObj**)(self + 0x8c), 3, lbl_805A25CC);
    printIndex__5MuMsgFUlUlPv(*(MsgObj**)(self + 0x8c), 6, 0x47, 0);
    printIndex__5MuMsgFUlUlPv(*(MsgObj**)(self + 0x8c), 7, 0x48, 0);
    printIndex__5MuMsgFUlUlPv(*(MsgObj**)(self + 0x8c), 8, 0x49, 0);
}
