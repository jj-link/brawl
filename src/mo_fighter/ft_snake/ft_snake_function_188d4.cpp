#include <mo_fighter/ft_dedede/ft_dedede_link_event.h>
#include <so/so_module_accesser.h>
#include <so/link/so_link_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <so/visibility/so_visibility_module_simple.h>
#pragma force_active on

namespace {
struct SnakeFighterBase {
    unsigned char data[0x3C];
};

struct SnakeFighter : SnakeFighterBase {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual unsigned int v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138(int);

    unsigned char mid[0x20];
    soModuleAccesser* accesser;
};
} // namespace

extern "C" void fn_27_8CF84(void*, void*);

extern "C" void fn_122_188D4(SnakeFighter* fighter, soLinkEventArgs* event,
                             soModuleAccesser* accesser, StageObject* object, int value) {
    switch (event->m_eventKind) {
    case 0x2:
        if (value == 3 && fighter->accesser->getStatusModule().getStatusKind() == 4) {
            fighter->accesser->getWorkManageModule().onFlag(0x22000000);
            fighter->accesser->getStatusModule().changeStatusRequest(0, fighter->accesser);
        }
        break;
    case 0x3D:
        if (value == 3 && fighter->accesser->getStatusModule().getStatusKind() == 4) {
            if (fighter->accesser->getWorkManageModule().isFlag(0x22000000) == 0) {
                fighter->accesser->getStatusModule().changeStatusRequest(0, fighter->accesser);
            }
        }
        break;
    case 0x38:
        if (value == 3 && fighter->accesser->getStatusModule().getStatusKind() == 4) {
            fighter->accesser->getStatusModule().changeStatusRequest(0, fighter->accesser);
        }
        break;
    case 0x37:
        fighter->accesser->getVisibilityModule().setWhole(reinterpret_cast<unsigned char*>(event)[5]);
        break;
    case 0x839: {
        soLinkModule& link = fighter->accesser->getLinkModule();
        soWorkManageModule& workManage = fighter->accesser->getWorkManageModule();
        if ((unsigned int)workManage.getInt(0x10000000) == (unsigned int)link.getParentTaskId(3)) {
            fn_27_8CF84((char*)fighter + 0x88, fighter->accesser);
            if (fighter->v41() == 1U) {
                fighter->v138(0);
            }
        }
        break;
    }
    }
    fn_27_1DB0F0(fighter, event, accesser, object, value);
}
