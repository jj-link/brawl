#pragma force_active on
class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void setIndex(int idx);
    virtual int getCount();
};

extern "C" void fn_113_24C9C(void* self, int idx, Obj* obj) {
    if (idx >= obj->getCount()) {
        int last = obj->getCount() - 1;
        obj->setIndex(last);
    } else {
        obj->setIndex(idx);
    }
}
