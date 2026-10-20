#pragma force_active on
class Object {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void process(int*);
};

extern "C" void fn_92_8B88(Object* object, int* values, int count)
{
    if (values == 0 || count <= 0)
        return;

    for (int i = 0; i < count; ++i)
        object->process(&values[i]);
}
