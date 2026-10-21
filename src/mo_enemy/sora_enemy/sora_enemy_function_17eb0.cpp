#pragma force_active on

struct V2 {
    float x, y;
};

struct Words {
    int x, y;
};

struct Unit {
    virtual void v0();
    virtual void v1();
    virtual Words get();
};

extern "C" {
extern float lbl_41_rodata_C3C;

Unit* fn_41_15FD4(void*, int);
bool fn_41_1AE7C(Unit*);
bool fn_41_1F0C0(Unit*, int);
void fn_41_1592C(V2*, Words*);

V2 fn_41_17EB0(void* self, int id) {
    V2 sum = {lbl_41_rodata_C3C, lbl_41_rodata_C3C};

    if (id == -1) {
        for (int i = 0; i < 8; ++i) {
            Unit* unit = fn_41_15FD4(self, i);
            if (fn_41_1AE7C(unit) != 1 && fn_41_1F0C0(unit, 0)) {
                Words value = unit->get();
                fn_41_1592C(&sum, &value);
            }
        }
    } else {
        Unit* unit = fn_41_15FD4(self, id);
        if (!fn_41_1F0C0(unit, 0))
            return sum;

        Words value = unit->get();
        fn_41_1592C(&sum, &value);
    }

    return sum;
}
}
