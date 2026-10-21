#pragma force_active on
extern "C" {
extern int lbl_8042B990[];

int fn_8004F294(unsigned int index) {
    return lbl_8042B990[index];
}
}
