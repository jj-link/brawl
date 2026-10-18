#pragma force_active on
// Constant remains owned by the original module's read-only data unit.
extern "C" const float lbl_105_rodata_88;

struct FtIceClimberScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_105_18340(FtIceClimberScalarPair* object) {
    object->first = object->second = lbl_105_rodata_88;
}
