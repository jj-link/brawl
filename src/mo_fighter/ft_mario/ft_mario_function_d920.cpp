#pragma force_active on
struct MarioSubobject {
    unsigned char prefix[12];
};
extern "C" void* fn_91_D920(MarioSubobject* obj, int flag) {
    if (flag == 0) return obj + 1;
    return 0;
}
