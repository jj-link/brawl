#pragma force_active on
#pragma scheduling off
#pragma optimization_level 2

#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>

struct Speed {
    float x, y;
};

struct Energy {
    virtual void slot0();
    virtual void slot1();
    virtual Speed slot2();

    float pad;
    Speed speed;
};

extern "C" {
extern const float lbl_27_rodata_76A8;

void fn_27_15FA20(int, void*, soModuleAccesser*);
Speed fn_27_164B10(soModuleAccesser*, bool, bool);
void fn_27_160268(soModuleAccesser*);
void fn_27_331AF0(void*, const Speed*);
void fn_27_331B04(void*, void*, const Speed*, soModuleAccesser*);
void fn_27_331BFC(void*, void*, const Speed*, soModuleAccesser*);
void fn_27_331C54(void*, void*, const Speed*, soModuleAccesser*);
void fn_27_331D50(void*, void*, const Speed*, soModuleAccesser*);
void fn_27_331ED0(void*, void*, const Speed*, soModuleAccesser*);
void fn_27_331F7C(void*, void*, const Speed*, soModuleAccesser*);
void fn_27_33213C(void*, void*, const Speed*, soModuleAccesser*);
void fn_27_332260(void*, void*, const Speed*, soModuleAccesser*);
void fn_27_33235C(void*, void*, const Speed*, soModuleAccesser*);
void fn_27_332490(void*, void*, const Speed*, soModuleAccesser*);
void fn_27_332660(void*, void*, const Speed*, soModuleAccesser*);
}

extern "C" void fn_27_3317DC(int kind, void* object, soModuleAccesser* accesser) {
    Speed speed;

    if (accesser->m_enumerationStart->m_kineticModule->getKineticType() == 0x6a) {
        ((char*)&speed)[-41] = 0;
        Energy* e = (Energy*)((char*)object + 0x6c);
        Speed first = e->slot2();
        e->speed.y = first.y / soValueAccesser::getConstantFloat(accesser, 0xfb3, 0);

        ((char*)&speed)[-42] = 0;
        Speed scaled;
        Energy* e2 = (Energy*)((char*)object + 0xa0);
        float v = soValueAccesser::getConstantFloat(accesser, 0xfb2, 0);
        Speed v2 = e2->slot2();
        float scale = lbl_27_rodata_76A8 / v;
        (*(Speed*)((char*)&speed - 0x28)).x = v2.x * scale;
        (*(Speed*)((char*)&speed - 0x28)).y = v2.y * scale;
        __memcpy(&scaled, (char*)&speed - 0x28, sizeof(Speed));
        fn_27_331AF0(&e2->speed, &scaled);
    }

    if (kind <= 0x63) {
        fn_27_15FA20(kind, object, accesser);
        return;
    }

    Speed returned = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returned, sizeof(Speed));

    Speed tmpA;
    Speed bufB;
    Speed bufC;

    switch (kind) {
    case 0x64:
        ((char*)&tmpA)[-3] = 0;
        fn_27_331B04(&((char*)&tmpA)[-3], object, &speed, accesser);
        break;
    case 0x65:
        ((char*)&bufB)[4] = 0;
        fn_27_331BFC(&((char*)&bufB)[4], object, &speed, accesser);
        break;
    case 0x66:
        ((char*)&bufB)[3] = 0;
        fn_27_331C54(&((char*)&bufB)[3], object, &speed, accesser);
        break;
    case 0x67:
        ((char*)&bufB)[2] = 0;
        fn_27_331D50(&((char*)&bufB)[2], object, &speed, accesser);
        break;
    case 0x68:
        ((char*)&bufB)[1] = 0;
        fn_27_331ED0(&((char*)&bufB)[1], object, &speed, accesser);
        break;
    case 0x69:
        ((char*)&bufB)[0] = 0;
        fn_27_331F7C(&((char*)&bufB)[0], object, &speed, accesser);
        break;
    case 0x6a:
        ((char*)&bufC)[7] = 0;
        fn_27_33213C(&((char*)&bufC)[7], object, &speed, accesser);
        break;
    case 0x6b:
        ((char*)&bufC)[6] = 0;
        fn_27_332260(&((char*)&bufC)[6], object, &speed, accesser);
        break;
    case 0x6c:
        ((char*)&bufC)[5] = 0;
        fn_27_33235C(&((char*)&bufC)[5], object, &speed, accesser);
        break;
    case 0x6d:
        ((char*)&bufC)[4] = 0;
        fn_27_332490(&((char*)&bufC)[4], object, &speed, accesser);
        break;
    case 0x6e:
        ((char*)&bufC)[3] = 0;
        fn_27_332660(&((char*)&bufC)[3], object, &speed, accesser);
        break;
    case 0x6f:
        ((char*)&bufC)[2] = 0;
        break;
    case 0x70:
        ((char*)&bufC)[1] = 0;
        break;
    case 0x71:
        ((char*)&bufC)[0] = 0;
        break;
    default:
        return;
    }

    fn_27_160268(accesser);
}
