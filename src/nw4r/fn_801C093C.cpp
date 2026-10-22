#pragma force_active on
extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int level);

struct FnNode {
    FnNode* next;
};

extern "C" void fn_801C093C(FnNode** arg0, unsigned int arg1, unsigned int arg2) {
    FnNode** var_r29;
    unsigned int end;
    FnNode* var_r5;
    int level;

    var_r29 = arg0;
    level = OSDisableInterrupts();
    end = arg1 + arg2;
    var_r5 = *var_r29;
    while (var_r5 != 0) {
        if (arg1 <= (unsigned int)var_r5 && (unsigned int)var_r5 < end) {
            *var_r29 = var_r5->next;
        } else {
            var_r29 = &var_r5->next;
        }
        var_r5 = var_r5->next;
    }
    OSRestoreInterrupts(level);
}
