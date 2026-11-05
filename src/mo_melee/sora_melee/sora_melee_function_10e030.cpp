#include <so/event/so_event_presenter.h>
#pragma force_active on

class ftOutsideEventObserver;

template <>
class soEventObserver<ftOutsideEventObserver> {
public:
    void addObserver(short, signed char);
};

void soEventObserver<ftOutsideEventObserver>::addObserver(short, signed char) {}
