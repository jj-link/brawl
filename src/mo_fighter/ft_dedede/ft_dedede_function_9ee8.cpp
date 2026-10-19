#pragma force_active on
extern "C" void* fn_117_946C();
extern "C" bool fn_27_135EE0(void*);

namespace {
class DededeStatusQuery {
public:
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void reserved4();
    virtual void reserved5();
    virtual void reserved6();
    virtual void reserved7();
    virtual void reserved8();
    virtual void reserved9();
    virtual void reserved10();
    virtual unsigned int query(void* arg);
};
}

extern "C" int fn_117_9EE8(void* self) {
    DededeStatusQuery* query = static_cast<DededeStatusQuery*>(fn_117_946C());
    void* arg = *reinterpret_cast<void**>(static_cast<unsigned char*>(self) + 0x60);
    if (query->query(arg) == 1) {
        return 1;
    }
    return fn_27_135EE0(self);
}
