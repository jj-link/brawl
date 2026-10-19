#pragma force_active on
class View {
public:
    virtual ~View();
    virtual void entry();
    virtual void entry2();
    virtual int call();
};

extern "C" int fn_99_9C70(View* object) {
    return !object->call();
}
