#include <types.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" int fn_27_8C078(void*, void*, int, int);
extern const char lbl_27_data_7A0C0[];
extern const char __RTTI__16soResourceModule[];

struct Class_90D8_base { char pad[0x8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual int fn_27_7AD2C();
};

extern Class_90D8 lbl_27_bss_71DC;

extern "C" int fn_27_2C06D8(void* p0, void* acc, int id, int arg4) {
    if (id > 0xABDF) {
        Class_90D8* obj = &lbl_27_bss_71DC;
        return obj->fn_27_7AD2C();
    }
    if (id <= 0xA7F7) {
        return fn_27_8C078(p0, acc, id, arg4);
    }
    void* enumStart = *(void**)((char*)acc + 0xD8);
    void* rm = *(void**)enumStart;
    void* castResult = __dynamic_cast(rm, 8, lbl_27_data_7A0C0, __RTTI__16soResourceModule, 1);
    void* r6 = *(void**)((char*)castResult + 0x34);
    void* r7 = *(void**)((char*)castResult + 0x38);
    switch (id) {
    case 0xA7F8: {
        void* t = *(void**)((char*)castResult + 0x30);
        void* t2 = *(void**)((char*)t + 0x60);
        if (t2 != 0) {
            return *(int*)t2;
        }
        return 0;
    }
    case 0xA7F9:
        return *(int*)((char*)r7 + 0x0);
    case 0xA7FB:
        return *(int*)((char*)r7 + 0x30);
    case 0xA7FC:
        return *(int*)((char*)r7 + 0x34);
    case 0xA7FD:
        return *(int*)((char*)r7 + 0x38);
    case 0xA7FA:
        return *(int*)((char*)r7 + 0x8);
    case 0xA7FE:
        return *(int*)((char*)r7 + 0x10);
    case 0xA7FF:
        return *(int*)((char*)r7 + 0x14);
    case 0xA800:
        return *(int*)((char*)r7 + 0x18);
    case 0xA801:
        return *(int*)((char*)r7 + 0x1C);
    case 0xA802:
        return *(int*)((char*)r7 + 0x20);
    case 0xA803:
        return *(int*)((char*)r7 + 0x24);
    case 0xA804:
        return *(int*)((char*)r7 + 0x28);
    case 0xA805:
        return *(int*)((char*)r7 + 0x2C);
    case 0xA806:
        return *(int*)((char*)r6 + 0xEC);
    default:
        return 0;
    }
}
