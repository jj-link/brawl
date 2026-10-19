#pragma force_active on
class fn27Base {
public:
    virtual void vf0();
    virtual fn27Base* vf1(void* p);
};

extern "C" {
void fn_27_292818(fn27Base* self, unsigned int* src, void* arg) {
    self = self->vf1(arg);
    *(unsigned int*)self = *src;
}
}
