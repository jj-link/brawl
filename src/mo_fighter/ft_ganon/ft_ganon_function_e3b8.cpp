#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class FtSubModule {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual unsigned char* vf6(int);
};

struct FtFlagByte {
    unsigned char hi : 1;
    unsigned char rest : 7;
};

extern "C" {
extern const char lbl_109_data_6530[], lbl_109_data_1670[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_15FBC8(int);
}

extern "C" void fn_109_E3B8(void*, int, void*, soModuleAccesser* accesser) {
    fn_27_15FBC8(0x13);
    FtSubModule* m = *reinterpret_cast<FtSubModule**>(reinterpret_cast<unsigned char*>(accesser) + 0xd8);
    m = *reinterpret_cast<FtSubModule**>(reinterpret_cast<unsigned char*>(m) + 0x7c);
    unsigned char* flags = m->vf6(0);
    reinterpret_cast<FtFlagByte*>(flags + 5)->hi = 0;
    FtSubModule* m2 = *reinterpret_cast<FtSubModule**>(reinterpret_cast<unsigned char*>(accesser) + 0xd8);
    m2 = *reinterpret_cast<FtSubModule**>(reinterpret_cast<unsigned char*>(m2) + 0x7c);
    unsigned char* obj = m2->vf6(1);
    unsigned char* energy = reinterpret_cast<unsigned char*>(
        __dynamic_cast(obj, 0, lbl_109_data_6530, lbl_109_data_1670, 1));
    *reinterpret_cast<float*>(energy + 0x10) = -soValueAccesser::getConstantFloat(accesser, 0xfb4, 0);
}
