#pragma force_active on
struct IkePairMember {
    unsigned int storage[2];
};

struct IkePairArray {
    unsigned int header;
    IkePairMember members[2];
};

extern "C" IkePairMember* fn_119_9750(IkePairArray* array, int index) {
    return &array->members[index];
}
