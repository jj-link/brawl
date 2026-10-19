#pragma force_active on
class grGimmick {
public:
    void updateCallback(unsigned long);
};

extern "C" void fn_40_2EB0C(grGimmick* self) {
    self->updateCallback(0);
    *((unsigned char*)self + 0x160) = 0;
}
