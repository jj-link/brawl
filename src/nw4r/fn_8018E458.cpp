#pragma force_active on
struct Resource {
    void* ptr;
    Resource(void* p) : ptr(p) {}
};
extern "C" int fn_8018CFAC(Resource*, const Resource*, void*);
extern char lbl_80465AA0[0x20];
struct Handle { char* ptr; };
extern "C" bool fn_8018E458(const Handle* arg0) {
    Resource data(arg0->ptr + 0x18);
    Resource value(lbl_80465AA0);
    return fn_8018CFAC(&data, &value, arg0->ptr) != 0;
}
