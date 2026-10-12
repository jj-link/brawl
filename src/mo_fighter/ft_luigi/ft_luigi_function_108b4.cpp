struct LuigiScaleResetPrefix {
    unsigned char reserved[8];
    float scale8;
    float scaleC;
};

extern "C" float fn_99_108B4(const LuigiScaleResetPrefix* object) {
    return object->scale8;
}
