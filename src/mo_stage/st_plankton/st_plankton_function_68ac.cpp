#pragma force_active on
struct Element {
    unsigned char data[0xA0];
};

extern "C" void* fn_74_68AC(Element* array, int index) {
    return array[index].data + 0x0C;
}
