#pragma force_active on
class FtRobotBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10(int* p);
    virtual void vfunc11();
    virtual void vfunc12();
};

extern "C" void fn_120_7A90(FtRobotBase* self, int* arr, int count) {
    if (arr == 0 || count <= 0) {
        return;
    }
    for (int i = 0; i < count; i++) {
        self->vfunc10(&arr[i]);
    }
}
