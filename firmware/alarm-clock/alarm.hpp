#include "Arduino.h"
#include "time.h"

class Alarm {
public:
        Alarm(int pin_number_ = 7);
        void set_time_to_ring(tm new_time_to_ring);
        void should_ring(tm time);
private:
        void ring();
        void stop();

        int pin_number;
        tm time_to_ring;
};