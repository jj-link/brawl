#include <ft/ft_common_data_accesser.h>
#pragma force_active on

extern float lbl_95_rodata_E0;
extern float lbl_95_rodata_E4;

extern "C" void fn_95_10704(void* self);
extern "C" int fn_95_FDD8(void* self);
extern "C" int fn_95_FE54(void* self);
extern "C" void fn_95_FF04(void* self);
extern "C" void fn_95_100C4(void* self);

class Class_7E00 {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void setA(int, int);
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual float getF(int);
    virtual void setF(float, int);
};

struct FtModules {
    char pad[0x64];
    Class_7E00* obj;
};

struct FtFighter {
    char pad[0xD8];
    FtModules* modules;
};

extern "C" void fn_95_12F44(void* unused, FtFighter* self) {
    Class_7E00* obj = self->modules->obj;
    char* common = (char*)g_ftCommonDataAccesser.getData((ftKind)4);
    char* data = *(char**)(common + 0x7C);

    obj->setF(lbl_95_rodata_E0, 0x21000008);
    obj->setA(0, 0x20000006);
    float base = obj->getF(0x21000005);
    float sum = base + lbl_95_rodata_E4 * *(float*)(data + 0x18);
    obj->setF(sum, 0x21000005);

    fn_95_10704(self);
    if (fn_95_FDD8(self) != 0 || fn_95_FE54(self) != 0) {
        obj->setA(0x11A, 0x20000008);
    }
    fn_95_FF04(self);
    fn_95_100C4(self);
}
