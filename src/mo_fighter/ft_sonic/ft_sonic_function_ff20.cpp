#pragma force_active on
struct Provider {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual int slot14();
};
struct Holder {
    void* field0;
    Provider* provider;
    int flag;
    int value;
};
extern "C" int fn_123_FF20(Holder* self) {
    int value = self->value;
    if (self->flag == 0)
        value = 0;
    if (self->provider != 0)
        return value + self->provider->slot14();
    return value;
}
