#include <so/so_value_accesser.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/link/so_link_module_impl.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

class Capture {
public:
 virtual void isNull();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
};
class ControllerCall {
public:
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
 virtual void v15();
 virtual void v16();
 virtual void v17();
 virtual void v18();
 virtual void v19();
 virtual void v20();
 virtual void v21();
 virtual void v22();
 virtual void v23();
 virtual void v24();
 virtual void v25();
 virtual void v26();
 virtual void v27();
 virtual void v28();
 virtual void v29();
 virtual void v30();
 virtual void v31();
 virtual void v32();
 virtual void v33();
 virtual void v34();
 virtual void v35();
 virtual void v36();
 virtual void v37();
 virtual void v38();
 virtual void v39();
 virtual void v40();
 virtual void v41();
 virtual void v42();
 virtual void v43();
 virtual void v44();
 virtual void v45();
 virtual void v46();
 virtual void v47();
 virtual void startClatter(float, float, float, unsigned char, signed char, unsigned int, bool);
};
extern float lbl_27_rodata_24C4;
extern "C" void fn_27_186C6C(void*, soModuleAccesser* a) {
    ((Capture*)a->m_enumerationStart->m_captureModule)->slot15();
    if (a->m_enumerationStart->m_statusModule->getStatusKind() == 0xda) {
        float frame = a->m_enumerationStart->m_controllerModule->getClatterTime(0);
        float value;
        if (a->m_enumerationStart->m_linkModule->getParentSituationKind(0) == 0)
            value = soValueAccesser::getConstantFloat(a, 0xd4a, 0);
        else
            value = soValueAccesser::getConstantFloat(a, 0xd4b, 0);
        reinterpret_cast<ControllerCall*>(a->m_enumerationStart->m_controllerModule)->startClatter(frame, lbl_27_rodata_24C4, value, 0, -1, 0, false);
    }
}