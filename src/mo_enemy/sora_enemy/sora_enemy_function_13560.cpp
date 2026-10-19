#pragma force_active on
struct emSubObj {
    virtual void v0();
    virtual float* getValuePtr();
};

struct emHolder {
    char pad[0x40];
    emSubObj* sub;
};

extern "C" float fn_41_13560(emHolder* p) {
    return *p->sub->getValuePtr();
}
