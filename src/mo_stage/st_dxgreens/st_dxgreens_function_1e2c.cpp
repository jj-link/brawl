#pragma force_active on
class grYakumono {
public:
    void preExit();
    char m_pad[0x20c];
    void* m_0x20c;
};

extern "C" void fn_27_263464(void* p);

extern "C" void fn_79_1E2C(grYakumono* self) {
    if (self->m_0x20c != 0) {
        fn_27_263464(self->m_0x20c);
    }
    self->preExit();
}
