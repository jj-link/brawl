#pragma force_active on
struct FtObj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(unsigned int* p);
};

extern "C" void fn_96_A400(FtObj* self, unsigned int* arr, int count) {
    if (arr == 0 || count <= 0) {
        return;
    } else {
        for (int i = 0; i < count; i++) {
            self->vf10(&arr[i]);
        }
    }
}
