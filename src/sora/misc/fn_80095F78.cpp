#pragma force_active on
extern "C" {
bool fn_80095F78(int** arg0) {
    return ((*arg0)[0x3B] & 7) != 0;
}
}
