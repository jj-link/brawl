#pragma force_active on
typedef unsigned int u32;

struct fn_27_1E7F00_Flags {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" {
void fn_27_1E7F00(void* obj, u32 value) {
    fn_27_1E7F00_Flags* f = (fn_27_1E7F00_Flags*)((char*)obj + 8);
    f->b = value;
}
}
