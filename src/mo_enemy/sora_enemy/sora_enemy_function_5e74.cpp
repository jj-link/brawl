#include <mt/mt_vector.h>

#pragma force_active on

extern "C" {
void* fn_41_5E20();
unsigned int fn_27_5BEA8(void*);
int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned int, unsigned int);
int checkDeadArea__12soGroundUtilFP5Vec3fff(void*, float, float);
void fn_41_2B31C(void*, int, int);
void fn_41_2B328(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const float lbl_41_rodata_18;
extern const char lbl_41_data_7F0[];
extern const char lbl_41_data_93C[];
}

struct ModelBase {
    char pad[8];
};

class Model : public ModelBase {
public:
    virtual void slot0();
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
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual Vec3f slot36(int, bool);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, unsigned int);
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
    virtual void slot16();
    virtual unsigned int slot17(unsigned int);
    virtual void slot18(unsigned int);
    virtual void slot19();
    virtual void slot20();
    virtual void slot21(void*);
};

struct Mods {
    char pad0[4];
    Model* m4;
    char pad8[0x64 - 0x8];
    Object_vptr_0* m64;
    char pad68[0x70 - 0x68];
    void* m70;
};

struct Self {
    char pad[0x1b4];
    Mods* mods;
};

extern "C" void fn_41_5E74(Self* self) {
    if (fn_27_5BEA8(fn_41_5E20()) == 1U) {
        Model* model = self->mods->m4;
        Vec3f position = model->slot36(
            getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
                (char*)self + 0xdc, 0x59e6, 0),
            false);
        int result = checkDeadArea__12soGroundUtilFP5Vec3fff(
            &position, lbl_41_rodata_18, lbl_41_rodata_18);

        if (result != -1) {
            Object_vptr_0* object = self->mods->m64;
            if (object->slot17(0x12000004) == 1U) {
                object = self->mods->m64;
                if (object->slot17(0x12000002) == 0) {
                    object = self->mods->m64;
                    object->slot18(0x22000008);
                    object = self->mods->m64;
                    object->slot18(0x12000002);
                    object = self->mods->m64;
                    object->slot5(result, 0x1000000E);

                    Object_vptr_0* target = (Object_vptr_0*)__dynamic_cast(
                        self->mods->m70, 0, lbl_41_data_7F0, lbl_41_data_93C, 1);
                    fn_41_2B31C(target, -0x15E, -0xFA);
                    target->slot21(&self->pad[0xdc]);
                    fn_41_2B328(target);
                }
            }
        }
    }
}
