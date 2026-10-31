#pragma force_active on
class grGimmick {
public:
    void processUpdate();
    unsigned char pad[0x160];
    unsigned char m_flag;
};

extern "C" void fn_40_2EAF8(grGimmick* self) {
    if (self->m_flag != 0) {
        self->processUpdate();
    }
}
