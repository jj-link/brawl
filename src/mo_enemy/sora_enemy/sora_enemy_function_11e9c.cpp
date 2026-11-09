#pragma force_active on

extern float lbl_41_rodata_BE0;

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, unsigned int id, unsigned int index);

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void* slot1(int index);
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void* slot11(int index);
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(unsigned int id);
};

extern "C" int fn_41_11E9C(char* self, unsigned char* arg1) {
    char* a = *(char**)(*(char**)(*(char**)(self + 0x3C) + 0xD8) + 0x64);
    if ((unsigned int)((Object_vptr_0*)a)->slot17(0x1200000F) == 1U) {
        return 1;
    }
    *arg1 = 0;
    for (int i = 0; i < ((Object_vptr_0*)*(char**)(self + 0x40))->slot3(); i++) {
        char* e = (char*)((Object_vptr_0*)*(char**)(self + 0x40))->slot1(i);
        if (*(float*)(e + 0xC) >= lbl_41_rodata_BE0) {
            if ((*(unsigned int*)(e + 0x6C) & 0x1F) == 7) {
                return 1;
            }
            if ((unsigned char)e[0x9C] == 1U) {
                *arg1 = 1;
                return 1;
            }
            if (*(unsigned int*)(((char*)((Object_vptr_0*)(*(char**)(*(char**)(*(char**)(self + 0x3C) + 0xD8) + 0x54)))->slot11(0)) + 0x28) != *(unsigned int*)(e + 0x1C)) {
                if (*(float*)(e + 0x4) >= (getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(*(void**)(self + 0x3C), 0x7F1, 0))) {
                    return 1;
                }
            } else if (!((*(unsigned int*)(e + 0x74) >> 9) & 1)) {
                *arg1 = 1;
                return 1;
            }
        }
    }
    return 0;
}
