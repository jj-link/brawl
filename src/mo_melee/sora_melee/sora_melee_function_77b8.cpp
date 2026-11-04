#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserver(int a, int b);
};

template <>
void soEventObserver<soAnimCmdEventObserver>::addObserver(int a, int b) {
}
