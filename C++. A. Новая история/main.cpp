#include <iostream>

// Days in a month
static constexpr int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Seconds in a day
static constexpr int seconds_per_day = 86400;

/**
 * @brief Calculates days in a specified year
 * @param year year to calculate count of a days
 * @return Count of a days in a year
 */
unsigned getDaysFromYear(short year)
{
    unsigned days{};
    for (int i = 1; i < year; i++)
        days += 365;
    return days;
}

/**
 * @brief Calculates days in a specified month
 * @param month month to calculate count of a days
 * @return Count of a days in a month
 */
unsigned getDaysFromMonth(short month)
{
    unsigned days{};
    for (int i = 0; i < month - 1; ++i)
        days += days_in_month[i];
    return days;
}

/**
 * @brief Calculates count of a days in specified date (combines another fcns)
 * @param year year
 * @param month month
 * @param day day
 * @return Count of a days in a specified date
 */
unsigned getDaysFromDate(short year, short month, short day) { return day + getDaysFromMonth(month) + getDaysFromYear(year); }

/**
 * @brief Calculates count of a seconds in specified time point
 * @param hours hours
 * @param minutes minutes
 * @param seconds seconds
 * @return Count of a seconds in a specified time point
 */
unsigned getSecondsFromTime(short hours, short minutes, short seconds) { return hours * 3600 + minutes * 60 + seconds; }

int main()
{
    // Date of the beginning
    short year_1{}, month_1{}, day_1{}, hour_1{}, min_1{}, sec_1{};
    std::cin >> year_1 >> month_1 >> day_1 >> hour_1 >> min_1 >> sec_1;

    // Date of the ending
    short year_2{}, month_2{}, day_2{}, hour_2{}, min_2{}, sec_2{};
    std::cin >> year_2 >> month_2 >> day_2 >> hour_2 >> min_2 >> sec_2;

    // Calculating count of a days in a both of dates
    unsigned days_1{getDaysFromDate(year_1, month_1, day_1)},
        days_2{getDaysFromDate(year_2, month_2, day_2)};

    // Calculating seconds in a both of time points
    unsigned seconds_1{getSecondsFromTime(hour_1, min_1, sec_1)},
        seconds_2{getSecondsFromTime(hour_2, min_2, sec_2)};

    // Calculating the difference in days and seconds
    int total_days = days_2 - days_1,
        total_secs = seconds_2 - seconds_1;

    // If we get negative seconds
    if (total_secs < 0)
    {
        // Adding one more seconds in a day and decrementing count of days
        total_secs += seconds_per_day;
        total_days--;
    }

    std::cout << total_days << ' ' << total_secs << '\n';

    return EXIT_SUCCESS;
}
