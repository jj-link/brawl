#pragma force_active on
class Viewer {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void apply(unsigned int value);
};

struct Context {
    unsigned char padding[0x70];
    unsigned int value;
    Viewer* viewer;
};

extern "C" void fn_6_BF60(Context* context) {
    context->viewer->apply(context->value);
}
