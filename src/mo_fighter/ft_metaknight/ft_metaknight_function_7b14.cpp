#pragma force_active on
class MetaKnightArray {
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
    virtual void append(const int*);
};

extern "C" void fn_111_7B14(MetaKnightArray* self, const int* values, int count) {
    if (values == 0 || count <= 0) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        self->append(&values[i]);
    }
}
