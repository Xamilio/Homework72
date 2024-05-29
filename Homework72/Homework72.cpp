#include <iostream>
#include <string>
using namespace std;


class WaterSupply {
public:
    void on()
    {
        cout << "Подача воды включена" << endl;
    }
    void off() 
    {
        cout << "Подача воды выключена" << endl;
    }
};
class WashingMachineMotor {
public:
    void start() 
    {
        cout << "Двигатель стиральной машины запущен" << endl;
    }
    void stop() 
    {
        cout << "Двигатель стиральной машины остановлен" << endl;
    }
};
class Heater {
public:
    void heatWater() 
    {
        cout << "Нагрев воды начат." << endl;
    }
};
class Drum {
public:
    void rotate(const string& direction) 
    {
        cout << "Барабан вращается в направлении: " << direction << endl;
    }
};
class WashingMachineFacade {
private:
    WaterSupply waterSupply;
    WashingMachineMotor motor;
    Heater heater;
    Drum drum;

public:
    void startWash() 
    {
        cout << "Начало стирки..." << endl;
        waterSupply.on();
        heater.heatWater();
        motor.start();
        drum.rotate("по часовой стрелке");
    }

    void stopWash() {
        cout << "Остановка стирки..." << endl;
        drum.rotate("против часовой стрелки");
        motor.stop();
        waterSupply.off();
    }
};

int main() {
    WashingMachineFacade washingMachine;
    washingMachine.startWash();
    washingMachine.stopWash();
}