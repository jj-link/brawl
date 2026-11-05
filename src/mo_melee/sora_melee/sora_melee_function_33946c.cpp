#include <so/so_module_accesser.h>
#include <so/situation/so_situation_module_impl.h>
#pragma force_active on

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C(int, soModuleAccesser*);
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void* fn_27_14A28(int);
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual Vec2f fn_27_14D08(short*);
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" unsigned char lbl_27_data_2E5F8[8];
extern "C" unsigned char lbl_27_data_CDF8[8];
extern "C" float lbl_27_rodata_76F8;
extern "C" float fn_27_192278(void*, unsigned long);

extern "C" void fn_27_33946C(void*, soModuleAccesser* accesser) {
    const soModuleEnumeration* en = accesser->m_enumerationStart;
    soSituationModule* sit = en->m_situationModule;
    Class_1250* kin = (Class_1250*)en->m_kineticModule;
    if (sit->getKind()) {
        float scale = fn_27_192278(accesser, 0xfa1);
        short idx = -1;
        Vec2f v;
        Vec2f::copy(v, kin->fn_27_14D08(&idx));
        kin->fn_27_14A48();
        void* p = kin->fn_27_14A28(3);
        char* e = (char*)__dynamic_cast(p, 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
        v.m_x = v.m_x / scale;
        v.m_y = lbl_27_rodata_76F8;
        *(Vec2f*)(e + 8) = v;
        e[5] |= 0x80;
    }
}
