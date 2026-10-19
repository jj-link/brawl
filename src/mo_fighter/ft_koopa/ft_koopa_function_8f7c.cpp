#include <types.h>
#pragma force_active on

struct FtKoopaPairMember {
    u32 storage[2];
};

struct FtKoopaPairArray {
    u32 header;
    FtKoopaPairMember members[2];
};

extern "C" void fn_27_57F78(FtKoopaPairMember* member);

extern "C" void fn_102_8F7C(FtKoopaPairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index]);
    }
}
