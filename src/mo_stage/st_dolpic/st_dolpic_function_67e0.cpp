#pragma force_active on
struct Vec3Holder {
    unsigned char pad[0x10];
    float x;
    float y;
    float z;
};

extern "C" Vec3Holder* fn_46_67E0(Vec3Holder* holder, float x, float y, float z) {
    holder->x = x;
    holder->y = y;
    holder->z = z;
    return holder;
}
