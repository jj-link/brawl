#pragma force_active on
class FtObj {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(int* p);
};

extern "C" {
void fn_105_A028(FtObj* self, int* arr, int count)
{
    int i;
    if (arr != 0) {
        if (count > 0) {
            goto loop;
        }
    }
    return;
loop:
    for (i = 0; i < count; i++) {
        self->vf12(arr + i);
    }
}
}
