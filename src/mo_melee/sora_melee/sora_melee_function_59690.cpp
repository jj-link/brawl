#pragma force_active on
class soControllerModuleImpl {
public:
    bool isObserv(char c);
};

bool soControllerModuleImpl::isObserv(char c) {
    return c == 7;
}
