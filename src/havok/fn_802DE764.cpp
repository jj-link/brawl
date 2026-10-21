#pragma force_active on
extern unsigned char lbl_80487BB8[];

extern "C" {
void fn_802DE764(void* arg0, signed char arg1) {
    *(short*)((char*)arg0 + 0x6) = 1;
    *(void**)arg0 = lbl_80487BB8;
    *(int*)((char*)arg0 + 0x8) = 0;
    *(int*)((char*)arg0 + 0x10) = 0;
    *(signed char*)((char*)arg0 + 0x1C) = arg1;
    *(char*)((char*)arg0 + 0x1D) = 0;
    *(int*)((char*)arg0 + 0x20) = 0;
    *(int*)((char*)arg0 + 0x24) = 0;
    *(int*)((char*)arg0 + 0x28) = 0;
}
}
