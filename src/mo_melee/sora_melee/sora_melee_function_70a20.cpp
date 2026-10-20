#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

class acCmdInterpreter {
public:
    u8 m_pad0[0x30];
    struct Flags {
        u32 a : 2;
        u32 b : 3;
        u32 c : 27;
    } m_flags;
    u8 m_pad1[0x10];
    u32 m_field44;

    void* getLastSystemStackData();
    void popSystemStack();
    void skipCmd();
};

extern "C" void fn_27_70A20(acCmdInterpreter* self, u32 arg) {
    self->m_flags.b = 1;
    self->m_field44 = arg;
    void* data = self->getLastSystemStackData();
    if (data != 0 && *(int*)data == 9) {
        self->popSystemStack();
    } else {
        self->skipCmd();
    }
}
