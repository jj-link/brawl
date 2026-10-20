#pragma force_active on

struct Unknown {
    unsigned char pad[0x834];
    float f834;
};

extern "C" float fn_27_112BEC(Unknown** p) {
    return (*p)->f834;
}
