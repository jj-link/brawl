#pragma force_active on
extern "C" int fn_27_2ACD20(void* self, int n, int v);

class Object {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int size();
};

extern "C" void fn_27_2AC9C8(Object* self, const int* p) {
    int n = self->size();
    int idx = fn_27_2ACD20(self, n - 1, -1);
    if (idx >= 0) {
        *(int*)((char*)self + idx * 12 + 0xc) = *p;
    }
}
