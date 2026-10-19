#pragma force_active on
extern "C" void fn_94_B1E0(void*, void*, void*);

extern "C" unsigned int* fn_94_B18C(unsigned int* arg0, void* arg1) {
    unsigned int buf[4];
    fn_94_B1E0(buf, arg0, arg1);
    arg0[1] = buf[0];
    arg0[2] = buf[1];
    arg0[3] = buf[2];
    return arg0 + 1;
}
