#pragma force_active on
struct Element {
    unsigned char data[0x38];
};

extern "C" unsigned char* fn_48_BDD0(Element* array, int index) {
    return array[index].data + 0x0C;
}
