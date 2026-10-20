#pragma force_active on
struct Result {
    int values[3];
};

class Object {
    char padding[0x30];

public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Result invoke();
};

extern "C" Object* fn_27_36028(void*, int, int);

extern "C" Result fn_27_470AC(const int* id, void* work, int index) {
    return fn_27_36028(work, index, *id)->invoke();
}
