#pragma force_active on

extern "C" {
extern const char lbl_41_data_5720[], lbl_41_data_E4[], lbl_41_data_132C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

namespace {
struct SoraEnemyArticleOperationState {
    bool first;
    bool second;
};

class EventObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual int id();
};
}

extern "C" int fn_41_4F258(void*, void*, void* self)
{
    EventObj* obj = reinterpret_cast<EventObj*>(self);
    switch (static_cast<unsigned>(obj->id())) {
    case 0: {
        SoraEnemyArticleOperationState state = {false, false};
        __dynamic_cast(self, 0, lbl_41_data_5720, lbl_41_data_132C, 1);
        return 1;
    }
    case 1: {
        SoraEnemyArticleOperationState state = {false, false};
        __dynamic_cast(self, 0, lbl_41_data_E4, lbl_41_data_132C, 1);
        return 1;
    }
    case 2: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 3: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 4: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 5: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 6: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 7: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 8: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 9: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 10: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 11: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 12: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 13: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 14: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 15: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 16: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    default: return 0;
    }
}
