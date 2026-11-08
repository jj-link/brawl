#pragma force_active on
#pragma scheduling off

extern int fn_801E56DC(int chan, unsigned int dev, unsigned int* out);

int fn_801E56B4(int chan) {
    unsigned int id[2];
    return fn_801E56DC(chan, 0, id);
}
