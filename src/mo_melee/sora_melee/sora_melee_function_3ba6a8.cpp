#pragma force_active on

typedef unsigned long u32;

struct Vec3f {
    float x, y, z;
};

class Matrix {
public:
    float m[3][4];
    void mulPos(const Vec3f*, Vec3f*);
};

class Obj {
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void getMatrix(u32, Matrix*, u32);
};

struct Holder {
    char pad[4];
    Obj* obj;
};

struct Accesser {
    char pad[0xD8];
    Holder* h;
};

struct Mod {
    char pad[0x60];
    Accesser* acc;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, u32, u32);

extern "C" void fn_27_3BA6A8(Vec3f* out, Mod* object) {
    Matrix matrix;
    object->acc->h->obj->getMatrix(4, &matrix, 0);

    float z = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        object->acc, 0xFA2, 0);
    float y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        object->acc, 0xFA1, 0);
    out->x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        object->acc, 0xFA0, 0);
    out->y = y;
    out->z = z;
    matrix.mulPos(out, out);
}
