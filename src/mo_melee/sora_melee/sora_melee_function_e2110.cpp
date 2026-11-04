#pragma force_active on

struct Node {
    unsigned int a;
    unsigned int b;
};

struct Container {
    virtual void slot08();
    virtual Node* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_AB2E0(Node* dst, const Node* src);

extern "C" void fn_27_E2110(Container* self, int start, const Node* value,
                            unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        Node* dst = self->at(start + i);
        fn_27_AB2E0(dst, value);
    }
}
