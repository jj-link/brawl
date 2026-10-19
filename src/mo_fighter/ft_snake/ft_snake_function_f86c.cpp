#pragma force_active on
typedef int s32;

extern "C" s32 fn_122_F86C(const s32* obj, s32 index) {
    s32* array = *(s32**)(obj + 3);
    return array[index];
}
