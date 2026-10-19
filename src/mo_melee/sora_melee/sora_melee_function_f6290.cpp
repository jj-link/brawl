#pragma force_active on
struct fn_27_Holder {
    virtual void unk0();
    virtual unsigned int* getSlot(unsigned int idx);
};

extern "C" void fn_27_F6290(fn_27_Holder* self, unsigned int* src, unsigned int idx) {
    unsigned int* dst = self->getSlot(idx);
    *dst = *src;
}
