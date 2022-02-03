#include <chrono>

/* Use clock_start(), set start time, and use clock_end(unit) compute duration.
 * Here unit is time unit, listed by TimeUnit.
 * NANOSEC -> ns, MICROSEC -> us, MILLISEC -> ms
 * clock_end(SECOND) will return the value, how many seconds are costed.
 */


enum class TimeUnit {
    NANOSEC,
    MICROSEC,
    MILLISEC,
    SECOND,
};

using accuracy_clock = std::chrono::high_resolution_clock;

#define TIME_FORMAT(unit) std::chrono::duration<int, unit>
#define DURATION_CAST(dura, time_format) std::chrono::duration_cast<time_format>(dura)

struct DClock {
    static accuracy_clock::time_point cursor;

    static void start() {
        cursor = accuracy_clock::now();
    }

    static int end(TimeUnit unit) {
        auto duration = accuracy_clock::now() - DClock::cursor;
        int time_count = -1;
        switch (unit) {
        case TimeUnit::SECOND:
            time_count = DURATION_CAST(duration, std::chrono::seconds).count();
            break;
        case TimeUnit::MILLISEC:
            time_count = DURATION_CAST(duration, std::chrono::milliseconds).count();
            break;
        case TimeUnit::MICROSEC:
            time_count = DURATION_CAST(duration, std::chrono::microseconds).count();
            break;
        case TimeUnit::NANOSEC:
            time_count = DURATION_CAST(duration, std::chrono::nanoseconds).count();
            break;
        default:
            break;
        }
        return time_count;
    }
};
// Definition avoid link no found
accuracy_clock::time_point DClock::cursor;


#define clock_start()   DClock::start()
#define clock_end(unit) DClock::end(TimeUnit::unit)
