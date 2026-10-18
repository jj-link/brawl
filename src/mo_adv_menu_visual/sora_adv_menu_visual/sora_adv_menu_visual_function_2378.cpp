#pragma force_active on
extern "C" int fn_800B61C0(void*);
extern "C" int fn_800B6310(void*);

struct Object {
    unsigned char pad[0x50];
    void* resource;
    unsigned char pad2[0x60];
    int fallback;
};

extern "C" int fn_29_2378(Object* object) {
    void* resource = object->resource;
    if (fn_800B61C0(resource) && fn_800B6310(resource)) {
        return 1;
    }
    return object->fallback;
}
