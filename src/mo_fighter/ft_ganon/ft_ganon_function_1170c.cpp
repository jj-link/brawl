#pragma force_active on
struct Float2 {
    float pad[2];
    float x;
    float y;
};

extern "C" float fn_109_1170C(Float2 *obj) {
    return obj->x * obj->y;
}
