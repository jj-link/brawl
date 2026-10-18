#pragma force_active on
struct ZakoMember {
    unsigned int storage[2];
};

extern "C" unsigned int* fn_126_72C8(ZakoMember* array, int index) {
    return &array[index].storage[1];
}
