#pragma force_active on
struct RefOwner {
    virtual void f0();
    virtual unsigned int* getRef(unsigned int);
};

extern "C" void fn_27_F098C(RefOwner* obj, const unsigned int* src, unsigned int idx) {
    unsigned int* dst = obj->getRef(idx);
    *dst = *src;
}
