#include <mu/mu_object.h>
#pragma force_active on

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC();
    virtual void fn_801B3050();
    virtual void fn_801B3248(void*);
};
struct Self {
    char pad[4];
    MuObject* first;
    MuObject* second;
    char pad2[0xc];
    void* item1;
    void* item2;
};
extern "C" {
extern Class_8042B6D0* lbl_805A0334;
extern const float lbl_805A2820;
void fn_80109540(Self* self, int flag) {
    void* item;
    if (flag == 0) item = self->item1;
    else item = self->item2;
    lbl_805A0334->fn_801B3248(item);
    MuObject* obj;
    if (flag == 0) obj = self->first;
    else obj = self->second;
    obj->setFrameNode(lbl_805A2820);
    obj->m_modelAnim->m_anmObjChrRes->SetUpdateRate(lbl_805A2820);
    obj->setFrameMatCol(lbl_805A2820);
    obj->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(lbl_805A2820);
}
}