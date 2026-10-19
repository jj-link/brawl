#pragma force_active on
typedef unsigned int u32;

struct KoopaPairMember {
    u32 storage[2];
};

struct KoopaPairArray {
    u32 header;
    KoopaPairMember members[2];
};

extern "C" void fn_27_57ED8(KoopaPairMember* member, void* argument);

extern "C" void fn_102_8FD0(KoopaPairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
