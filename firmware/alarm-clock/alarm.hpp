#include "time.h"

class Alarm {
public:
        Alarm(int pin_number = 7);
        void set_time_to_ring(tm new_time_to_ring);
private:
        void ring();
        void stop();

        tm time_to_ring;
};