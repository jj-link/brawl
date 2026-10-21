#pragma force_active on
extern int fn_80204A70(int a, int b, int c);

int fn_80204E48(int* p, int b) {
    return fn_80204A70(p[1], b, p[2]);
}
