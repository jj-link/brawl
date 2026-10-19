#pragma force_active on
struct KirbyPairMember {
    unsigned int storage[2];
};

struct KirbyPairArray {
    unsigned int header;
    KirbyPairMember members[2];
};

extern "C" KirbyPairMember* fn_96_F214(KirbyPairArray* array, int index) {
    return &array->members[index];
}
