// Read the scale C component from the scale reset prefix.
struct LuigiScaleResetPrefix {
    unsigned char reserved[8];
    float scale8;
    float scaleC;
};

extern "C" float fn_99_108A4(const LuigiScaleResetPrefix* object) {
    return object->scaleC;
}
