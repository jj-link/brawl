#pragma force_active on
class KoopaSubObject {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
};

extern "C" int fn_102_14D54(char* self) {
    KoopaSubObject* obj = reinterpret_cast<KoopaSubObject*>(self + 0x13974);
    return obj->slot2();
}
