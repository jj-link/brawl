#pragma force_active on
struct IceClimberPairMember {
    unsigned int storage[2];
};

struct IceClimberPairArray {
    unsigned int header;
    IceClimberPairMember members[2];
};

extern "C" IceClimberPairMember* fn_105_DB08(IceClimberPairArray* array, int index) {
    return &array->members[index];
}
