#pragma force_active on
typedef unsigned int u32;

class ElementArray {
public:
    virtual void unused0();
    virtual void* at(int index);
    virtual void unused2();
    virtual int size();
};

struct Container {
    char padding[12];
    ElementArray* elements;
};

extern "C" u32 fn_27_C40F4(void* self);
extern "C" void fn_27_C3E58(void* self);

static inline void* findElement(Container* self, int id) {
    int count = self->elements->size();
    for (int i = 0; i < count; ++i) {
        if ((int)fn_27_C40F4(self->elements->at(i)) == id) {
            return self->elements->at(i);
        }
    }
    return 0;
}

extern "C" void fn_27_C35F0(Container* self, int id) {
    void* element = findElement(self, id);
    if (element) {
        fn_27_C3E58(element);
    }
}
