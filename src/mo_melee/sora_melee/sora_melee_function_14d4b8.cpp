#pragma force_active on
class Fighter;
class StageObject;
class soModuleAccesser;

class soExternalValueAccesser {
public:
    static soModuleAccesser* getModuleAccesser(StageObject* obj);
};

class soValueAccesser {
public:
    static float getConstantFloat(soModuleAccesser* accesser, unsigned long a, unsigned long b);
};

class ftExternalValueAccesser {
public:
    static float getWeight(Fighter* fighter);
};

float ftExternalValueAccesser::getWeight(Fighter* fighter) {
    soModuleAccesser* accesser = soExternalValueAccesser::getModuleAccesser((StageObject*)fighter);
    return soValueAccesser::getConstantFloat(accesser, 0xbe1, 0);
}
