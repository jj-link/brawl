#pragma force_active on
#pragma opt_propagation off

#include <mt/mt_vector.h>
#include <so/stageobject.h>
#include <so/so_module_accesser.h>

class Class_6700 {
public:
    virtual void fn_119_58E4();
    virtual void fn_119_11708();
    virtual void fn_119_13614();
    virtual void fn_119_1360C();
    virtual void fn_119_13604();
    virtual void fn_119_135FC();
    virtual void fn_119_135F4();
    virtual void fn_119_135EC();
    virtual void fn_119_135E4();
    virtual void fn_119_135DC();
    virtual void fn_119_135D4();
    virtual void fn_119_135CC();
    virtual void fn_119_135C4();
    virtual void fn_119_135BC();
    virtual void fn_119_1356C();
    virtual void fn_119_135B4();
    virtual void fn_119_135A4();
    virtual void fn_119_13594();
    virtual void fn_119_13584();
    virtual void fn_119_13574();
};

struct IkeTeam {
    virtual void unused0();
    virtual void unused1();
    virtual int getTeam();
};

struct IkeTeamModule {
    virtual void unused0();
    virtual void unused1();
    virtual IkeTeam* getTeam();
};

extern "C" char lbl_119_data_8[];

extern "C" void fn_119_12BD8(
    StageObject*, unsigned int, unsigned int, int,
    Vec3f*, float, int, bool, int);

extern "C" bool fn_119_77FC(
    StageObject* object, soModuleAccesser* accesser)
{
    soWorkManageModule* work =
        accesser->m_enumerationStart->m_workManageModule;
    soSituationModule* situation =
        accesser->m_enumerationStart->m_situationModule;
    soPostureModule* posture =
        accesser->m_enumerationStart->m_postureModule;
    const char* nodeName = lbl_119_data_8;
    soModelModule* model =
        accesser->m_enumerationStart->m_modelModule;

    Vec3f position = model->getNodeGlobalPosition(
        model->getNodeId(nodeName), false);

    IkeTeamModule* team =
        (IkeTeamModule*)accesser->m_enumerationStart->m_teamModule;
    soResourceModule* resource =
        accesser->m_enumerationStart->m_resourceModule;
    unsigned int task = accesser->m_stageObject->m_taskId;

    fn_119_12BD8(
        object, task,
        resource->getResourceIdAccesser()->getMdlResId(),
        team->getTeam()->getTeam(),
        &position, posture->getLr(),
        situation->getKind(), work->isFlag(0x1200003d), 0);

    accesser->m_enumerationStart->m_workManageModule->offFlag(0x1200003d);
    return true;
}
