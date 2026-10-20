#pragma force_active on
struct ftOwnerData {
    char _[0x68];
    int m_someField;
};

struct ftOwner {
    ftOwnerData* m_data;
};

extern "C" int fn_27_112D00(ftOwner* owner) {
    return owner->m_data->m_someField;
}
