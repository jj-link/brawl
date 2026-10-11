#include <mt/mt_vector.h>
#include <types.h>

class snd3DGenerator;

struct MetaKnightSoundGeneratorHandle {
    s32 id;
    snd3DGenerator* generator;
};

struct MetaKnightSoundGeneratorPair {
    void* vtable;
    MetaKnightSoundGeneratorHandle handles[2];
};

static_assert(sizeof(MetaKnightSoundGeneratorHandle) == 8,
              "Original sound generator handle stride");
static_assert(sizeof(MetaKnightSoundGeneratorPair) == 20,
              "Original fixed sound generator pair layout");

extern "C" void fn_27_57F78(MetaKnightSoundGeneratorHandle* handle);
extern "C" void fn_27_57ED8(MetaKnightSoundGeneratorHandle* handle, Vec3f* position);

extern "C" MetaKnightSoundGeneratorHandle* fn_111_865C(
    MetaKnightSoundGeneratorPair* pair, s32 index) {
    return &pair->handles[index];
}

extern "C" void fn_111_866C(MetaKnightSoundGeneratorPair* pair) {
    for (s32 index = 0; index < 2; ++index) {
        fn_27_57F78(&pair->handles[index]);
    }
}

extern "C" void fn_111_86C0(MetaKnightSoundGeneratorPair* pair, Vec3f* position) {
    for (s32 index = 0; index < 2; ++index) {
        fn_27_57ED8(&pair->handles[index], position);
    }
}
