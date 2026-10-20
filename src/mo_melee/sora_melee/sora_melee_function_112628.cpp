#pragma force_active on
extern "C" {

struct S {
    unsigned char _pad[0x800];
    float f;
};

float fn_27_112628(S** p) {
    return (*p)->f;
}

}
