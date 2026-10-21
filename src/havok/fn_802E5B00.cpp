#pragma force_active on

class Foo {
public:
    virtual void slot0(int);
};

extern "C" void fn_802E5B00(Foo* p) {
    p->slot0(-1);
}
