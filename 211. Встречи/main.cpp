#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

class Appointment
{
private:
    int m_startTimePoint;
    int m_endTimePoint;
    std::vector<std::string> m_names;

public:
    explicit Appointment() = default;
    explicit Appointment(Appointment const &) = default;
    explicit Appointment(Appointment &&) noexcept = default;
    Appointment &operator=(Appointment const &) = default;
    Appointment &operator=(Appointment &&) noexcept = default;
    virtual ~Appointment() = default;

    std::vector<std::string> getNames() const { return m_names; }

    explicit Appointment(int day, int hours, int minutes, int duration, std::vector<std::string> const &names)
    {
        m_startTimePoint = (day - 1) * 24 * 60 + hours * 60 + minutes;
        m_endTimePoint = m_startTimePoint + duration;
        m_names = names;
    }

    bool isBooked(Appointment const &app) const
    {
        return ((app.m_startTimePoint > m_startTimePoint && app.m_startTimePoint < m_endTimePoint) ||
                (app.m_endTimePoint > m_startTimePoint && app.m_endTimePoint < m_endTimePoint))
                   ? true
                   : false;
    }

    constexpr int getDay() const { return static_cast<int>(floor((static_cast<double>(m_startTimePoint) / 60) / 24) + 1); }

    constexpr int getHour() const { return static_cast<int>((floor(static_cast<double>(m_startTimePoint - (getDay() - 1) * 24 * 60)) / 60)); }

    constexpr int getMinutes() const { return m_startTimePoint - (getDay() - 1) * 24 * 60 - getHour() * 60; }

    constexpr int getDuration() const { return m_endTimePoint - m_startTimePoint; }
};

void appointmentHandler(std::vector<std::vector<std::string>> const &userInput)
{
    std::vector<Appointment> apps;
    bool flag{};
    for (size_t i{}; i < userInput.size(); i++)
    {
        if (userInput.at(i).at(0ul) == "APPOINT")
        {
            std::vector<std::string> namesVec(userInput.at(i).cbegin() + 5, userInput.at(i).cend());
            Appointment app(std::stoi(userInput.at(i).at(1ul)),
                            std::stoi(userInput.at(i).at(2ul).substr(0ul, userInput.at(i).at(2ul).find(':'))),
                            std::stoi(userInput.at(i).at(2ul).substr(userInput.at(i).at(2ul).find(':') + 1ul)),
                            std::stoi(userInput.at(i).at(3ul)), namesVec);
            if (apps.size() == 0ul)
            {
                apps.emplace_back(app);
                std::cout << "OK\n";
                continue;
            }
            else
            {
                for (size_t k{}; k < apps.size(); k++)
                {
                    // If is booked -> mark it
                    if (apps.at(k).isBooked(app))
                        flag = true;
                    break;
                }
                // If appointment is already booked -> outputting "FAIL"
                if (flag == true)
                {
                    std::cout << "FAIL\n";
                    for (auto const &name : app.getNames())
                        std::cout << name << ' ';
                    std::endl(std::cout);
                }
                else
                {
                    apps.push_back(app);
                    std::cout << "OK\n";
                }
            }
        }
        else if (userInput.at(i).at(0ul) == "PRINT")
        {
            for (size_t k{}; k < apps.size(); k++)
            {
                if (apps.at(k).getDay() == std::stoi(userInput.at(i).at(1ul)) &&
                    (std::find(apps.at(k).getNames().cbegin(), apps.at(k).getNames().cend(),
                               userInput.at(i).at(2ul)) != apps.at(k).getNames().cend()))
                {

                    std::cout << (apps.at(k).getHour() > 10
                                      ? std::to_string(apps.at(k).getHour())
                                      : "0" + std::to_string(apps.at(k).getHour()))
                              << ":"
                              << (apps.at(k).getMinutes() > 10
                                      ? std::to_string(apps.at(k).getMinutes())
                                      : "0" + std::to_string(apps.at(k).getMinutes()))
                              << ' ' << apps.at(k).getDuration() << ' ';

                    for (auto const &name : apps.at(k).getNames())
                        std::cout << name << ' ';
                    std::endl(std::cout);
                }
            }
        }
    }
}

int main()
{
    // Count of requests
    ushort n{};
    std::cin >> n;

    std::vector<std::vector<std::string>> input(n, std::vector<std::string>(5ul));
    for (ushort i{}; i < n; i++)
        for (ushort j{}; j < 5u; j++)
            std::cin >> input.at(i).at(j);

    appointmentHandler(input);

    return EXIT_SUCCESS;
}
