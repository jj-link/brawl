#pragma force_active on
class grYakumono {
public:
    void setValid(unsigned long valid);
};

extern "C" {
void fn_40_369C0(grYakumono* self, unsigned long valid);
}

void fn_40_369C0(grYakumono* self, unsigned long valid) {
    self->setValid(valid);
    if (valid == 0) {
        *((unsigned char*)self + 0x150) = 5;
    } else {
        *((unsigned char*)self + 0x150) = 0;
    }
}
