#pragma force_active on
extern "C" {

extern unsigned char lbl_91_data_2D8C[];

void fn_91_8B10(void* dest, int a, int b, int c) {
    *(void**)dest = lbl_91_data_2D8C;
    *(int*)((char*)dest + 0x10) = a;
    *(int*)((char*)dest + 0x14) = b;
    *(int*)((char*)dest + 0x18) = c;
}

}
