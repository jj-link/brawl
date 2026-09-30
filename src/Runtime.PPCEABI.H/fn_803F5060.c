// Branchless signed integer magnitude helper.
int fn_803F5060(int value) {
    int sign = value >> 31;
    return (sign ^ value) - sign;
}
