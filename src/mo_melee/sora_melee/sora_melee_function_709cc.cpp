#pragma force_active on
class acCmdInterpreter {
public:
    unsigned int isSleepStackData(long) const;
};

extern "C" unsigned int fn_27_709CC(const acCmdInterpreter* self, long cmd) {
    unsigned int ret;
    if (self->isSleepStackData(cmd) == 1) {
        ret = 1;
    } else {
        ret = 0;
        if (cmd == 8) {
            goto set;
        }
        if (cmd != 9) {
            goto end;
        }
    set:
        ret = 1;
    }
end:
    return ret;
}
