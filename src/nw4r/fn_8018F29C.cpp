#pragma force_active on
struct Obj { char pad[0x28]; int off; };
struct Resource {
    void* ptr;
    Resource(void* p) : ptr(p) {}
};
struct Handle {
    Obj* ptr;
    void* get() const {
        int offset = ptr->off;
        return offset ? (char*)ptr + offset : 0;
    }
};
extern "C" int fn_8018CFAC(Resource*, const Resource*, void*);
extern "C" int fn_8018F29C(const Handle* a, const Resource* b)
{
    Resource data(a->get());
    Resource value = *b;
    return fn_8018CFAC(&data, &value, value.ptr);
}
