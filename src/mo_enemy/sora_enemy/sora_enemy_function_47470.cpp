#pragma force_active on
struct Vec3 { float x,y,z; };
extern "C" {
extern float lbl_41_rodata_1018;
extern unsigned char lbl_41_bss_504[];
Vec3* fn_41_5AC4(Vec3*, float, float, float);
void fn_41_534C(Vec3*, const Vec3*);
}
class Model {
public:
    char pad[8];
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
    virtual void slot36();
    virtual Vec3 position(unsigned int, Vec3*, int, bool);
};
class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3 slot4();
};
struct Modules { char pad[4]; Model* model; char pad2[4]; soAnimCmdEventObserver* posture; };
struct Object { char pad[0xd8]; Modules* modules; };
struct Input { char pad[8]; int mode; char pad2[0x54]; float x, y; };
extern "C" void fn_41_47470(Vec3* out, Input* input, Object* obj) {
    Vec3 v;
    fn_41_5AC4(&v, input->x, input->y, lbl_41_rodata_1018);
    if (input->mode != 2) {
        unsigned int id = *(unsigned int*)(lbl_41_bss_504 + 8);
        if (id != 0xffffffff) {
            fn_41_534C(out, &obj->modules->model->position(id, &v, 0, 0));
        }
    } else {
        fn_41_534C(out, &obj->modules->posture->slot4());
    }
}