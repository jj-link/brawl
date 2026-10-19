#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;
typedef float f32;

extern const f32 lbl_27_rodata_9A4;

struct acCmdInterpreterStackData {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    s32 unkC;
    f32 unk10;
};

class acCmdInterpreter {
public:
    void pushSystemStack(const acCmdInterpreterStackData& data);
};

extern "C" void fn_27_70CF0(acCmdInterpreter* self) {
    acCmdInterpreterStackData data;
    data.unk0 = 9;
    data.unk4 = 0;
    data.unk8 = 0;
    data.unkC = 0;
    data.unk10 = lbl_27_rodata_9A4;
    self->pushSystemStack(data);
}
