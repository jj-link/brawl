#pragma force_active on
class PalutenaObject {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual int query() = 0;
};

extern "C" bool fn_67_4E88(PalutenaObject* object) {
    return !object->query();
}
