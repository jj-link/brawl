#pragma force_active on
class LucasDispatch {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void apply(int* value);
};

extern "C" void fn_114_AD34(LucasDispatch* object, int* values, int count) {
    if (values == 0 || count <= 0) {
        return;
    }
    for (int i = 0; i < count; ++i) {
        object->apply(&values[i]);
    }
}
