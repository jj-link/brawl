#pragma force_active on

struct Team {
    virtual void slot08();
    virtual void slot0C();
    virtual int getTeamNo();
};

struct TeamModule {
    virtual void slot08();
    virtual void slot0C();
    virtual Team* getTeam();
};

struct ModuleAccessor {
    char padding[0x18];
    TeamModule* teamModule;
};

struct StageModule {
    char padding[0xD8];
    ModuleAccessor* accessor;
};

struct StageObject {
    char padding[0x60];
    StageModule* module;

    StageModule* getModule() { return module; }
};

extern "C" int getTeamNo__23soExternalValueAccesserFP11StageObject(
    StageObject* __restrict object
) {
    return object->getModule()->accessor->teamModule->getTeam()->getTeamNo();
}
