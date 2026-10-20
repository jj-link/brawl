#pragma force_active on
class soModelModuleImpl {
public:
    bool isObserv(char kind);
};

bool soModelModuleImpl::isObserv(char kind) {
    return kind == 3;
}
