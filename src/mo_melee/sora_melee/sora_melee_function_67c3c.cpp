#pragma force_active on
class soStopModuleImpl {
public:
    bool isObserv(char c);
};

bool soStopModuleImpl::isObserv(char c) {
    return c == 0x1c;
}
