#pragma force_active on
struct Unit;
struct Unk;

extern "C" {
    bool fn_41_1AE7C(Unit* p);
    bool fn_41_1C9C4(Unit* p);
    int fn_41_1CA10(Unit* p);

    bool fn_41_1C678(Unit* unit) {
        if (fn_41_1AE7C(unit) == 1) {
            return 0;
        }
        if (fn_41_1C9C4(unit) == 1) {
            return 0;
        }
        return fn_41_1CA10(unit) != 1;
    }
}
