#pragma force_active on
struct ClassX {
    unsigned _0;
    unsigned _4;
    unsigned _x : 18;
    unsigned _y : 1;
    unsigned _z : 13;
};

extern "C" int fn_27_CF544(void* r3) {
    return ((ClassX*)r3)->_y;
}
