#pragma force_active on
extern "C" char lbl_41_data_3DD8[];
extern "C" char lbl_41_data_3D88[];

struct Class_3D90_base { char pad[0x24]; };
class Class_3D90 : public Class_3D90_base {
public:
    virtual void fn_41_2C0AC();
    virtual void fn_41_2BFE8();
    virtual void fn_41_2C050();
    virtual void fn_41_2C934();
    virtual void fn_41_2CA04();
    virtual void fn_41_2C128();
    virtual void fn_41_2C180();
    virtual void fn_41_2C280();
    virtual void fn_41_2C3D0();
};

extern "C" void fn_41_2BF6C(int* ptr);
extern "C" void fn_27_CB150(void*, int, int);
extern "C" void fn_27_D3544(void*, int, int);

extern "C" char* fn_41_2BEBC(char* self) {
    *(void**)(self + 0x24) = lbl_41_data_3DD8;
    fn_41_2BF6C((int*)(self + 0x8));
    fn_41_2BF6C((int*)(self + 0x14));
    *(int*)self = 0;
    *(int*)(self + 0x4) = 0;
    *(unsigned char*)(self + 0x20) = 1;
    *(void**)(self + 0x24) = lbl_41_data_3D88;
    fn_27_CB150(self + 0x28, 0x46, 0);
    fn_27_D3544(self + 0x264, 0xa, 0);
    Class_3D90* obj = (Class_3D90*)self;
    obj->fn_41_2C280();
    obj->fn_41_2C3D0();
    return self;
}