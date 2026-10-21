#pragma force_active on
extern int lbl_80529858[];

void fn_802324CC(int arg0, int arg1) {
    *(int*)((char*)lbl_80529858 + ((arg0 * 4) & 0x3FC)) = arg1;
}
