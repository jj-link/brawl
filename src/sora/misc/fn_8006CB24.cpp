#pragma force_active on

extern "C" {
extern void CXUncompressLZ(void*, void*);
extern void DCFlushRange(const void*, unsigned int);
extern int fn_8015E680(void*, int);
extern int isReady__14gfFileIOHandleCFv(void*);

extern unsigned char lbl_80497D7C[0x28];
extern unsigned char lbl_805A0198[4];
extern int lbl_805A01B0;
extern int lbl_805A01B4;
extern int lbl_805A01B8;

extern "C" int fn_8006CB24() {
    if (lbl_805A01B4 == 0) {
        return 1;
    }
    if (isReady__14gfFileIOHandleCFv(lbl_805A0198) == 0) {
        return 0;
    }
    CXUncompressLZ((void*)lbl_805A01B4, (void*)lbl_805A01B0);
    DCFlushRange((const void*)lbl_805A01B0, lbl_805A01B8);
    fn_8015E680(lbl_80497D7C, lbl_805A01B0);
    lbl_805A01B4 = 0;
    return 1;
}
}
