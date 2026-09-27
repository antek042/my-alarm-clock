#include <inc/alarm.hpp>

Alarm::Alarm(int pin_number = 7) {
        pinMode(pin_number, OUTPUT);
        stop();
}

void Alarm::set_time_to_ring(tm new_time_to_ring) {
        time_to_ring = new_time_to_ring;
}

void Alarm::ring() {
        digitalWrite(pin_number, HIGH);
}

void Alarm::stop() {
        digitalWrite(pin_number, LOW);
}
