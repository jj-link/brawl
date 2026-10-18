#pragma force_active on
struct GwMember {
    unsigned char data[0x78];
};

struct GwArray {
    unsigned char header[0x0C];
    GwMember members[1];
};

extern "C" GwMember* fn_63_AFC0(GwArray* array, int index) {
    return &array->members[index];
}
