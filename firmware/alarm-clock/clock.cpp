#include <clock.hpp>

Clock::Clock() {
        configTzTime(posixTimeZone, ntpServerAddress.c_str());
}

std::optional<tm> Clock::get_current_time() {
        tm curr_time;
        if (!getLocalTime(&curr_time))
                return {};
        
        return curr_time;
}

Clock& Clock::set_ntp_server_address(const std::string& ntpServer_) {
        ntpServerAddress = ntpServer_;
        return *this;
}