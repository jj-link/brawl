#pragma force_active on
extern "C" {
extern unsigned char lbl_101_data_38CC[];
void fn_101_9210(void*, int);
}

extern "C" void* fn_101_A4CC(void* object, int a1, int a2, int a3, int a4, int a5, int a6) {
    unsigned char* p = static_cast<unsigned char*>(object);
    fn_101_9210(object, 0);
    void* base = lbl_101_data_38CC;
    *reinterpret_cast<void**>(p + 0x8) = base;
    *reinterpret_cast<void**>(p + 0x0) = static_cast<unsigned char*>(base) + 0x8;
    *reinterpret_cast<int*>(p + 0xC) = a1;
    *reinterpret_cast<int*>(p + 0x10) = a2;
    *reinterpret_cast<int*>(p + 0x14) = a3;
    *reinterpret_cast<int*>(p + 0x18) = a4;
    *reinterpret_cast<int*>(p + 0x1C) = a5;
    *reinterpret_cast<int*>(p + 0x20) = a6;
    return object;
}
