#pragma force_active on

namespace nw4r { namespace g3d {
struct Resource {
    char* ptr;
    Resource() {}
    Resource(void* p) : ptr((char*)p) {}
    bool valid() const {
        return (unsigned)(-(int)ptr | (int)ptr) >> 31;
    }
    char* get(int index) const {
        if (valid()) {
            int offset = *(int*)(ptr + ((index + 1) << 4) + 0x14);
            if (offset != 0)
                return ptr + offset;
            return 0;
        }
        return 0;
    }
};
struct ResFile {
    char* ptr;
    int GetResAnmVis(int);
};
}}
extern "C" int fn_8018CFAC(nw4r::g3d::Resource*, const nw4r::g3d::Resource*, void*);
extern char lbl_80465A80[0x20];

using nw4r::g3d::Resource;
extern "C" int GetResAnmVis__Q34nw4r3g3d7ResFileFi(const nw4r::g3d::ResFile* self, int arg1) {
    char* base = self->ptr;
    Resource data;
    Resource value(lbl_80465A80);
    data.ptr = base + 0x18;
    Resource result((void*)fn_8018CFAC(&data, &value, base));
    if (result.ptr != 0) {
        return (int)result.get(arg1);
    }
    return 0;
}
