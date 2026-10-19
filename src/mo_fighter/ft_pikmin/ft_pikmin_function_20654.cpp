#pragma force_active on
struct FtPikminVec {
    char pad[8];
    float x;
    float y;
    float z;
};

extern "C" void fn_113_1E208(void* dst, void* src);

extern "C" FtPikminVec* fn_113_20654(FtPikminVec* dst, FtPikminVec* src) {
    fn_113_1E208(dst, src);
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    return dst;
}
