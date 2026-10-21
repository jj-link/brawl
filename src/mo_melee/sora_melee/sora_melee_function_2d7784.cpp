#pragma force_active on

struct Object {
    void* vptr;
    unsigned char padding[0x480];

public:
    virtual void method2();
};

extern "C" int fn_27_2D7784(Object* self, int index) {
    int result = 0;
    if (index >= 0 && index < 0x40) {
        if (*(int*)self > 0) {
            int* p = (int*)((char*)self + index * 0xC);
            int slot = p[3];
            if (slot != 0) {
                result = slot;
                p[3] = 0;
                (*(int*)self)--;
            }
        }
    }
    self->method2();
    return result;
}
