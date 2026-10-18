#pragma force_active on
struct Float2 {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_97_10B54(Float2 *object) { return object->first * object->second; }
