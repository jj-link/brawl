struct LuigiScaleResetPrefix {
    unsigned char reserved[8];
    float scale8;
    float scaleC;
};

extern "C" float fn_99_108C4(LuigiScaleResetPrefix* object) {
    return object->scale8 * object->scaleC;
}
