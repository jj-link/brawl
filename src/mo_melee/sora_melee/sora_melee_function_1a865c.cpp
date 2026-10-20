#include <types.h>
#pragma force_active on

class soLinkEventObserver;

class soWorkAreaBase {
public:
    virtual ~soWorkAreaBase();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual s32 getObserverNum() const;
};

class soEventUnitBase {
public:
    virtual ~soEventUnitBase();
    u32 unk4;
    u32 unk8;
};

template <typename T, int N>
class soEventUnitWithWorkArea : public soEventUnitBase {
public:
    soWorkAreaBase m_work;
    s32 getObserverNum() const;
};

template <typename T, int N>
s32 soEventUnitWithWorkArea<T, N>::getObserverNum() const {
    return m_work.getObserverNum();
}

template class soEventUnitWithWorkArea<soLinkEventObserver, 4>;
