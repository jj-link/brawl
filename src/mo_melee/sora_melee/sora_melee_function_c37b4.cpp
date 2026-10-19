#pragma force_active on
typedef unsigned int u32;

extern "C" u32 fn_27_C40F4(void* self);

class ElementArray {
public:
    virtual ~ElementArray();
    virtual void* at(int index) = 0;
    virtual const void* at(int index) const = 0;
    virtual int size() const = 0;
};

struct Object {
    char padding[12];
    ElementArray* elements;
};

static inline void* findElement(Object* self, int id) {
    int count = self->elements->size();
    for (int i = 0; i < count; ++i) {
        if (id == (int)fn_27_C40F4(self->elements->at(i))) {
            return self->elements->at(i);
        }
    }
    return 0;
}

extern "C" bool fn_27_C37B4(Object* self, int id) {
    return findElement(self, id) != 0;
}
