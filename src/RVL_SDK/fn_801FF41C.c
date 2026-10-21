#pragma force_active on
extern unsigned int lbl_804E4850[32];

void fn_801FF41C(unsigned int* node) {
    node[0] = lbl_804E4850[0];
    lbl_804E4850[0] = (unsigned int)node;
    node[3] = 0;
}
