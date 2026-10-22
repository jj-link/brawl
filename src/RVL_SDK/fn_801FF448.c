#pragma force_active on
extern unsigned int lbl_804E4850[32];
extern unsigned int lbl_804E48D0[36];

void fn_801FF448(unsigned int* node) {
    unsigned int i = node[3];
    unsigned int a = lbl_804E4850[i];
    unsigned int b = lbl_804E48D0[i];

    if (a == b) {
        lbl_804E48D0[i] = 0;
        lbl_804E4850[i] = 0;
        return;
    }
    if ((unsigned int)node == a) {
        unsigned int p = node[0];
        lbl_804E4850[i] = p;
        *(unsigned int*)(p + 4) = 0;
        return;
    }
    if ((unsigned int)node == b) {
        unsigned int p = node[1];
        lbl_804E48D0[i] = p;
        *(unsigned int*)p = 0;
        return;
    }
    {
        unsigned int p = node[1];
        unsigned int q = node[0];
        *(unsigned int*)p = q;
        *(unsigned int*)(q + 4) = p;
    }
}
