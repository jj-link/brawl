#pragma force_active on
struct V2 { float x, y; };
struct Words { int x, y; };
union Pair { Words bits; V2 vec; };

struct Module {
    int pad[2];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual int has(int);
    virtual Words get(int, int);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Words slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
};

struct Data { int type; float kind; char pad[28]; float angle; };

extern "C" {
extern float lbl_41_rodata_C38[];
float fn_41_10830(V2*);
float fn_41_108AC(V2*, V2*);
Words fn_27_899AC(V2*, V2*);
void fn_41_1592C(V2*, Words*);
Data* fn_41_15964(void*, int);
float fn_41_15A00(float, V2*);
Object_vptr_0* fn_41_15FD4(void*, int);
void fn_41_1627C(void*, int, int, Data*, bool, bool, float, int, float, float);
int fn_41_1794C(void*, int);
void fn_41_17C30(void*, int);
bool fn_41_1AE7C(Object_vptr_0*);
bool fn_41_1C678(Object_vptr_0*);
unsigned int fn_41_1C6E4(Object_vptr_0*, void*, V2*);
void fn_41_1C7D8(Object_vptr_0*, V2*, float);
void fn_41_1CC18(Object_vptr_0*);

void fn_41_172BC(char* self, int id, int param, int sel, int arg4) {
    float* base = lbl_41_rodata_C38;
    Module* mod = *(Module**)(*(char**)(*(char**)(self + 0x20) + 0xD8) + 0x10);
    Pair input;
    V2 sum;
    V2 out;

    if (!mod->has(0))
        return;

    Words initial = mod->get(255, 0);
    input.bits = initial;

    if (base[1] == fn_41_10830(&input.vec))
        return;

    sum.x = base[1];
    sum.y = base[1];
    out.x = base[1];
    out.y = base[1];

    if (sel == -1) {
        for (int i = 0; i < 8; ++i) {
            Object_vptr_0* unit = fn_41_15FD4(self, i);
            if (fn_41_1AE7C(unit) != 1 && fn_41_1C678(unit)) {
                unsigned int flag = fn_41_1C6E4(unit, *(void**)(self + 0x20), &input.vec);
                Words value = unit->slot2();
                fn_41_1592C(&sum, &value);
                if (flag == 1)
                    fn_41_1CC18(unit);
            }
        }
    } else {
        Object_vptr_0* unit = fn_41_15FD4(self, sel);
        if (fn_41_1AE7C(unit) == 0 && fn_41_1C678(unit) == 1) {
            unsigned int flag = fn_41_1C6E4(unit, *(void**)(self + 0x20), &input.vec);
            Words value = unit->slot2();
            fn_41_1592C(&sum, &value);
            if (flag == 1)
                fn_41_1CC18(unit);
        }
    }

    if (base[1] == fn_41_10830(&sum))
        return;
    if (fn_41_108AC(&sum, &input.vec) >= base[1])
        return;
    if (!fn_41_1794C(self, id))
        return;

    Data* data = fn_41_15964(self, param);
    if ((data->type == 0 || data->type == 8 || data->type == 9 || data->type == 10 || data->type == 11 || data->type == 12 || data->type == 13) &&
        (base[13] == data->kind || base[14] == data->kind || base[15] == data->kind)) {
        Words result = fn_27_899AC(&sum, &input.vec);
        out.x = *(float*)&result.x;
        out.y = *(float*)&result.y;
        float angle = data->angle;
        if (base[14] == angle) {
            Object_vptr_0* module = *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x20) + 0xD8) + 0xC);
            float value = module->slot9();
            V2 copy = out;
            angle = fn_41_15A00(value, &copy);
        }
        fn_41_17C30(self, id);
        fn_41_1C7D8(fn_41_15FD4(self, id), &out, angle);
        fn_41_1627C(self, id, param, data, 0, 0, angle, arg4, base[0], base[1]);
    }
}
}
