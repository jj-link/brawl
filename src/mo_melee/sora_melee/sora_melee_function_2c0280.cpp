#include <so/so_value_accesser.h>
#pragma force_active on

struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual float fn_27_7B2EC(soModuleAccesser*, int, unsigned int);
};
extern unsigned int lbl_27_bss_71DC[];
extern float lbl_27_rodata_5FD8;
extern float lbl_27_rodata_5FF0;
extern "C" float fn_27_8C02C(void*, soModuleAccesser*, int, unsigned int);
extern "C" int fn_27_28C800(void*);

struct Data { char pad[0x30]; float* a; float* b; };
struct Holder { Data* data; };
struct Object { char pad[0x8c0]; int kind; int variation; };
struct Access { char pad[8]; Object* object; char pad2[0xcc]; Holder* holder; };

extern "C" float fn_27_2C0280(void* self, soModuleAccesser* module, int id, unsigned int index) {
    Access* a = (Access*)module;
    if (id > 0xf9f)
        return ((Class_90D8*)lbl_27_bss_71DC)->fn_27_7B2EC(module, id, index);
    if (id <= 0xbb7)
        return fn_27_8C02C(self, module, id, index);
    if (id > 0xbb8 && id < 0xbc9)
        return a->holder->data->a[id - 0xbb9];
    if (id > 0xd48 && id < 0xd73)
        return a->holder->data->b[id - 0xd49];
    if (id > 0xdac && id < 0xdae) {
        Object* obj = a->object;
        switch (id) {
        case 0xdad:
            int value = -1;
            if (fn_27_28C800(obj) & 0x80) {
                switch (obj->kind) {
                case 0x20:
                    if (obj->variation == 1) return lbl_27_rodata_5FF0;
                    value = 0x15e0;
                    break;
                case 0x24: value = 0x16a8; break;
                case 0x40: value = obj->variation + 0x1c20; break;
                case 0x58: value = 0x20d0; break;
                case 0x4a: value = 0x1e14; break;
                case 0x4e: value = obj->variation + 0x1edc; break;
                }
            }
            if (value >= 0) return soValueAccesser::getConstantFloat(module, value, 0);
            return lbl_27_rodata_5FD8;
        }
    }
    return lbl_27_rodata_5FD8;
}