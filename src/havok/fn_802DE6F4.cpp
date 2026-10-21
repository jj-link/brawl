#pragma force_active on
extern "C" {
extern unsigned char lbl_80487BB8[];

void fn_802DE6F4(void* arg0) {
    if (arg0 != 0) {
        *(unsigned short*)((char*)arg0 + 6) = 1;
        *(void**)arg0 = lbl_80487BB8;
    }
}
}
