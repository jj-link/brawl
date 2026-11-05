#pragma force_active on

struct Resource {
    void* ptr;
    Resource() {}
    Resource(void* p) : ptr(p) {}
};
struct Handle { char* ptr; };

namespace first {
extern "C" int fn_8018CFAC(Resource*, const Resource*, void*);
}
namespace second {
extern "C" int fn_8018CFAC(Resource*, const Resource*);
}
extern char lbl_80465A20[0x20];

extern "C" int fn_8018D37C(const Handle* arg0, const Handle* arg1) {
    Resource data;
    Resource value(lbl_80465A20);
    data.ptr = arg0->ptr + 0x18;
    int result = first::fn_8018CFAC(&data, &value, arg0->ptr);
    if (result != 0) {
        Resource data2((void*)result);
        Resource value2(arg1->ptr);
        return second::fn_8018CFAC(&data2, &value2);
    }
    return 0;
}
