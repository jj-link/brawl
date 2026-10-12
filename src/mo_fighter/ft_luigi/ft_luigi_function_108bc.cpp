struct LuigiScaleResetPrefix {
    unsigned char reserved[8];
    float scale8;
    float scaleC;
};

extern "C" void fn_99_108BC(LuigiScaleResetPrefix* object, float scale) {
    object->scale8 = scale;
}
