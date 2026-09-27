#include <string>
#include <optional>

class Clock {
        Clock();
        std::optional<tm> get_current_time();

        Clock& set_ntp_server_address(const std::string& ntpServer_);
private:
        std::string ntpServerAddress = "time.nist.gov";
        const char* posixTimeZone = "CET-1CEST,M3.5.0,M10.5.0/3";
};