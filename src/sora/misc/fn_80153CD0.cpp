#pragma force_active on
extern "C" long long fn_80153CD0(int **arg)
{
    int *p = *arg;
    if (p == 0) {
        return 0;
    }
    return *(long long *)p;
}
