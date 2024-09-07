#include <iostream>
#include <string>
#include <sstream>

enum status {
    ALL_POWER,
    SOCKETS,
    LIGHT_HOME,
    LIGHT_STREET,
    HEATING_HOME,
    HEATING_STREET,
    CONDOTIONER,
    ACTIVITY
};

int main() {
    int tempStreet = 0;
    int tempHome = 0;
    int statusHeatingStreet = 0;
    int statusHeatingHome = 0;
    int statusConditioner = 0;
    int statusLightStreet = 0;
    int statusLightHome = 0;
    int time = 0;
    int day = 1;
    std::string action;
    std::string lightHome;

    for (int i = 0; i < 48; i++) {

        std::stringstream str;
        std::string info;

        if (time == 24) {
            day++;
            std::cout << day << " day\n";
            time = 0;
        }

        std::cout << "Inpiting tempirature street\n";
        std::cout << "Inpiting tempirature home\n";
        std::cout << "Activity street? (Yes/No)\n";
        std::cout << "Light home? (Yes/No)\n";
        std::getline(std::cin, info);

        str << info;
        str >> tempStreet >> tempHome >> action >> lightHome;

        time++;
        int light = 2700;

        std::cout << "Time: " << time << ":00\n\n";

        if (time == 24 || time < 16) {
            light = 5000;
        }

        if (time >= 16 && time <= 20) {
            light = 5000 - (575 * (time - 16));
        }

        if ((tempStreet < 0 ) && !(statusHeatingStreet & HEATING_STREET)) {
            statusHeatingStreet |= HEATING_STREET;
            std::cout << "Heating street on\n";
        }

        else if ((tempStreet > 5) && (statusHeatingStreet & HEATING_STREET)) {
            statusHeatingStreet &= ~HEATING_STREET;
            std::cout << "Heating street off\n";
        }

        if ((tempHome < 22) && !(statusHeatingHome & HEATING_HOME)) {
            statusHeatingHome |= HEATING_HOME;
            std::cout << "Heatinh home on\n";
        }
        else if ((tempHome >= 25) && (statusHeatingHome & HEATING_HOME)) {
            statusHeatingHome &= ~HEATING_HOME;
            std::cout << "Heatinh home off\n";
        }

        if ((tempHome >= 30) && !(statusConditioner & CONDOTIONER)){
            statusConditioner |= CONDOTIONER;
            std::cout << "Conditioner home on\n";
        }
        else if ((tempHome <= 25) && (statusConditioner & CONDOTIONER)) {
            statusConditioner &= ~CONDOTIONER;
            std::cout << "Conditioner home off\n";
        }

        if ((time >= 16 || time <= 5) && (action == "Yes" || action == "yes") && !(statusLightStreet & LIGHT_STREET)) {
            statusLightStreet |= LIGHT_STREET;
            std::cout << "Light street on\n";
        }
        else if ((time < 16 || time > 5) && (action == "No" || action == "no") && (statusLightStreet & LIGHT_STREET)){
            statusLightStreet &= ~LIGHT_STREET;
            std::cout << "Light street off\n";
        }

        if ((lightHome == "Yes" || lightHome == "yes") && (time < 16 || time == 0) && !(statusLightHome & LIGHT_HOME)) {
            statusLightHome |= LIGHT_HOME;
            std::cout << "Light home on " << light << "\n";
        }

        else if ((lightHome == "No" || lightHome == "no") && (statusLightHome & LIGHT_HOME)) {
            statusLightHome &= ~LIGHT_HOME;
            std::cout << "Light home off\n";
        }

        if (time >= 16 && (lightHome == "Yes" || lightHome == "yes") && !(statusLightHome & LIGHT_HOME)) {
            statusLightHome |= LIGHT_HOME;
            std::cout << "Light home on " << light << " \n";
        }
        std::cout << "\n\n";
    }
}