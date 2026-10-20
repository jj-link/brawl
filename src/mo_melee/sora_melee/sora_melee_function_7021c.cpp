#pragma force_active on
typedef unsigned int u32;

class acCmdInterpreter {
public:
    char pad_00[0x44];
    void* m_44;
    char pad_48[0x4];
    u32 m_4c;
    void interpretCmd(float f);
};

extern "C" {
void fn_27_7021C(acCmdInterpreter* self, void* arg, float f)
{
    self->m_44 = arg;
    self->m_4c = 0;
    self->interpretCmd(f);
}
}
