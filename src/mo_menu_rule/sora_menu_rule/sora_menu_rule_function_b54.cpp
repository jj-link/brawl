#include <types.h>
#include <gf/gf_task.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on

struct Class_FA8_base { char pad[0x668]; };
class Class_FA8 : public Class_FA8_base {
public:
    virtual void fn_18_48E8(int);
};
struct Class_1688_base { char pad[0x668]; };
class Class_1688 : public Class_1688_base {
public:
    virtual void fn_18_68E0(int);
};
struct Class_1750_base { char pad[0x668]; };
class Class_1750 : public Class_1750_base {
public:
    virtual void fn_18_7A48(int);
};
struct Class_18D0_base { char pad[0x668]; };
class Class_18D0 : public Class_18D0_base {
public:
    virtual void fn_18_95B0(int);
};
class MenuObject {
    char pad[0x5c];
public:
    virtual void method(int);
};
extern "C" {
extern char lbl_18_data_480[];
void __dl__FPv(void*);
void __dt__6gfTaskFv(void*, int);
void* fn_18_B54(unsigned char* object, int deleting) {
    if (object) {
        *(void**)(object + 0x3c) = lbl_18_data_480;
        unsigned char* cursor = object;
        for (unsigned int i = 0; i < 6; ++i, cursor += 4) {
            (*(nw4r::g3d::G3dObj**)(cursor + 0x250))->Destroy();
            *(void**)(cursor + 0x250) = 0;
        }
        cursor = object;
        for (unsigned int i = 0; i < 0x82; ++i, cursor += 4) {
            MenuObject* entry = *(MenuObject**)(cursor + 0x48);
            if (entry) {
                if (entry) entry->method(1);
                *(void**)(cursor + 0x48) = 0;
            }
        }
        for (unsigned int i = 0; i < 4; ++i) {
            unsigned char* p = object + ((unsigned short)i * 4);
            Class_FA8* entry = *(Class_FA8**)(p + 0x268);
            if (entry) entry->fn_18_48E8(1);
            *(void**)(p + 0x268) = 0;
        }
        (*(gfTask**)(object + 0x44))->exit();
        *(void**)(object + 0x44) = 0;
        __dt__6gfTaskFv(object, 0);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}