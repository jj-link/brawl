#pragma force_active on
extern void fn_803F8ACC(void *, unsigned int, unsigned int, unsigned int);

void fn_8035AAC0(void *arg0, unsigned int arg1) {
    int *p = (int *)arg0;
    fn_803F8ACC((void *)p[5], (unsigned int)p[0], (unsigned int)p[2], arg1);
}
