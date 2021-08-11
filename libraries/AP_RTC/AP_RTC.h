#pragma once

#include <AP_Param/AP_Param.h>

#include <stdint.h>

#define PTP_SYNC 0x00
#define PTP_FOLLOW_UP 0x08
#define PTP_DELAY_REQUEST 0x01
#define PTP_DELAY_RESPONSE 0x09
#define TAKEOFF_TIME 0x03
#define PTP_DEFAULT_STATE 255

 struct time_spec {
	        long	sec;		/* seconds */
        	long	nsec;	/* and nanoseconds */
    };

class AP_RTC {

public:

    AP_RTC();

    static const struct AP_Param::GroupInfo var_info[];

    AP_Int8 allowed_types;
    AP_Int16 tz_min;

    // ordering is important in source_type; lower-numbered is
    // considered a better time source.  These values are documented
    // and used in the parameters!
    enum source_type : uint8_t {
        SOURCE_GPS = 0,
        SOURCE_MAVLINK_SYSTEM_TIME= 1,
        SOURCE_HW = 2,
        SOURCE_NONE,
    };  

    /*
      get clock in UTC microseconds.  Returns false if it is not available.
     */
    bool get_utc_usec(uint64_t &usec) const;

    // set the system time.  If the time has already been set by
    // something better (according to source_type), this set will be
    // ignored.
    void set_utc_usec(uint64_t time_utc_usec, source_type type);

    /*
      get time in UTC hours, minutes, seconds and milliseconds
     */
    bool get_system_clock_utc(uint8_t &hour, uint8_t &min, uint8_t &sec, uint16_t &ms);
    
    bool get_local_time(uint8_t &hour, uint8_t &min, uint8_t &sec, uint16_t &ms);

    uint32_t get_time_utc(int32_t hour, int32_t min, int32_t sec, int32_t ms);

    void time_add(struct time_spec *output, const struct time_spec *left, const struct time_spec *right);
    void time_sub(struct time_spec *output, const struct time_spec *left, const struct time_spec *right);

    // get singleton instance
    static AP_RTC *get_singleton() {
        return _singleton;
    }
    uint32_t takeoff_start_time = 0;
private:
    static AP_RTC *_singleton;

    source_type rtc_source_type = SOURCE_NONE;
    int64_t rtc_shift;

};

namespace AP {
    AP_RTC &rtc();
};
