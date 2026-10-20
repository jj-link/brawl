#pragma force_active on
typedef unsigned int u32;

struct fn_27_199C08_obj {
    u32 unk0;
    u32 unk4;
    u32 flag : 5;
    u32 rest : 27;
};

extern "C" void fn_27_199C08(fn_27_199C08_obj *p, u32 v) {
    p->flag = v;
}
