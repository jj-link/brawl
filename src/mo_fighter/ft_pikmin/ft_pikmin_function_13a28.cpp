#pragma force_active on
struct PikminPairMember {
    unsigned int storage[2];
};

struct PikminPairArray {
    unsigned int header[3];
    PikminPairMember members[1];
};

extern "C" PikminPairMember* fn_113_13A28(PikminPairArray* array, int index) {
    return &array->members[index];
}
