#pragma force_active on
class CaptainSlot {
public:
    virtual void* get0();
    virtual void* get1();
    virtual void* get2();
    virtual void* get3();
    virtual void activate(int index, void* accesser);
    virtual void* get5();
    virtual void* get6();
    virtual void* get7();
    virtual void* get8();
    virtual int query(int index);
};

extern "C" int fn_100_F850(void* data, void* accesser) {
    void* sub = *(void**)((char*)data + 0xd8);
    CaptainSlot* obj = *(CaptainSlot**)((char*)sub + 0x54);
    for (int i = 6; i < 12; i++) {
        if (obj->query(i) == 0) {
            obj->activate(i, accesser);
            return i;
        }
    }
    return -1;
}
