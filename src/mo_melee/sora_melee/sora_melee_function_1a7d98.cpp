#pragma force_active on
class soGimmickEventObserver;

template <typename T>
class soEventObserver;

template <>
class soEventObserver<soGimmickEventObserver> {
public:
    virtual void addObserver(short, signed char);

    short m_manageID;
    short m_unitID;
    short m_sendID;

    soEventObserver(short unitID);
};

soEventObserver<soGimmickEventObserver>::soEventObserver(short unitID) {
    m_manageID = -1;
    m_unitID = unitID;
    m_sendID = -1;
}
