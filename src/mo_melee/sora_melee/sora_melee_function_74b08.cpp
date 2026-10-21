#pragma force_active on
struct Entry {
    int value;
};

class Interface {
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
    virtual void apply(const Entry*);
};

struct Object {
    char padding[0x30];
    Interface* target;
};

extern "C" void fn_27_74B08(Object* self, const Entry* entries, int count) {
    if (entries == 0 || count <= 0) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        self->target->apply(&entries[i]);
    }
}
