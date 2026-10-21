#pragma force_active on
extern "C" int fn_80331D00(int* data, int* pos) {
    int offset = *pos;
    *pos = offset + 4;
    return *(int*)((char*)data + offset);
}
