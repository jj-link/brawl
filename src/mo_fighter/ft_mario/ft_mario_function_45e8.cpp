#pragma force_active on
extern "C" {
extern unsigned char lbl_91_data_2938[];
void fn_91_1A70(void* object, unsigned char value);

void* fn_91_45E8(void* object, int a, int b, int c, int d, int e, int f) {
    unsigned char* self = static_cast<unsigned char*>(object);
    fn_91_1A70(object, 0);
    *reinterpret_cast<unsigned char**>(self + 0x8) = lbl_91_data_2938;
    *reinterpret_cast<unsigned char**>(self + 0x0) = lbl_91_data_2938 + 8;
    *reinterpret_cast<int*>(self + 0xc) = a;
    *reinterpret_cast<int*>(self + 0x10) = b;
    *reinterpret_cast<int*>(self + 0x14) = c;
    *reinterpret_cast<int*>(self + 0x18) = d;
    *reinterpret_cast<int*>(self + 0x1c) = e;
    *reinterpret_cast<int*>(self + 0x20) = f;
    return object;
}
}
