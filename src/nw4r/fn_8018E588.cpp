#pragma force_active on
struct Resource {
    void* ptr;
    Resource(void* p) : ptr(p) {}
};
extern "C" int fn_8018CFAC(Resource*, const Resource*, void*);
extern char lbl_80465B20[0x40];

struct Handle { char* ptr; };

extern "C" bool fn_8018E588(const Handle* arg0) {
    char* base = arg0->ptr;
    Resource data(base + 0x18);
    Resource value(lbl_80465B20);
    return fn_8018CFAC(&data, &value, base) != 0;
}
