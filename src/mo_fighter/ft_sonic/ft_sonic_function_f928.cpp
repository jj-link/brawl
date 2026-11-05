#include <so/so_value_accesser.h>
#pragma force_active on

class Class_70AC {
public:
    virtual void fn_123_6E08();
    virtual void fn_123_12D4C();
    virtual void fn_123_14120();
    virtual void fn_123_14118();
    virtual void fn_123_14110();
    virtual void fn_123_14108(int);
    virtual void fn_123_14100();
    virtual void fn_123_140F8();
    virtual void fn_123_140F0();
    virtual void fn_123_140E8();
    virtual void fn_123_140E0();
    virtual void fn_123_140D8();
    virtual void fn_123_140D0();
    virtual void fn_123_140C8();
    virtual unsigned int fn_123_14078(int, bool);
    virtual void fn_123_140C0();
    virtual void fn_123_140B0();
    virtual void fn_123_140A0();
    virtual void fn_123_14090(unsigned int);
};

extern "C" float fn_123_FBC0(void*, soModuleAccesser*);

extern "C" void fn_123_F928(void* self, soModuleAccesser* accesser) {
    float value = fn_123_FBC0(self, accesser);
    Class_70AC* module = *(Class_70AC**)(*(char**)((char*)accesser + 0xD8) + 0x1C);
    if (module->fn_123_14078(0, 0) == 1U) {
        if (value <= soValueAccesser::getConstantFloat(accesser, 0xFBE, 0)) {
            (*(Class_70AC**)(*(char**)((char*)accesser + 0xD8) + 0x1C))->fn_123_14108(0);
        }
    } else if (value > soValueAccesser::getConstantFloat(accesser, 0xFBE, 0)) {
        (*(Class_70AC**)(*(char**)((char*)accesser + 0xD8) + 0x64))->fn_123_14090(0x22000010);
    }
}
