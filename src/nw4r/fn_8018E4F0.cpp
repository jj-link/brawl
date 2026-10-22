#pragma force_active on
struct Resource {
    void* ptr;
    Resource(void* p) : ptr(p) {}
};
struct Handle { char* ptr; char* get() const { return ptr + 0x18; } };
extern "C" int fn_8018CFAC(Resource*, const Resource*, void*);
extern "C" unsigned char lbl_80465AE0[0x20];

extern "C" bool fn_8018E4F0(const Handle* arg) {
    Resource data(arg->get());
    Resource value(lbl_80465AE0);
    return fn_8018CFAC(&data, &value, arg->ptr) != 0;
}
