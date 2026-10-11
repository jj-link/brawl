struct LuigiTeamImpl {
    const void* vtable;
    unsigned char baseStorage[4];
    void* owner;
    int team;
};

extern "C" {
extern const unsigned char lbl_99_data_6CB4[];
void* fn_99_60A0(void*, unsigned char);
}

extern "C" LuigiTeamImpl* fn_99_1033C(LuigiTeamImpl* object, void* owner) {
    fn_99_60A0(object, 0);
    object->vtable = lbl_99_data_6CB4;
    object->owner = owner;
    object->team = -1;
    return object;
}
