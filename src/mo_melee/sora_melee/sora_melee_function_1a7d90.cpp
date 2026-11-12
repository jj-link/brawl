#include <types.h>
#pragma force_active on

class soGimmickEventObserver;

template <typename T>
class soEventObserver;

template <>
class soEventObserver<soGimmickEventObserver> {
public:
    virtual void addObserver(s16, s8);

    s16 m_manageID;
    s16 m_unitID;
    s16 m_sendID;

    s32 getObserverId() const;
};

s32 soEventObserver<soGimmickEventObserver>::getObserverId() const {
    return m_sendID;
}
