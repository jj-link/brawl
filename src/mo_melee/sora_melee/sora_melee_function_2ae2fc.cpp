#pragma force_active on
extern "C" {
void* fn_27_2AC504(void* arg, int param);
void fn_27_2AC7B0(void* arg, void* value);
}

class fn_27_Obj {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual int getCount();
};

extern "C" void fn_27_2AE2FC(fn_27_Obj* self) {
    int n = self->getCount();
    void* v = fn_27_2AC504(self, n - 1);
    fn_27_2AC7B0(self, v);
}
