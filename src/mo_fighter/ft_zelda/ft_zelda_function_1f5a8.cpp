#pragma force_active on
struct NessTransitionVector { float x; float y; };

extern "C" float fn_104_1F5A8(const NessTransitionVector* vector) {
    return vector->x * vector->x + vector->y * vector->y;
}
