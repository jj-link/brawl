#pragma force_active on

extern "C" {
extern void CXUncompressLZ(void*, void*);
extern void DCFlushRange(const void*, unsigned int);
extern int fn_8015E680(void*, int);
extern int isReady__14gfFileIOHandleCFv(void*);

extern unsigned char lbl_80497D54[0x28];
extern unsigned char lbl_805A0194[4];
extern int lbl_805A01A4;
extern int lbl_805A01A8;
extern int lbl_805A01AC;

extern "C" int fn_8006CAA8() {
    if (lbl_805A01A8 == 0) {
        return 1;
    }
    if (isReady__14gfFileIOHandleCFv(lbl_805A0194) == 0) {
        return 0;
    }
    CXUncompressLZ((void*)lbl_805A01A8, (void*)lbl_805A01A4);
    DCFlushRange((const void*)lbl_805A01A4, lbl_805A01AC);
    fn_8015E680(lbl_80497D54, lbl_805A01A4);
    lbl_805A01A8 = 0;
    return 1;
}
}