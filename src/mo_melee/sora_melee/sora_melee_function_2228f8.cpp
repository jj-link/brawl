#pragma force_active on
struct GrCollisionList {
    void* first;
    void* second;
    void* third;
};
extern "C" GrCollisionList g_grCollisionList;
extern "C" void* fn_27_2228F8() {
    return g_grCollisionList.first;
}
