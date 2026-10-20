#pragma force_active on
typedef unsigned int u32;

struct fn_27_1CFD64_Bits {
    u32 hi : 5;
    u32 mid : 5;
    u32 lo : 22;
};

class fn_27_1CFD64_Obj {
public:
    u32 pad[2];
    fn_27_1CFD64_Bits flags;
};

extern "C" {
void fn_27_1CFD64(fn_27_1CFD64_Obj* obj, u32 val)
{
    obj->flags.mid = val;
}
}
