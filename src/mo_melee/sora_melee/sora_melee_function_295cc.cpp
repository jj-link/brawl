#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

struct Result {
    u32 padding[8];
    u64 value;
    u32 tail[4];
};

struct Resource {
    u32 unused;
    void* data;
};

struct Interface {
    virtual ~Interface();
    virtual Resource* get();
};

struct Object {
    u32 padding[10];
    Interface* resource;
};

extern "C" void fn_801341D8(void*, Result*);

extern "C" u64 fn_27_295CC(const Object& self) {
    Result result;
    fn_801341D8(self.resource->get()->data, &result);
    return result.value;
}
