#pragma force_active on
typedef signed short s16;
typedef int s32;

namespace {
struct FalcoSub {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    unsigned char hidden;
    bool isEnabled() const { return enabled; }
};
}

extern "C" void fn_108_DF20(void* object, void* argument);
extern "C" void fn_108_E490(s16* destination, const s16* source);
extern "C" s32 fn_108_E000(void* object, const s16* value, void* argument);

extern "C" void fn_108_DF70(void* self, const s16* index, void* argument) {
    unsigned char* base = static_cast<unsigned char*>(self);
    FalcoSub* sub = reinterpret_cast<FalcoSub*>(base + 0xC);
    s16 local;
    if ((*index & 1) != 0 && sub->isEnabled() == true && sub->hidden == 0) {
        fn_108_DF20(sub, argument);
    }
    fn_108_E490(&local, index);
    fn_108_E000(base + 4, &local, argument);
}
