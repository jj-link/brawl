#pragma force_active on

typedef signed int s32;

namespace nw4r {
namespace g3d {
class ResMdl {
    void* unk0;
public:
    void GetResNode(const char* arg) const;
};
}
}

extern "C" void fn_8018CF30(void**);

namespace nw4r {
namespace g3d {
void ResMdl::GetResNode(const char* arg) const {
    void* p = unk0;
    void* result;
    s32 offset = *(s32*)((char*)p + 0x14);
    if (offset != 0) {
        result = (void*)((char*)p + offset);
    } else {
        result = (void*)0;
    }
    fn_8018CF30(&result);
}
}
}
