#pragma force_active on
int PFAPI_convertReturnValue(int value) {
    return (-value | value) >> 31;
}
