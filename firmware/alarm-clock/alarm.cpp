#include <alarm.hpp>

Alarm::Alarm(int pin_number_) {
        pin_number = pin_number_;
        pinMode(pin_number, OUTPUT);
        stop();
}

void Alarm::set_time_to_ring(tm new_time_to_ring) {
        time_to_ring = new_time_to_ring;
}

void Alarm::should_ring(tm time) {
        if (time.tm_hour == time_to_ring.tm_hour &&
            time.tm_min == time_to_ring.tm_min)
    {
                ring();
    }
}

void Alarm::ring() {
        digitalWrite(pin_number, HIGH);
}

void Alarm::stop() {
        digitalWrite(pin_number, LOW);
}
