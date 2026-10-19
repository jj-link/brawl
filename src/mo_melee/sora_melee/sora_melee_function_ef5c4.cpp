#pragma force_active on
struct Interface {
    virtual void unused0();
    virtual unsigned int* get(unsigned int);
};

extern "C" void fn_27_EF5C4(Interface* self, unsigned int* source, unsigned int argument) {
    unsigned int* destination = self->get(argument);
    *destination = *source;
}
