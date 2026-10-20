#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

struct Result {
    u64 value;
    u32 pad[10];
};

struct Resource {
    u32 unused;
    void* data;
};

struct Interface {
    virtual Resource* unused();
    virtual Resource* get();
};

struct Object {
    u32 pad[10];
    Interface* resource;
};

extern "C" void fn_801341D8(void*, Result*);

extern "C" u64 fn_27_2972C(const Object& self) {
    Result result;
    fn_801341D8(self.resource->get()->data, &result);
    return result.value;
}
