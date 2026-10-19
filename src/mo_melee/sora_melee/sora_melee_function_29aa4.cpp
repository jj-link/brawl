#pragma force_active on
extern "C" {
void fn_27_2F044(char* self, float* v);

class SoraSubObj {
public:
    virtual void vfn0();
    virtual char* vfn3(void* p);
};

void fn_27_29AA4(char* self, float* v, void* p) {
    SoraSubObj* obj = *(SoraSubObj**)(self + 0x28);
    fn_27_2F044(obj->vfn3(p), v);
}
}
