#pragma force_active on
extern "C" {
extern unsigned char lbl_106_data_120C[];
}

extern "C" void fn_106_6D4C(void* self, void* a, void* b, void* c) {
    *(void**)self = lbl_106_data_120C;
    *(void**)((char*)self + 0x10) = a;
    *(void**)((char*)self + 0x14) = b;
    *(void**)((char*)self + 0x18) = c;
}
