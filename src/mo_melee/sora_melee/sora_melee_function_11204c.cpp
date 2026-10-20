#pragma force_active on
class Fighter {
public:
    enum ScalingKind { SCALING_KIND_NONE = 0 };
    enum ScalingType { SCALING_TYPE_NONE = 0 };
};

struct ftOwnerScalingData {
    unsigned char pad[0x10];
    int kind;
    int type;
};

class ftOwner {
public:
    ftOwnerScalingData* m_scaling;
    void setInfiniteScaling(Fighter::ScalingKind kind, Fighter::ScalingType type);
};

void ftOwner::setInfiniteScaling(Fighter::ScalingKind kind, Fighter::ScalingType type) {
    m_scaling->kind = kind;
    m_scaling->type = type;
}
