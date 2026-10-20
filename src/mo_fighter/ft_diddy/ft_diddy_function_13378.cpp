#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void fn_27_1DCC10(int, unsigned char*, soModuleAccesser*);
void fn_115_133F0(unsigned char*);
}

struct DededeVirtObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
};

extern "C" void fn_115_13378(int kind, unsigned char* energies, soModuleAccesser* accesser) {
    unsigned char flags[2];
    if (kind <= 31) {
        fn_27_1DCC10(kind, energies, accesser);
    } else {
        switch (kind) {
        case 32: {
            DededeVirtObj* b;
            flags[1] = 0;
            b = *(DededeVirtObj**)(*(char**)((char*)accesser + 0xd8) + 0x7c);
            b->v12();
            break;
        }
        case 33:
            flags[0] = 0;
            fn_115_133F0(flags);
            break;
        }
    }
}
