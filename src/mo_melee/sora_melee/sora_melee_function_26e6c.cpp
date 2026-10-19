#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_27_2EEC4(unsigned char* self, u32 a, u32 b);

class soSoraObjSlot {
public:
    virtual void v0();
    virtual unsigned char* v1(u32 x);
};

extern "C" void fn_27_26E6C(unsigned char* self, u32 a, u32 b) {
    soSoraObjSlot* obj = *(soSoraObjSlot**)(self + 0x28);
    unsigned char* r = obj->v1(b);
    fn_27_2EEC4(r, a, 0);
}
