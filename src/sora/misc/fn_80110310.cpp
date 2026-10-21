#pragma force_active on
extern "C" {
extern int lbl_8045D908[4];
int fn_80110190(int*, int*, int*);

int fn_80110310(int* a, int* b) {
    return fn_80110190(a, b, (int*)&lbl_8045D908);
}
}
