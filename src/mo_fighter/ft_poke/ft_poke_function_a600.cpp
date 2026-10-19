#include <types.h>
#pragma force_active on

struct FtPokeMember {
    u32 storage[2];
};

struct FtPokeArray {
    u32 header;
    FtPokeMember members[2];
};

extern "C" void fn_27_57F78(FtPokeMember* member);

extern "C" void fn_116_A600(FtPokeArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index]);
    }
}
