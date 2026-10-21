#pragma force_active on

extern "C" {
int fn_27_241F14(void);
int fn_27_241F00(void*);
void* getInstance__16CameraControllerFv(void);
extern const float lbl_27_rodata_4118[4];
}

class SubObjV {
public:
    int pad;
    virtual void f0(float);
    virtual void f1();
    virtual void f2();
};

extern "C" void fn_27_25469C(void* arg0) {
    unsigned char* self = (unsigned char*)arg0;
    const float* k = lbl_27_rodata_4118;
    if (fn_27_241F14() == 0) {
        if (fn_27_241F00(arg0) == 0) {
            if (self[0x41] != 0) {
                *(float*)(self + 0x9C) = *(float*)(self + 0x9C) - k[1];
                SubObjV* obj = *(SubObjV**)((unsigned char*)getInstance__16CameraControllerFv() + 0x48);
                obj->f0(*(float*)(self + 0xA0));
                *(float*)(self + 0xA0) = *(float*)(self + 0xA0) * k[2];
                if (*(float*)(self + 0x9C) < k[3]) {
                    *(float*)(self + 0x9C) = k[0];
                }
                if (k[0] == *(float*)(self + 0x9C)) {
                    self[0xA4] = 1;
                }
            }
        }
    }
}
