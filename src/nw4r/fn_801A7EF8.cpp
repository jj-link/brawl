#pragma force_active on
struct Data {
    char pad[0x70];
    unsigned int flags;
    char pad2[0x38];
    float ac, b0, b4;
    char pad3[4];
    float bc, c0, c4, c8, cc, d0, d4, d8;
};
extern "C" void fn_801ECCE8(float*, float, float, float, float, float, float, float, float);
extern "C" void fn_801ECB4C(float*, float, float, float, float, float, float, float, float, float);
extern "C" void fn_801ECBF0(float*, float, float, float, float, float, float);
extern "C" void fn_801A7EF8(Data** arg0, float* arg1) {
    Data* p;
    if (arg1 && (p = *arg0)) {
        if (p->flags & 0x40) {
            fn_801ECCE8(arg1, p->bc, p->c0, p->c4, p->c8, p->cc, -p->d0, p->d4, p->d8);
        } else if (p->flags & 0x10) {
            fn_801ECB4C(arg1, p->bc, p->c0, p->c4, p->c8, p->b4, p->cc, -p->d0, p->d4, p->d8);
        } else {
            fn_801ECBF0(arg1, p->ac, p->b0, p->cc, -p->d0, p->d4, p->d8);
        }
    }
}