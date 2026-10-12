struct LuigiSubKindPrefix {
    unsigned char storage[0xB8];
    int subKind;
};

extern "C" int fn_99_10828(const LuigiSubKindPrefix* fighter) {
    return fighter->subKind;
}
