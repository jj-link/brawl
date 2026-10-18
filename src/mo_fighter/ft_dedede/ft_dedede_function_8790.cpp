#pragma force_active on
extern "C" {
extern unsigned char lbl_117_data_3B38[];
}

extern "C" void fn_117_8790(void* self, void* a, void* b, void* c) {
    *(void**)self = lbl_117_data_3B38;
    *(void**)((char*)self + 0x10) = a;
    *(void**)((char*)self + 0x14) = b;
    *(void**)((char*)self + 0x18) = c;
}
