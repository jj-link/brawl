#pragma force_active on
class fn_27_Base {
public:
    virtual void vf0();
    virtual fn_27_Base* vf1(void* p);
};

extern "C" {
void fn_27_F9DE8(fn_27_Base* dst, unsigned int* src, void* arg) {
    fn_27_Base* d = dst->vf1(arg);
    *(unsigned int*)d = *src;
}
}
