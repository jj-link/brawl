#pragma force_active on

extern "C" void* getTask__6gfTaskFi(int id);
extern "C" void* __dynamic_cast(void* src, long off, const void* dst, const void* srcType, int hint);
extern "C" int getTeamNo__23soExternalValueAccesserFP11StageObject(void* self);
extern char __RTTI__6gfTask[];
extern const char lbl_27_data_248[];
extern "C" int fn_27_8CB9C();

class soNullable {
public:
    virtual void isNull();  // offset 0x8: isNull__10soNullableCFv
    virtual void fn_27_B5324();  // offset 0xc
    virtual int fn_27_B5874();  // offset 0x10
    virtual void fn_27_B5454(int team, int flag);  // offset 0x14
    virtual int fn_27_B587C();  // offset 0x18
    virtual void fn_27_B62C0();  // offset 0x1c
    virtual void fn_27_B56E0(int team);  // offset 0x20
    char pad[0x2C];
    int unk30;
};

extern "C" void fn_27_B5748(soNullable* self, int id) {
    if ((unsigned int)(id + 0x10000) != 0xFFFF) {
        void* task = getTask__6gfTaskFi(id);
        if (task != 0) {
            void* obj = __dynamic_cast(task, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 0);
            if (obj != 0) {
                self->unk30 = fn_27_8CB9C();
                int a = self->fn_27_B5874();
                int b = ((soNullable*)a)->fn_27_B5874();
                int team = getTeamNo__23soExternalValueAccesserFP11StageObject(obj);
                self->fn_27_B5454(team, 1);
                int c = self->fn_27_B587C();
                int d = ((soNullable*)c)->fn_27_B5874();
                if (b == d) {
                    self->fn_27_B56E0(team);
                }
            }
        } else {
            self->unk30 = id;
        }
    } else {
        self->unk30 = id;
    }
}
