#pragma force_active on
struct Work {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int get(unsigned int);
};

struct Object {
    char padding[0x2aac];
    Work work;
};

struct Result {
    int first;
    int second;
    int third;
};

extern "C" void fn_27_285224(Result* out, Object* object) {
    int second = object->work.get(0x1000001e);
    int first = object->work.get(0x1000001d);
    out->first = first;
    out->second = second;
    out->third = 0;
}
