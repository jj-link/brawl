#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct TourObject {
    char pad0[4];
    void* model;
    char pad1[0xB68];
    Vec3f source;
    Vec3f position;
};

extern "C" void fn_800B6838(void*, const Vec3f*);

extern "C" void fn_3_175C(TourObject* object, int update)
{
    object->position.x = object->source.x;
    object->position.y = object->source.y;
    object->position.z = object->source.z;

    if (update != 0) {
        fn_800B6838(object->model, &object->position);
    }
}
