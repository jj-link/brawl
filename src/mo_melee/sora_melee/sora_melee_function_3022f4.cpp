#pragma force_active on
typedef signed int s32;
struct fnObj;

extern "C" {
void fn_27_5B248(fnObj*, s32, s32, s32);

fnObj* fn_27_3022F4(fnObj* p, s32 a, s32 b) {
    fn_27_5B248(p, a, b, 2);
    return p;
}
}
