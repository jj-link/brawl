#pragma force_active on
class soWorkInner {
public:
    virtual void v0() = 0;
    virtual unsigned char* getFlagPtr(int index) = 0;
    virtual void v2() = 0;
    virtual int getCount() = 0;
};

class soWorkOuter {
public:
    unsigned char pad[0xC];
    soWorkInner* m_inner;
};

extern "C" void fn_27_AB638(soWorkOuter* self) {
    int count = self->m_inner->getCount();
    int i = 0;
    if (count > 0) {
        for (; i < count; ) {
            unsigned char* p = self->m_inner->getFlagPtr(i);
            unsigned char v = *p;
            i++;
            *p = v | 0x80;
        }
    }
}
