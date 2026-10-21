#pragma force_active on
class Element;

class Array {
public:
    virtual ~Array();
    virtual Element* at(int);
    virtual void unused();
    virtual int size();
};

struct Owner {
    void* vtable;
    Array* array;
};

extern "C" void fn_27_C41E4(Element*);

extern "C" void fn_27_C3DCC(Owner* self) {
    if (self->array) {
        int count = self->array->size();
        for (int i = 0; i < count; ++i) {
            fn_27_C41E4(self->array->at(i));
        }
    }
}
