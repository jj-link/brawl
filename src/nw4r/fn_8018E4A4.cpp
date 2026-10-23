#pragma force_active on
struct Resource {
    void* ptr;
    Resource(void* p) : ptr(p) {}
};
extern "C" int fn_8018CFAC(Resource*, const Resource*, void*);
extern char lbl_80465AC0[0x20];

struct Handle { char* ptr; };

extern "C" bool fn_8018E4A4(const Handle* arg0) {
    Resource data(arg0->ptr + 0x18);
    Resource value(lbl_80465AC0);
    return fn_8018CFAC(&data, &value, arg0->ptr) != 0;
}
