#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void* getData__9gfArchiveF11ARCNodeTypeiUs(void* arch, int type, int index, u16 n);
}

namespace nw4r {
namespace g3d {
class ResFileData;
}
}

class Stage {
public:
    void registScnAnim(nw4r::g3d::ResFileData* data, unsigned long idx);
};

extern "C" {
void fn_46_3FF0(Stage* self, u32 n, u32 flag);
}

void fn_46_3FF0(Stage* self, u32 n, u32 flag) {
    u8* p = (u8*)self;
    if (n < 0x10) {
        if (*(p + 0x1d9) != n || flag != 0) {
            void* arch = *(void**)(p + 0x1a0);
            nw4r::g3d::ResFileData* data =
                (nw4r::g3d::ResFileData*)getData__9gfArchiveF11ARCNodeTypeiUs(arch, 5, 0, (u16)0xFFFE);
            self->registScnAnim(data, n);
            *(p + 0x1d9) = (u8)n;
        }
    }
}
